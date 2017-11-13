/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abadraja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 17:40:40 by abadraja          #+#    #+#             */
/*   Updated: 2017/03/03 17:40:41 by abadraja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rtv1.h"

t_colors	color_zero()
{
	t_colors	c;

	c.r = 0.5;
	c.g = 0.5;
	c.b = 0.5;
	return (c);
}

t_colors	color_4param(double r, double g, double b, double sp)
{
	t_colors	col;

	col.r = r;
	col.g = g;
	col.b = b;
	col.sp = sp;
	return (col);
}

double		set_color_red(t_colors col, double val)
{
	col.r = val;
	return (col.r);
}

double		set_color_green(t_colors col, double val)
{
	col.g = val;
	return (col.g);
}

double		set_color_blue(t_colors col, double val)
{
	col.b = val;
	return (col.b);
}

double		set_color_sp(t_colors col, double val)
{
	col.sp = val;
	return (col.sp);
}
