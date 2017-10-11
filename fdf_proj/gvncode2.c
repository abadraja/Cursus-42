/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gvncode2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abadraja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 09:42:27 by abadraja          #+#    #+#             */
/*   Updated: 2017/01/10 09:53:43 by abadraja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		draw_key_up(t_fdf *fdf)
{
	int	save;

	save = fdf->info->color;
	fdf->info->color = BLACK;
	draw_dots(fdf);
	fdf->eco->y -= 5;
	fdf->info->color = save;
	draw_dots(fdf);
}

void		draw_key_left(t_fdf *fdf)
{
	int	save;

	save = fdf->info->color;
	fdf->info->color = BLACK;
	draw_dots(fdf);
	fdf->eco->x -= 5;
	fdf->info->color = save;
	draw_dots(fdf);
}

void		draw_key_down(t_fdf *fdf)
{
	int	save;

	save = fdf->info->color;
	fdf->info->color = BLACK;
	draw_dots(fdf);
	fdf->eco->y += 5;
	fdf->info->color = save;
	draw_dots(fdf);
}

void		draw_zoomin(t_fdf *fdf)
{
	int	save;

	save = fdf->info->color;
	fdf->info->color = BLACK;
	draw_dots(fdf);
	fdf->eco->zoom += 3;
	fdf->info->color = save;
	draw_dots(fdf);
}

void		draw_zoomout(t_fdf *fdf)
{
	int	save;

	save = fdf->info->color;
	fdf->info->color = BLACK;
	draw_dots(fdf);
	fdf->eco->zoom -= 3;
	fdf->info->color = save;
	draw_dots(fdf);
}
