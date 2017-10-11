/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abadraja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 12:20:07 by abadraja          #+#    #+#             */
/*   Updated: 2017/01/06 15:32:19 by abadraja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_fdf		*mal_draw(t_fdf *fdf)
{
	fdf->eco->i = 0;
	fdf->draw->x_iso = malloc(fdf->map->rows * sizeof(int *));
	while (fdf->eco->i < fdf->map->rows)
	{
		fdf->draw->x_iso[fdf->eco->i] = malloc(fdf->map->cols * sizeof(int));
		if (fdf->draw->x_iso[fdf->eco->i] == NULL)
		{
			ft_putendl("out of memory");
			exit(1);
		}
		fdf->eco->i++;
	}
	return (fdf);
}

t_fdf		*mal_draw2(t_fdf *fdf)
{
	fdf->eco->i = 0;
	fdf->draw->y_iso = malloc(fdf->map->rows * sizeof(int *));
	while (fdf->eco->i < fdf->map->rows)
	{
		fdf->draw->y_iso[fdf->eco->i] = malloc(fdf->map->cols * sizeof(int));
		if (fdf->draw->y_iso[fdf->eco->i] == NULL)
		{
			ft_putendl("out of memory");
			exit(1);
		}
		fdf->eco->i++;
	}
	return (fdf);
}

t_fdf		*calc_eco(t_fdf *fdf)
{
	fdf->eco->space = 0.75 * (WIDTH / (fdf->map->rows *
		0.5 + fdf->map->cols * 0.86 + fdf->eco->zoom));
	fdf->eco->cos_angle = cos(fdf->info->coss * M_PI / 180);
	fdf->eco->sin_angle = sin(fdf->info->sinn * M_PI / 180);
	return (fdf);
}

void		draw_dots(t_fdf *fdf)
{
	fdf->eco->i = 0;
	fdf = calc_eco(fdf);
	while (fdf->eco->i < fdf->map->rows)
	{
		fdf->eco->j = 0;
		while (fdf->eco->j < fdf->map->cols)
		{
			fdf->draw->x_iso[fdf->eco->i][fdf->eco->j] = (fdf->eco->i -
				fdf->map->rows / 2) * fdf->eco->space *
				-fdf->eco->cos_angle + (fdf->eco->j - fdf->map->cols / 2) *
				fdf->eco->space * fdf->eco->cos_angle + WIDTH / 2 + fdf->eco->x;
			fdf->draw->y_iso[fdf->eco->i][fdf->eco->j] = (fdf->eco->i -
				fdf->map->rows / 2) * fdf->eco->space *
				fdf->eco->sin_angle - (fdf->eco->j - fdf->map->cols / 2) *
				fdf->eco->space * -fdf->eco->sin_angle -
				fdf->map->kek[fdf->eco->i][fdf->eco->j] *
				MAG * fdf->eco->space + HEIGHT / 2 + fdf->eco->y;
			fdf->eco->j++;
		}
		fdf->eco->i++;
	}
	draw_lines(fdf);
}

void		draw_lines(t_fdf *fdf)
{
	draw_leg(fdf);
	fdf->eco->i = 0;
	while (fdf->eco->i < fdf->map->rows)
	{
		fdf->eco->j = 0;
		while (fdf->eco->j < fdf->map->cols)
		{
			if (fdf->eco->j != fdf->map->cols - 1)
				put_toleft(fdf, fdf->eco->i, fdf->eco->j);
			if (fdf->eco->i != fdf->map->rows - 1)
				put_todown(fdf, fdf->eco->i, fdf->eco->j);
			fdf->eco->j++;
		}
		fdf->eco->i++;
	}
}
