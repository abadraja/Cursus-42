/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abadraja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 08:09:18 by abadraja          #+#    #+#             */
/*   Updated: 2017/01/10 09:50:00 by abadraja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		draw_plus_sinn(t_fdf *fdf)
{
	int	save;

	save = fdf->info->color;
	fdf->info->color = BLACK;
	draw_dots(fdf);
	fdf->info->sinn += 5;
	fdf->info->color = save;
	draw_dots(fdf);
}

void		draw_minus_sinn(t_fdf *fdf)
{
	int	save;

	save = fdf->info->color;
	fdf->info->color = BLACK;
	draw_dots(fdf);
	fdf->info->sinn -= 5;
	fdf->info->color = save;
	draw_dots(fdf);
}

void		draw_minus_coss(t_fdf *fdf)
{
	int	save;

	save = fdf->info->color;
	fdf->info->color = BLACK;
	draw_dots(fdf);
	fdf->info->coss -= 5;
	fdf->info->color = save;
	draw_dots(fdf);
}

void		draw_plus_coss(t_fdf *fdf)
{
	int	save;

	save = fdf->info->color;
	fdf->info->color = BLACK;
	draw_dots(fdf);
	fdf->info->coss += 5;
	fdf->info->color = save;
	draw_dots(fdf);
}

void		draw_key_right(t_fdf *fdf)
{
	int	save;

	save = fdf->info->color;
	fdf->info->color = BLACK;
	draw_dots(fdf);
	fdf->eco->x += 5;
	fdf->info->color = save;
	draw_dots(fdf);
}
