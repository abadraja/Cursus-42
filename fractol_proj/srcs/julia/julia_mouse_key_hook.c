/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia_mouse_key_hook.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abadraja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 15:25:10 by abadraja          #+#    #+#             */
/*   Updated: 2017/05/16 18:00:45 by abadraja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fractol.h"

int			ft_julia_mouse_exit(int but, int x, int y, t_fractol *f)
{
	f->mouse.x = x;
	f->mouse.y = y;
	if (but == 4)
		move_julia_zoom_plus(f);
	if (but == 5)
		move_julia_zoom_mins(f);
	f->julia.move_x += ((x - f->info.originx) / (f->julia.zoom * 2)) / 1000;
	f->julia.move_y += ((y - f->info.originy) / (f->julia.zoom * 2)) / 1000;
	expose_hook(f);
	return (0);
}

int			ft_julia_key_exit(int key, t_fractol *f)
{
	if (key == KEY_ESC)
		exit(1);
	if (key == 35)
		f->julia.stop = 1;
	if (key == 31)
		f->julia.stop = 0;
	if (key == KEY_F5)
		move_julia_dec(f);
	if (key == KEY_F6)
		move_julia_inc(f);
	if (key == KEY_W || key == KEY_A || key == KEY_S || key == KEY_D)
		move_julia_wasd(f, key);
	if (key == KEY_PLUS)
		move_mand_zoom_plus(f);
	if (key == KEY_MINUS)
		move_mand_zoom_mins(f);
	ft_exit2(f, key);
	expose_hook(f);
	return (0);
}

void		ft_exit2(t_fractol *f, int key)
{
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
}
