/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vect.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abadraja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 18:02:52 by abadraja          #+#    #+#             */
/*   Updated: 2017/03/01 18:02:52 by abadraja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rtv1.h"

t_vect		vect_zero()
{
	t_vect		v;

	v.x = 0;
	v.y = 0;
	v.z = 0;
	return (v);
}

t_vect		vect_3params(double i, double j, double k)
{
	t_vect		v;

	v.x = i;
	v.y = j;
	v.z = k;
	return (v);
}

double			vect_magnitude(t_vect v)
{
	return (sqrt((pow(v.x, 2) + pow(v.y, 2) + pow(v.z, 2))));
}

t_vect			vect_normalize(t_vect v)
{
	double		mag;
	t_vect		vec;

	mag = vect_magnitude(v);
	vec.x = v.x / mag;
	vec.y = v.y / mag;
	vec.z = v.z / mag;
	return (vec);
}

t_vect			vect_negative(t_vect v)
{
	t_vect		vec;

	vec.x = -v.x;
	vec.y = -v.y;
	vec.z = -v.z;
	return (vec);
}

double			vect_dot_prod(t_vect v1, t_vect v2)
{
	return (v1.x * v2.x + v1.y * v2.y +
		v1.z * v2.z);
}

t_vect			vect_cross_prod(t_vect v1, t_vect v2)
{
	t_vect	vec;

	vec.x = v1.y * v2.z - v1.z * v2.y;
	vec.y = v1.z * v2.x - v1.x * v2.z;
	vec.z = v1.x * v2.y - v1.y * v2.x;
	return (vec);
}

t_vect			vect_add(t_vect v1, t_vect v)
{
	t_vect		vec;

	vec.x = v1.x + v.x;
	vec.y = v1.y + v.y;
	vec.z = v1.z + v.z;
	return (vec);
}

t_vect			vect_mult(t_vect v, double scalar)
{
	t_vect		vec;

	vec.x = v.x * scalar;
	vec.y = v.y * scalar;
	vec.z = v.z * scalar;
	return (vec);
}

// double		get_vect_x(t_vect *vect)
// {
// 	return (vect->x);
// }

// double		get_vect_y(t_rtv1 *r)
// {
// 	return (vect.y);
// }

// double		get_vect_z(t_rtv1 *r)
// {
// 	return (r->vect.z);
// }
