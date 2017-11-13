/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abadraja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 18:08:09 by abadraja          #+#    #+#             */
/*   Updated: 2017/03/03 18:08:10 by abadraja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rtv1.h"

t_light		light_zero()
{
	t_light		l;
	t_vect		v1;

	v1 = vect_zero();
	l.pos = v1;
	l.col = color_4param(1, 1, 1, 0);
	return (l);
}

t_light		light_2param(t_vect p, t_colors d)
{
	t_light		l;

	l.pos = p;
	l.col = d;
	return (l);
}
