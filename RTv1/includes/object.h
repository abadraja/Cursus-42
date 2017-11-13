/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abadraja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/31 16:19:14 by abadraja          #+#    #+#             */
/*   Updated: 2017/03/31 16:19:15 by abadraja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECT_H
# define OBJECT_H

# include "rtv1.h"
# include "plane.h"

typedef struct 	s_object
{
	t_plane		*planes;
	t_sphere	*shperes;
}				t_object;

#endif
