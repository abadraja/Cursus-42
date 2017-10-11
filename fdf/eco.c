/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eco.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abadraja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/08 18:08:26 by abadraja          #+#    #+#             */
/*   Updated: 2017/01/08 18:14:05 by abadraja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_fdf		*savein1(t_fdf *fdf, int i, int j)
{
	fdf->eco->savex0 = fdf->draw->x_iso[i][j];
	fdf->eco->savey0 = fdf->draw->y_iso[i][j];
	fdf->eco->savex1 = fdf->draw->x_iso[i][j + 1];
	fdf->eco->savey1 = fdf->draw->y_iso[i][j + 1];
	return (fdf);
}

t_fdf		*saveout1(t_fdf *fdf, int i, int j)
{
	fdf->draw->x_iso[i][j] = fdf->eco->savex0;
	fdf->draw->y_iso[i][j] = fdf->eco->savey0;
	fdf->draw->x_iso[i][j + 1] = fdf->eco->savex1;
	fdf->draw->y_iso[i][j + 1] = fdf->eco->savey1;
	return (fdf);
}

t_fdf		*ecospace1(t_fdf *fdf, int i, int j)
{
	fdf->eco->dx = abs(fdf->draw->x_iso[i][j + 1] - fdf->draw->x_iso[i][j]);
	fdf->eco->sx = fdf->draw->x_iso[i][j] < fdf->draw->x_iso[i][j + 1] ? 1 : -1;
	fdf->eco->dy = abs(fdf->draw->y_iso[i][j + 1] - fdf->draw->y_iso[i][j]);
	fdf->eco->sy = fdf->draw->y_iso[i][j] < fdf->draw->y_iso[i][j + 1] ? 1 : -1;
	fdf->eco->err = (fdf->eco->dx > fdf->eco->dy ? fdf->eco->dx :
		-fdf->eco->dy) / 2;
	return (fdf);
}

t_fdf		*savein2(t_fdf *fdf, int i, int j)
{
	fdf->eco->savex0 = fdf->draw->x_iso[i][j];
	fdf->eco->savey0 = fdf->draw->y_iso[i][j];
	fdf->eco->savex1 = fdf->draw->x_iso[i + 1][j];
	fdf->eco->savey1 = fdf->draw->y_iso[i + 1][j];
	return (fdf);
}

t_fdf		*saveout2(t_fdf *fdf, int i, int j)
{
	fdf->draw->x_iso[i][j] = fdf->eco->savex0;
	fdf->draw->y_iso[i][j] = fdf->eco->savey0;
	fdf->draw->x_iso[i + 1][j] = fdf->eco->savex1;
	fdf->draw->y_iso[i + 1][j] = fdf->eco->savey1;
	return (fdf);
}
