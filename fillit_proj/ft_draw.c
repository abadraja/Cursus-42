/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abadraja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 16:23:20 by abadraja          #+#    #+#             */
/*   Updated: 2016/11/21 16:36:55 by abadraja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hf.h"

void	ft_free_tab(t_tab *tab)
{
	int i;

	i = 0;
	while (i < tab->size)
	{
		ft_memdel((void **)&(tab->tab[i]));
		i++;
	}
	ft_memdel((void **)&(tab->tab));
	ft_memdel((void **)&tab);
}

t_tab	*ft_tab_inst(int size)
{
	t_tab	*tab;
	int		i;
	int		j;

	tab = (t_tab *)ft_memalloc(sizeof(t_tab));
	tab->size = size;
	tab->tab = (char **)ft_memalloc(sizeof(char *) * size);
	i = 0;
	while (i < size)
	{
		tab->tab[i] = ft_strnew(size);
		j = 0;
		while (j < size)
		{
			tab->tab[i][j] = '.';
			j++;
		}
		i++;
	}
	return (tab);
}

void	ft_draw(t_tetr *tet, t_tab *tab, t_vector2 *point)
{
	int i;
	int j;

	i = 0;
	while (i < tet->width)
	{
		j = 0;
		while (j < tet->height)
		{
			if (tet->content[j][i] == '#')
				tab->tab[point->y + j][point->x + i] = tet->let;
			j++;
		}
		i++;
	}
	ft_memdel((void **)&point);
}

void	ft_remove(t_tetr *tet, t_tab *tab, t_vector2 *point)
{
	int i;
	int j;

	i = 0;
	while (i < tet->width)
	{
		j = 0;
		while (j < tet->height)
		{
			if (tet->content[j][i] == '#')
				tab->tab[point->y + j][point->x + i] = '.';
			j++;
		}
		i++;
	}
	ft_memdel((void **)&point);
}

int		ft_try(t_tetr *tet, t_tab *tab, int x, int y)
{
	int i;
	int j;

	i = 0;
	while (i < tet->width)
	{
		j = 0;
		while (j < tet->height)
		{
			if (tet->content[j][i] == '#' && tab->tab[y + j][x + i] != '.')
				return (0);
			j++;
		}
		i++;
	}
	ft_draw(tet, tab, ft_new_vector2(x, y));
	return (1);
}
