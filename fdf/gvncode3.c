/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gvncode3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abadraja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 09:43:06 by abadraja          #+#    #+#             */
/*   Updated: 2017/01/10 10:28:37 by abadraja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		draw_18(t_fdf *fdf)
{
	int i;
	int j;
	int	save;

	save = fdf->info->color;
	i = 0;
	fdf->info->color = BLACK;
	draw_dots(fdf);
	while (i < fdf->map->rows)
	{
		j = 0;
		while (j < fdf->map->cols)
		{
			if (fdf->map->kek[i][j] != 0)
				fdf->map->kek[i][j] -= 4;
			j++;
		}
		i++;
	}
	fdf->info->color = save;
	draw_dots(fdf);
}

void		draw_19(t_fdf *fdf)
{
	int i;
	int j;
	int	save;

	save = fdf->info->color;
	i = 0;
	fdf->info->color = BLACK;
	draw_dots(fdf);
	while (i < fdf->map->rows)
	{
		j = 0;
		while (j < fdf->map->cols)
		{
			if (fdf->map->kek[i][j] != 0)
				fdf->map->kek[i][j] += 5;
			j++;
		}
		i++;
	}
	fdf->info->color = WHITE;
	draw_dots(fdf);
}

void		draw_colorpp(t_fdf *fdf)
{
	fdf->info->color += 15;
	draw_dots(fdf);
}

void		draw_colormm(t_fdf *fdf)
{
	fdf->info->color -= 15;
	draw_dots(fdf);
}

void		draw_leg(t_fdf *fdf)
{
	char	*leg;
	char	*leg2;
	char	*leg3;
	char	*sry;

	leg = "WASD = move | Arrows = rotate | 1,2 = change high | -/+ = zoom";
	leg2 = "7/8 = colorchange(yellow->blue)*";
	leg3 = "*Red is for wine, not for fdf =3";
	sry = "Don't hurt my gvncoder feelings, thx.";
	mlx_string_put(fdf->info->mlx, fdf->info->win, 50, 700, BLACK, leg);
	mlx_string_put(fdf->info->mlx, fdf->info->win, 50, 725, BLACK, leg2);
	mlx_string_put(fdf->info->mlx, fdf->info->win, 50, 750, BLACK, leg3);
	mlx_string_put(fdf->info->mlx, fdf->info->win, 50, 780, BLACK, sry);
	mlx_string_put(fdf->info->mlx, fdf->info->win, 50, 700, 0x0066FF33, leg);
	mlx_string_put(fdf->info->mlx, fdf->info->win, 50, 725, 0x0066FF33, leg2);
	mlx_string_put(fdf->info->mlx, fdf->info->win, 50, 750, 0x0066FF33, leg3);
	mlx_string_put(fdf->info->mlx, fdf->info->win, 50, 780, 0x0066FF33, sry);
}
