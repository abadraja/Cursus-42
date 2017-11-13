 /* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abadraja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/31 16:30:01 by abadraja          #+#    #+#             */
/*   Updated: 2017/03/31 16:30:02 by abadraja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rtv1.h"

t_colors		get_ObjectColor()
{
	t_colors	col;

	col = color_4param(0.0, 0.0, 0.0, 0.0);
	return (col);
}

double		obj_findIntersection(t_ray ray)
{
	ray.origin.x = ray.origin.x + 1 - 1;
	return (0);
}
