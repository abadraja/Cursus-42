/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare_ship.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abadraja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/13 15:03:59 by abadraja          #+#    #+#             */
/*   Updated: 2017/02/13 15:04:05 by abadraja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fractol.h"

void		prep_var_ship(t_fractol *f)
{
	f->ship.zoom = 0.80;
	f->ship.move_x = -0.5;
	f->ship.move_y = 0;
	f->ship.max_i = 20;
	color_first(f);
	f->eco.count1 = 0;
	f->eco.count2 = 0;
	f->info.originx = WIDTH / 2;
	f->info.originy = HIGH / 2;
}

void		draw_ship(t_fractol *f, int i)
{
	if (i)
		color_make(f);
	else
		color_to_black(f);
	f->info.x = f->ship.x;
	f->info.y = f->ship.y;
	f->info.i = f->ship.i;
	pixel_put3(f);
}
