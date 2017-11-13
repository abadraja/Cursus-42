/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abadraja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/31 17:03:21 by abadraja          #+#    #+#             */
/*   Updated: 2017/03/31 17:03:23 by abadraja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLANE_H
# define PLANE_H

# include "rtv1.h"

typedef struct 	s_plane
{
	int			type;
	t_vect		normal;
	double		distance;
	t_colors	col;
}				t_plane;

#endif
