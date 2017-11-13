/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abadraja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/31 13:53:56 by abadraja          #+#    #+#             */
/*   Updated: 2017/03/31 13:53:57 by abadraja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rtv1.h"

t_sphere			sphere_zero()
{
	t_sphere		l;
	t_vect			v1;

	l.type = T_SPHERE;
	v1 = vect_zero();
	l.center = v1;
	l.radius = 1.0;
	l.col = color_4param(0.5, 0.5, 0.5, 0);
	return (l);
}

t_sphere		sphere_2param(t_vect c, double r, t_colors d)
{
	t_sphere		l;

	l.type = T_SPHERE;
	l.center = c;
	l.radius = r;
	l.col = d;
	return (l);
}

t_vect			shpere_get_normal_at(t_vect point, t_vect *center)
{
	t_vect		normal_vec;

	normal_vec = vect_normalize(vect_add(point, vect_negative(*center)));
	return (normal_vec);
}

double			shpere_findIntersection(t_ray ray, t_sphere *center)
{
	t_vect ray_origin = ray.origin;
	double ray_origin_x = ray_origin.x;
	double ray_origin_y = ray_origin.y;
	double ray_origin_z = ray_origin.z;
		
	t_vect ray_direction = ray.direction;
	double ray_direction_x = ray_direction.x;
	double ray_direction_y = ray_direction.y;
	double ray_direction_z = ray_direction.z;
		
	t_vect sphere_center = center->center;
	double sphere_center_x = sphere_center.x;
	double sphere_center_y = sphere_center.y;
	double sphere_center_z = sphere_center.z;
		
	double a = 1;
	double b = (2*(ray_origin_x - sphere_center_x)*ray_direction_x) + (2*(ray_origin_y - sphere_center_y)*ray_direction_y) + (2*(ray_origin_z - sphere_center_z)*ray_direction_z);
	double c = pow(ray_origin_x - sphere_center_x, 2) + pow(ray_origin_y - sphere_center_y, 2) + pow(ray_origin_z - sphere_center_z, 2) - (center->radius*center->radius);
		
	double discriminant = b*b - 4*c*a;
		
	if (discriminant > 0)
	{
			/// the ray intersects the sphere
			// the first root
		double root_1 = ((-1*b - sqrt(discriminant))/2) - 0.000001;
			
		if (root_1 > 0) {
			// the first root is the smallest positive root
			return root_1;
		}
		else {
			// the second root is the smallest positive root
			double root_2 = ((sqrt(discriminant) - b)/2) - 0.000001;

			return root_2;
		}
	}
	else
	{
		// the ray missed the sphere
		return -1;
	}
}

