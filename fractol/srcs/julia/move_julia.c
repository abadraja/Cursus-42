/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_julia.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abadraja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 15:23:57 by abadraja          #+#    #+#             */
/*   Updated: 2017/05/16 18:02:37 by abadraja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fractol.h"

int			ft_mouse_motion(int x, int y, t_fractol *f)
{
	if (f->julia.stop % 2 == 1)
	{
		f->julia.c_re = (double)x / (double)WIDTH * 4 - 5.9;
		f->julia.c_im = (double)y / (double)HIGH * 4 - 2.1;
		draw_julia_ph1(f);
		expose_hook(f);
	}
	return (0);
}

void		move_julia_wasd(t_fractol *f, int key)
{
	if (key == KEY_A)
		f->julia.move_x -= 0.1 / f->julia.zoom;
	else if (key == KEY_D)
		f->julia.move_x += 0.1 / f->julia.zoom;
	else if (key == KEY_W)
		f->julia.move_y -= 0.1 / f->julia.zoom;
	else if (key == KEY_S)
		f->julia.move_y += 0.1 / f->julia.zoom;
	draw_julia_ph1(f);
	expose_hook(f);
}

void		move_julia_zoom_plus(t_fractol *f)
{
	if (f->eco.count1 > 20)
	{
		f->julia.max_i += 4 + f->eco.count2 / 5;
		f->eco.count1 = 0;
	}
	f->julia.zoom *= 1.1;
	if (f->eco.count2 > 20)
		f->julia.zoom *= 1.1;
	draw_julia_ph1(f);
	expose_hook(f);
	f->eco.count1++;
	f->eco.count2++;
}

void		move_julia_zoom_mins(t_fractol *f)
{
	f->julia.max_i--;
	if (f->julia.zoom > 0)
	{
		f->julia.zoom /= 1.1;
		draw_julia_ph1(f);
		expose_hook(f);
	}
	if (f->eco.count2 > 20)
		f->julia.zoom /= 1.1;
}
