/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_ship.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abadraja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/13 15:03:51 by abadraja          #+#    #+#             */
/*   Updated: 2017/02/13 15:03:52 by abadraja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fractol.h"

void		move_ship_wasd(t_fractol *f, int key)
{
	if (key == KEY_A)
		f->ship.move_x -= 0.1 / f->ship.zoom;
	else if (key == KEY_D)
		f->ship.move_x += 0.1 / f->ship.zoom;
	else if (key == KEY_W)
		f->ship.move_y -= 0.1 / f->ship.zoom;
	else if (key == KEY_S)
		f->ship.move_y += 0.1 / f->ship.zoom;
	draw_ship_ph1(f);
}

void		move_ship_zoom_plus(t_fractol *f)
{
	if (f->eco.count1 > 20)
	{
		f->ship.max_i += 4 + f->eco.count2 / 4;
		f->eco.count1 = 0;
	}
	f->ship.zoom *= 1.1;
	if (f->eco.count2 > 20)
		f->ship.zoom *= 1.1;
	draw_ship_ph1(f);
	f->eco.count1++;
	f->eco.count2++;
}

void		move_ship_zoom_mins(t_fractol *f)
{
	f->ship.max_i--;
	if (f->ship.zoom > 0)
	{
		f->ship.zoom /= 1.1;
		draw_ship_ph1(f);
	}
	if (f->eco.count2 > 20)
		f->ship.zoom /= 1.1;
}

void		move_ship_increase(t_fractol *f)
{
	f->ship.max_i += 5;
	draw_ship_ph1(f);
}
