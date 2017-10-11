/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abadraja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/29 13:13:02 by abadraja          #+#    #+#             */
/*   Updated: 2017/01/08 16:56:50 by abadraja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_map		*mal_map(t_map *map)
{
	int		i;

	i = 0;
	map->kek = malloc(map->rows * sizeof(int *));
	while (i < map->rows)
	{
		map->kek[i] = malloc(map->cols * sizeof(int));
		if (map->kek[i] == NULL)
		{
			printf("out of memory\n");
			exit(1);
		}
		i++;
	}
	return (map);
}

void		split_them(t_map *map, int r, int c, char *tab_krk)
{
	char	**tab_str;
	char	**tab_char;
	int		i;
	int		j;
	int		cnt;

	cnt = 0;
	i = 0;
	tab_str = ft_strsplit(tab_krk, '\n');
	c = how_much(tab_str[0]);
	inc_xyz(r, c, map);
	map = mal_map(map);
	while (i < map->rows)
	{
		j = 0;
		cnt = 0;
		while (cnt < map->cols)
		{
			map->kek[i][cnt++] = ft_atoi(&tab_str[i][j++]);
			while ((tab_str[i][j] != ' ') && tab_str[i][j])
				j++;
			j++;
		}
		i++;
	}
}

void		use_gnl(int fd, t_map *map, char **av)
{
	char	*store;
	int		r;
	int		j;
	int		c;
	char	*rez;

	r = 0;
	j = 0;
	store = ft_strnew(1);
	rez = ft_strnew(1);
	while (get_next_line(fd, &store) == 1)
	{
		rez = ft_strjoin(rez, store);
		rez = ft_strjoin(rez, "\n");
		r++;
	}
	c = ft_strlen(store);
	split_them(map, r, c, rez);
}

void		ft_exit_werror(char *text)
{
	ft_putstr(text);
	ft_putchar('\n');
	exit(0);
}

int			main(int ac, char **av)
{
	int			fd;
	t_map		*map;
	t_info		*info;
	t_eco		*eco;
	t_fdf		*fdf;

	fdf = (t_fdf *)malloc(sizeof(t_fdf));
	fdf->eco = (t_eco *)malloc(sizeof(t_eco));
	fdf->info = (t_info *)malloc(sizeof(t_info));
	fdf->map = (t_map *)malloc(sizeof(t_info));
	if (ac != 2)
		ft_exit_werror("Use only one file ma nigga!");
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
		ft_exit_werror("U sure here is that pice of cake?!");
	use_gnl(fd, fdf->map, av);
	prep_win(fdf);
	return (0);
}
