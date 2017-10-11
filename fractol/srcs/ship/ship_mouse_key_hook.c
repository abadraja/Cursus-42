/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ship_mouse_key_hook.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abadraja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/13 15:04:13 by abadraja          #+#    #+#             */
/*   Updated: 2017/02/13 15:04:15 by abadraja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fractol.h"

int			ft_ship_key_exit(int key, t_fractol *f)
{
	if (key == KEY_ESC)
		exit(1);
	if (key == KEY_W || key == KEY_A || key == KEY_S || key == KEY_D)
		move_ship_wasd(f, key);
	if (key == KEY_PLUS)
		move_ship_zoom_plus(f);
	if (key == KEY_MINUS)
		move_ship_zoom_mins(f);
	if (key == KEY_SPACE)
		move_ship_increase(f);
	if (key == KEY_2)
		color_2(f);
	if (key == KEY_1)
		color_first(f);
	if (key == KEY_3)
		color_3(f);
	if (key == KEY_4)
		color_4(f);
	if (key == KEY_5)
		color_5(f);
	if (key == KEY_6)
		color_6(f);
	expose_hook(f);
	return (0);
}

int			ft_ship_mouse_exit(int but, int x, int y, t_fractol *f)
{
	f->mouse.x = x;
	f->mouse.y = y;
	if (but == 4)
		move_ship_zoom_plus(f);
	if (but == 5)
		move_ship_zoom_mins(f);
	f->ship.move_x += ((x - f->info.originx) / (f->ship.zoom * 2)) / 1000;
	f->ship.move_y += ((y - f->info.originy) / (f->ship.zoom * 2)) / 1000;
	expose_hook(f);
	return (0);
}
