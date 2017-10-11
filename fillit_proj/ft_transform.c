/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_transform.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abadraja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 16:19:19 by abadraja          #+#    #+#             */
/*   Updated: 2016/11/21 16:19:21 by abadraja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hf.h"

t_vector2		*ft_new_vector2(int x, int y)
{
	t_vector2	*v;

	v = (t_vector2*)malloc(sizeof(t_vector2));
	v->x = x;
	v->y = y;
	return (v);
}

void			ft_get_limits(char **t, t_vector2 *lu, t_vector2 *rb)
{
	int			i;
	int			j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (t[i][j] == '#')
			{
				lu->y = (i < lu->y) ? i : lu->y;
				rb->y = (i > rb->y) ? i : rb->y;
				lu->x = (j < lu->x) ? j : lu->x;
				rb->x = (j > rb->x) ? j : rb->x;
			}
			j++;
		}
		i++;
	}
}

t_tetr			*ft_tet_inst(char **content, int width, int height, char let)
{
	t_tetr		*rez;

	rez = (t_tetr*)malloc(sizeof(t_tetr));
	rez->content = content;
	rez->width = width;
	rez->height = height;
	rez->let = let;
	return (rez);
}

t_tetr			*ft_prepare_tet(char **t, char let)
{
	t_vector2	*lu;
	t_vector2	*rb;
	t_tetr		*tetr;
	int			i;
	char		**rez;

	i = 0;
	lu = ft_new_vector2(3, 3);
	rb = ft_new_vector2(0, 0);
	ft_get_limits(t, lu, rb);
	rez = (char**)malloc(sizeof(char*) * (rb->y - lu->y + 1));
	while (i < (rb->y - lu->y) + 1)
	{
		rez[i] = (char*)malloc(sizeof(char) * (rb->x - lu->x));
		ft_strncpy(rez[i], t[lu->y + i] + lu->x, rb->x - lu->x + 1);
		i++;
	}
	tetr = ft_tet_inst(rez, rb->x - lu->x + 1, rb->y - lu->y + 1, let);
	free(lu);
	free(rb);
	return (tetr);
}
