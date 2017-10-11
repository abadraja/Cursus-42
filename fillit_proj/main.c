/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abadraja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 15:19:23 by abadraja          #+#    #+#             */
/*   Updated: 2016/11/21 16:38:21 by abadraja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hf.h"

void			ft_print_sol(t_tab *tab)
{
	int			i;

	i = 0;
	while (i < tab->size)
	{
		ft_putstr(tab->tab[i]);
		ft_putchar('\n');
		i++;
	}
}

int				ft_backtrack(t_tab *tab, t_list *tetlist)
{
	int			x;
	int			y;
	t_tetr		*tet;

	if (tetlist == NULL)
		return (1);
	y = 0;
	tet = (t_tetr *)(tetlist->content);
	while (y < tab->size - tet->height + 1)
	{
		x = 0;
		while (x < tab->size - tet->width + 1)
		{
			if (ft_try(tet, tab, x, y))
			{
				if (ft_backtrack(tab, tetlist->next))
					return (1);
				else
					ft_remove(tet, tab, ft_new_vector2(x, y));
			}
			x++;
		}
		y++;
	}
	return (0);
}

int				high_sqrt(int n)
{
	int			size;

	size = 2;
	while (size * size < n)
		size++;
	return (size);
}

int				main(int ac, char **av)
{
	int			fd;
	t_list		*tetlist;
	t_tab		*tab;
	int			size;

	if (ac != 2)
		ft_exit_werror("usage: fillit input_file");
	fd = open(av[1], O_RDONLY);
	tetlist = ft_parse(fd);
	size = high_sqrt(ft_lstlen(tetlist) * 4);
	tab = ft_tab_inst(size);
	while (!ft_backtrack(tab, tetlist))
	{
		size++;
		ft_free_tab(tab);
		tab = ft_tab_inst(size);
	}
	ft_print_sol(tab);
	ft_free_tab(tab);
	ft_lstfree(tetlist);
	return (0);
}
