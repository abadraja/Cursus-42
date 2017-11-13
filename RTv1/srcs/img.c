/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abadraja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 17:30:05 by abadraja          #+#    #+#             */
/*   Updated: 2017/02/28 17:30:23 by abadraja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

void		pixel_put(t_rtv1 *r)
{
	int		offset;

	offset = r->info.x * 4;
	offset += r->info.y * r->info.sline;
	*(int*)(r->info.str + offset) = r->info.color;
}

int			expose_hook(t_rtv1 *r)
{
	mlx_clear_window(r->info.mlx, r->info.win);
	pixel_put(r);
	mlx_put_image_to_window(r->info.mlx, r->info.win, r->info.img, 0, 0);
	return (0);
}
