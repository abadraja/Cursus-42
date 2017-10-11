/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_ship.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abadraja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/13 15:03:39 by abadraja          #+#    #+#             */
/*   Updated: 2017/02/13 15:03:40 by abadraja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fractol.h"

void		draw_ship_ph2(t_fractol *f)
{
	f->ship.pr = 1.5 * (f->ship.x - WIDTH / 2) /
		(0.5 * f->ship.zoom * WIDTH) + f->ship.move_x;
	f->ship.pi = (f->ship.y - HIGH / 2) /
		(0.5 * f->ship.zoom * HIGH) + f->ship.move_y;
	f->ship.newre = 0;
	f->ship.newim = 0;
	f->ship.oldre = 0;
	f->ship.oldim = 0;
	f->ship.i = 0;
	while (f->ship.i < f->ship.max_i)
	{
		f->ship.oldre = fabs(f->ship.newre);
		f->ship.oldim = fabs(f->ship.newim);
		f->ship.newre = f->ship.oldre * f->ship.oldre -
			f->ship.oldim * f->ship.oldim + f->ship.pr;
		f->ship.newim = 2 * f->ship.oldre *
			f->ship.oldim + f->ship.pi;
		if ((f->ship.newre * f->ship.newre +
					f->ship.newim * f->ship.newim) > 4)
			break ;
		f->ship.i++;
	}
}

void		draw_ship_ph1(t_fractol *f)
{
	f->ship.y = 0;
	while (f->ship.y < HIGH)
	{
		f->ship.x = 0;
		while (f->ship.x < WIDTH)
		{
			draw_ship_ph2(f);
			if (f->ship.i < f->ship.max_i)
				draw_ship(f, 1);
			else
				draw_ship(f, 0);
			f->ship.x++;
		}
		f->ship.y++;
	}
}

void		start_ship(t_fractol *f)
{
	f->info.color = (int *)malloc(350 * sizeof(int));
	f->info.mlx = mlx_init();
	f->info.win = mlx_new_window(f->info.mlx, WIDTH, HIGH, SHIP);
	f->info.img = mlx_new_image(f->info.mlx, WIDTH, HIGH);
	f->info.str = ft_strnew(1);
	f->info.str = mlx_get_data_addr(f->info.img, &f->info.bpp,
		&f->info.sline, &f->info.endian);
	prep_var_ship(f);
	draw_ship_ph1(f);
	expose_hook(f);
	mlx_mouse_hook(f->info.win, ft_ship_mouse_exit, f);
	mlx_key_hook(f->info.win, ft_ship_key_exit, f);
	mlx_loop(f->info.mlx);
}
