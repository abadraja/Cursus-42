/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abadraja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 16:41:49 by abadraja          #+#    #+#             */
/*   Updated: 2017/03/02 16:41:50 by abadraja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rtv1.h"

t_camera		cam_zero()
{
	t_camera	c;

	c.pos.x = 0;
	c.pos.y = 0;
	c.pos.z = 0;
	c.dir.x = 0;
	c.dir.y = 0;
	c.dir.z = 1;
	c.right.x = 0;
	c.right.y = 0;
	c.right.z = 0;
	c.down.x = 0;
	c.down.y = 0;
	c.down.z = 0;
	return (c);
}

t_camera		cam_2params(t_vect p, t_vect di, t_vect right, t_vect d)
{
	t_camera	c;

	c.pos.x = p.x;
	c.pos.y = p.y;
	c.pos.z = p.z;
	c.dir.x = di.x;
	c.dir.y = di.y;
	c.dir.z = di.z;
	c.right.x = right.x;
	c.right.y = right.y;
	c.right.z = right.z;
	c.down.x = d.x;
	c.down.y = d.y;
	c.down.z = d.z;
	return (c);
}
