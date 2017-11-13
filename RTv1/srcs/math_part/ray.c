/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abadraja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 16:08:44 by abadraja          #+#    #+#             */
/*   Updated: 2017/03/02 16:08:46 by abadraja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rtv1.h"

t_ray			ray_zero()
{
	t_ray		r;

	r.origin.x = 0;
	r.origin.y = 0;
	r.origin.z = 0;
	r.direction.x = 1;
	r.direction.y = 0;
	r.direction.z = 0;
	return (r);
}

t_ray			ray_2params(t_vect o, t_vect d)
{
	t_ray		r;

	r.origin.x = o.x;
	r.origin.y = o.y;
	r.origin.z = o.z;
	r.direction.x = d.x;
	r.direction.y = d.y;
	r.direction.z = d.z;
	return (r);
}
