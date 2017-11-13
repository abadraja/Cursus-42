/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_camera.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abadraja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 17:03:37 by abadraja          #+#    #+#             */
/*   Updated: 2017/03/02 17:03:38 by abadraja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rtv1.h"

t_vect		get_cam_pos(t_rtv1 *r)
{
	return (r->cam.pos);
}

t_vect		get_cam_dir(t_rtv1 *r)
{
	return (r->cam.dir);
}

t_vect		get_cam_right(t_rtv1 *r)
{
	return (r->cam.right);
}

t_vect		get_cam_down(t_rtv1 *r)
{
	return (r->cam.down);
}
