/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_mand.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abadraja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 16:50:30 by abadraja          #+#    #+#             */
/*   Updated: 2017/02/04 16:12:24 by abadraja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fractol.h"

void		move_mand_wasd(t_fractol *f, int key)
{
	if (key == KEY_A)
		f->mand.move_x -= 0.1 / f->mand.zoom;
	else if (key == KEY_D)
		f->mand.move_x += 0.1 / f->mand.zoom;
	else if (key == KEY_W)
		f->mand.move_y -= 0.1 / f->mand.zoom;
	else if (key == KEY_S)
		f->mand.move_y += 0.1 / f->mand.zoom;
	draw_mandelbrot_ph1(f);
}

void		move_mand_zoom_plus(t_fractol *f)
{
	if (f->eco.count1 > 20)
	{
		f->mand.max_i += 4 + f->eco.count2 / 4;
		f->eco.count1 = 0;
	}
	f->mand.zoom *= 1.1;
	if (f->eco.count2 > 20)
		f->mand.zoom *= 1.1;
	draw_mandelbrot_ph1(f);
	f->eco.count1++;
	f->eco.count2++;
}

void		move_mand_zoom_mins(t_fractol *f)
{
	f->mand.max_i--;
	if (f->mand.zoom > 0)
	{
		f->mand.zoom /= 1.1;
		draw_mandelbrot_ph1(f);
	}
	if (f->eco.count2 > 20)
		f->mand.zoom /= 1.1;
}

void		move_mand_increase(t_fractol *f)
{
	f->mand.max_i += 5;
	draw_mandelbrot_ph1(f);
}
