/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abadraja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/31 17:14:41 by abadraja          #+#    #+#             */
/*   Updated: 2017/03/31 17:14:42 by abadraja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rtv1.h"

t_plane			plane_zero()
{
	t_plane		l;
	t_vect		v1;

	l.type = T_PLANE;
	v1 = vect_3params(1, 0, 0);
	l.normal = v1;
	l.distance = 0;
	l.col = color_4param(0.5, 0.5, 0.5, 0);
	return (l);
}

t_plane			plane_3param(t_vect c, double r, t_colors d)
{
	t_plane		l;

	l.type = T_PLANE;
	l.normal = c;
	l.distance = r;
	l.col = d;
	return (l);
}

double			plane_findIntersection(t_ray ray, t_plane *plane)
{
	double		a;
	double		b;
	t_vect		ray_direction;

	ray_direction = ray.direction;
	a = vect_dot_prod(ray_direction, plane->normal);
	if (a == 0)
		return (-1);
	else
	{
		b = vect_dot_prod(plane->normal, vect_add(ray.origin,
			vect_negative(vect_mult(plane->normal, plane->distance))));
		return (-1 * b / a);
	}
}

t_vect			getNormalAt(t_vect point, t_plane plane)
{
	point.x = point.x + 0;
	return (plane.normal);
}