/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abadraja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 16:40:03 by abadraja          #+#    #+#             */
/*   Updated: 2017/01/10 10:17:49 by abadraja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		inc_xyz(int x, int y, t_map *map)
{
	map->rows = x;
	map->cols = y;
}

int			how_much(char *str)
{
	int			cnt;
	int			i;
	int			j;

	i = 0;
	j = 0;
	cnt = 0;
	while (str[i] != '\0')
	{
		if (str[i] == ' ')
			i++;
		if (str[i] != ' ' && str[i])
		{
			cnt++;
			while (str[i] != ' ' && str[i])
				i++;
		}
		i++;
	}
	return (cnt);
}

int			ft_exit(int keycode, t_fdf *fdf)
{
	if (keycode == 53)
		exit(1);
	if (keycode == 123)
		draw_plus_coss(fdf);
	if (keycode == 124)
		draw_minus_coss(fdf);
	if (keycode == 125)
		draw_plus_sinn(fdf);
	if (keycode == 126)
		draw_minus_sinn(fdf);
	if (keycode == 0)
		draw_key_left(fdf);
	if (keycode == 2)
		draw_key_right(fdf);
	ft_exit2(keycode, fdf);
	return (0);
}

void		eval(t_fdf *fdf)
{
	int		cnt;
	size_t	k;

	cnt = 0;
	fdf->eco->i = 0;
	k = fdf->map->rows * fdf->map->cols;
	fdf->info->x = (int *)malloc(k * sizeof(int));
	fdf->info->y = (int *)malloc(k * sizeof(int));
	fdf->info->z = (int *)malloc(k * sizeof(int));
	while (fdf->eco->i < fdf->map->rows)
	{
		fdf->eco->j = 0;
		while (fdf->eco->j < fdf->map->cols)
		{
			fdf->info->x[cnt] = fdf->eco->i;
			fdf->info->y[cnt] = fdf->eco->j;
			fdf->info->z[cnt] = fdf->map->kek[fdf->eco->i][fdf->eco->j];
			cnt++;
			fdf->eco->j++;
		}
		fdf->eco->i++;
	}
	fdf->map->cnt = cnt;
}

void		prep_win(t_fdf *fdf)
{
	fdf->info->mlx = mlx_init();
	fdf->draw = (t_draw *)malloc(sizeof(t_draw));
	fdf = mal_draw(fdf);
	fdf = mal_draw2(fdf);
	fdf->info->win = mlx_new_window(fdf->info->mlx, WIDTH, HEIGHT, PPAP);
	eval(fdf);
	fdf->info->color = WHITE;
	fdf->info->coss = 30;
	fdf->info->sinn = 40;
	fdf->eco->zoom = 0;
	fdf->eco->x = 0;
	fdf->eco->y = 0;
	draw_dots(fdf);
	mlx_key_hook(fdf->info->win, ft_exit, fdf);
	mlx_loop(fdf->info->mlx);
}
