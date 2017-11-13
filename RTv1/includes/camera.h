/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abadraja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 16:39:59 by abadraja          #+#    #+#             */
/*   Updated: 2017/03/02 16:40:00 by abadraja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMERA_H
# define CAMERA_H

# include "rtv1.h"

typedef struct 	s_camera
{
	t_vect		pos;
	t_vect		dir;
	t_vect		right;
	t_vect		down;
}				t_camera;

#endif
