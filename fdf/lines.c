/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lines.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abadraja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 14:48:19 by abadraja          #+#    #+#             */
/*   Updated: 2017/01/10 10:28:39 by abadraja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_fdf		*ecospace2(t_fdf *fdf, int i, int j)
{
	fdf->eco->dx = abs(fdf->draw->x_iso[i + 1][j] - fdf->draw->x_iso[i][j]);
	fdf->eco->sx = fdf->draw->x_iso[i][j] < fdf->draw->x_iso[i + 1][j] ? 1 : -1;
	fdf->eco->dy = abs(fdf->draw->y_iso[i + 1][j] - fdf->draw->y_iso[i][j]);
	fdf->eco->sy = fdf->draw->y_iso[i][j] < fdf->draw->y_iso[i + 1][j] ? 1 : -1;
	fdf->eco->err = (fdf->eco->dx > fdf->eco->dy ? fdf->eco->dx :
			-fdf->eco->dy) / 2;
	return (fdf);
}

void		put_toleft(t_fdf *fdf, int i, int j)
{
	fdf = savein1(fdf, i, j);
	fdf = ecospace1(fdf, i, j);
	while (1)
	{
		mlx_pixel_put(fdf->info->mlx, fdf->info->win, fdf->draw->x_iso[i][j],
			fdf->draw->y_iso[i][j], fdf->info->color);
		if (fdf->draw->x_iso[i][j] == fdf->draw->x_iso[i][j + 1] &&
			fdf->draw->y_iso[i][j] == fdf->draw->y_iso[i][j + 1])
			break ;
		fdf->eco->e2 = fdf->eco->err;
		if (fdf->eco->e2 > -fdf->eco->dx)
		{
			fdf->eco->err -= fdf->eco->dy;
			fdf->draw->x_iso[i][j] += fdf->eco->sx;
		}
		if (fdf->eco->e2 < fdf->eco->dy)
		{
			fdf->eco->err += fdf->eco->dx;
			fdf->draw->y_iso[i][j] += fdf->eco->sy;
		}
	}
	fdf = saveout1(fdf, i, j);
}

void		put_todown(t_fdf *fdf, int i, int j)
{
	fdf = savein2(fdf, i, j);
	fdf = ecospace2(fdf, i, j);
	while (1)
	{
		mlx_pixel_put(fdf->info->mlx, fdf->info->win, fdf->draw->x_iso[i][j],
			fdf->draw->y_iso[i][j], fdf->info->color);
		if (fdf->draw->x_iso[i][j] == fdf->draw->x_iso[i + 1][j] &&
			fdf->draw->y_iso[i][j] == fdf->draw->y_iso[i + 1][j])
			break ;
		fdf->eco->e2 = fdf->eco->err;
		if (fdf->eco->e2 > -fdf->eco->dx)
		{
			fdf->eco->err -= fdf->eco->dy;
			fdf->draw->x_iso[i][j] += fdf->eco->sx;
		}
		if (fdf->eco->e2 < fdf->eco->dy)
		{
			fdf->eco->err += fdf->eco->dx;
			fdf->draw->y_iso[i][j] += fdf->eco->sy;
		}
	}
	fdf = saveout2(fdf, i, j);
}

void		ft_exit2(int keycode, t_fdf *fdf)
{
	if (keycode == 13)
		draw_key_up(fdf);
	if (keycode == 1)
		draw_key_down(fdf);
	if (keycode == 27)
		draw_zoomin(fdf);
	if (keycode == 24)
		draw_zoomout(fdf);
	if (keycode == 18)
		draw_18(fdf);
	if (keycode == 19)
		draw_19(fdf);
	if (keycode == 28)
		draw_colorpp(fdf);
	if (keycode == 26)
		draw_colormm(fdf);
}
