/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_julia.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abadraja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 15:54:45 by abadraja          #+#    #+#             */
/*   Updated: 2017/05/16 17:59:19 by abadraja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fractol.h"

void		draw_julia_ph2(t_fractol *f)
{
	f->julia.newre = 1.5 * (f->julia.x - WIDTH / 2) /
		(0.5 * f->julia.zoom * WIDTH) + f->julia.move_x;
	f->julia.newim = (f->julia.y - HIGH / 2) /
		(0.5 * f->julia.zoom * HIGH) + f->julia.move_y;
	f->julia.i = 0;
	while (f->julia.i < f->julia.max_i)
	{
		f->julia.oldre = f->julia.newre;
		f->julia.oldim = f->julia.newim;
		f->julia.newre = f->julia.oldre * f->julia.oldre -
			f->julia.oldim * f->julia.oldim + f->julia.c_re;
		f->julia.newim = 2 * f->julia.oldre *
		f->julia.oldim + f->julia.c_im;
		if ((f->julia.newre * f->julia.newre +
					f->julia.newim * f->julia.newim) > 4)
			break ;
		f->julia.i++;
	}
}

void		draw_julia_ph1(t_fractol *f)
{
	f->julia.y = 0;
	while (f->julia.y < HIGH)
	{
		f->julia.x = 0;
		while (f->julia.x < WIDTH)
		{
			draw_julia_ph2(f);
			if (f->julia.i < f->julia.max_i)
				draw_julia(f, 1);
			else
				draw_julia(f, 0);
			f->julia.x++;
		}
		f->julia.y++;
	}
}

void		draw_julia(t_fractol *f, int i)
{
	if (i)
		color_make(f);
	else
		color_to_black(f);
	f->info.x = f->julia.x;
	f->info.y = f->julia.y;
	f->info.i = f->julia.i;
	pixel_put2(f);
}

void		start_julia(t_fractol *f)
{
	f->info.color = (int *)malloc(350 * sizeof(int));
	f->info.mlx = mlx_init();
	f->info.win = mlx_new_window(f->info.mlx, WIDTH, HIGH, JULIA);
	f->info.img = mlx_new_image(f->info.mlx, WIDTH, HIGH);
	f->info.str = mlx_get_data_addr(f->info.img, &f->info.bpp,
			&f->info.sline, &f->info.endian);
	prep_var_julia(f);
	draw_julia_ph1(f);
	expose_hook(f);
	mlx_mouse_hook(f->info.win, ft_julia_mouse_exit, f);
	mlx_key_hook(f->info.win, ft_julia_key_exit, f);
	mlx_hook(f->info.win, MOTION_NOTIFY, PTR_MOTION_MASK,
		ft_mouse_motion, f);
	mlx_loop(f->info.mlx);
}
