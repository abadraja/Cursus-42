/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare_mand.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abadraja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/04 16:15:37 by abadraja          #+#    #+#             */
/*   Updated: 2017/02/04 16:15:39 by abadraja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fractol.h"

void		prep_var_mandelbrot(t_fractol *f)
{
	f->mand.zoom = 0.80;
	f->mand.move_x = -0.5;
	f->mand.move_y = 0;
	f->mand.max_i = 20;
	color_first(f);
	f->eco.count1 = 0;
	f->eco.count2 = 0;
	f->info.originx = WIDTH / 2;
	f->info.originy = HIGH / 2;
}

void		draw_mand(t_fractol *f, int i)
{
	if (i)
		color_make(f);
	else
		color_to_black(f);
	f->info.x = f->mand.x;
	f->info.y = f->mand.y;
	f->info.i = f->mand.i;
	pixel_put(f);
}
