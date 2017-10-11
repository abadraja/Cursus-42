/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_mandelbrot2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abadraja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 16:41:39 by abadraja          #+#    #+#             */
/*   Updated: 2017/02/04 16:15:10 by abadraja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fractol.h"

void		draw_mandelbrot_ph2(t_fractol *f)
{
	f->mand.pr = 1.5 * (f->mand.x - WIDTH / 2) /
		(0.5 * f->mand.zoom * WIDTH) + f->mand.move_x;
	f->mand.pi = (f->mand.y - HIGH / 2) /
		(0.5 * f->mand.zoom * HIGH) + f->mand.move_y;
	f->mand.newre = 0;
	f->mand.newim = 0;
	f->mand.oldre = 0;
	f->mand.oldim = 0;
	f->mand.i = 0;
	while (f->mand.i < f->mand.max_i)
	{
		f->mand.oldre = f->mand.newre;
		f->mand.oldim = f->mand.newim;
		f->mand.newre = f->mand.oldre * f->mand.oldre -
			f->mand.oldim * f->mand.oldim + f->mand.pr;
		f->mand.newim = 2 * f->mand.oldre *
			f->mand.oldim + f->mand.pi;
		if ((f->mand.newre * f->mand.newre +
					f->mand.newim * f->mand.newim) > 4)
			break ;
		f->mand.i++;
	}
}

void		draw_mandelbrot_ph1(t_fractol *f)
{
	f->mand.y = 0;
	while (f->mand.y < HIGH)
	{
		f->mand.x = 0;
		while (f->mand.x < WIDTH)
		{
			draw_mandelbrot_ph2(f);
			if (f->mand.i < f->mand.max_i)
				draw_mand(f, 1);
			else
				draw_mand(f, 0);
			f->mand.x++;
		}
		f->mand.y++;
	}
}

void		start_mandelbrot(t_fractol *f)
{
	f->info.color = (int *)malloc(350 * sizeof(int));
	f->info.mlx = mlx_init();
	f->info.win = mlx_new_window(f->info.mlx, WIDTH, HIGH, MANDELBROT);
	f->info.img = mlx_new_image(f->info.mlx, WIDTH, HIGH);
	f->info.str = ft_strnew(1);
	f->info.str = mlx_get_data_addr(f->info.img, &f->info.bpp,
		&f->info.sline, &f->info.endian);
	prep_var_mandelbrot(f);
	draw_mandelbrot_ph1(f);
	expose_hook(f);
	mlx_mouse_hook(f->info.win, ft_mand_mouse_exit, f);
	mlx_key_hook(f->info.win, ft_mand_key_exit, f);
	mlx_loop(f->info.mlx);
}
