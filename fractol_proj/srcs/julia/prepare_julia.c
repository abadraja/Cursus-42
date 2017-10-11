/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare_julia.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abadraja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 16:14:15 by abadraja          #+#    #+#             */
/*   Updated: 2017/02/07 15:27:06 by abadraja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fractol.h"

void		prep_var_julia(t_fractol *f)
{
	color_first(f);
	f->julia.zoom = 1;
	f->julia.move_x = 0;
	f->julia.move_y = 0;
	f->julia.max_i = 45;
	f->julia.c_re = -0.70;
	f->julia.c_im = 0.27015;
	f->julia.y = 0;
	f->julia.stop = 1;
	f->info.originx = WIDTH / 2;
	f->info.originy = HIGH / 2;
	f->eco.count1 = 0;
	f->eco.count2 = 0;
}
