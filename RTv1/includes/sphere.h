/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abadraja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/31 13:51:07 by abadraja          #+#    #+#             */
/*   Updated: 2017/03/31 13:51:09 by abadraja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPHERE_H
# define SPHERE_H

# include "rtv1.h"

typedef struct 	s_sphere
{
	int			type;
	t_vect		center;
	double		radius;
	t_colors	col;
}				t_sphere;

#endif
