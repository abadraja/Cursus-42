/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abadraja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 16:19:07 by abadraja          #+#    #+#             */
/*   Updated: 2016/11/21 16:37:41 by abadraja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hf.h"

void		ft_tetfree(t_tetr *tet)
{
	int i;

	i = 0;
	while (i < tet->height)
	{
		ft_memdel((void *)(&(tet->content[i])));
		i++;
	}
	ft_memdel((void **)(&(tet->content)));
	ft_memdel((void **)&tet);
}

t_list		*ft_lstfree(t_list *lst)
{
	t_tetr	*tet;
	t_list	*tmp;

	while (lst)
	{
		tet = (t_tetr*)lst->content;
		tmp = lst->next;
		ft_tetfree(tet);
		ft_memdel((void**)&lst);
		lst = tmp;
	}
	return (NULL);
}

void		ft_last_check(int vars[3], t_list *list)
{
	if (vars[2] != 0 || vars[1] != 20)
	{
		ft_lstfree(list);
		ft_exit_werror("error");
	}
}

t_list		*ft_parse(int fd)
{
	char	*buf;
	int		vars[3];
	t_list	*list;
	t_tetr	*tmp;

	vars[0] = 'A';
	vars[1] = 0;
	buf = (char*)malloc(sizeof(char) * BUF_SIZE);
	list = NULL;
	while ((vars[2] = read(fd, buf, BUF_SIZE)) >= 20)
	{
		vars[1] = vars[2];
		if (!(tmp = ft_prepare_tet(ft_tetrimino_to_bitab(buf), vars[0]++)))
		{
			ft_memdel((void **)&buf);
			ft_lstfree(list);
			ft_exit_werror("error");
		}
		ft_lstadd(&list, ft_lstnew(tmp, sizeof(t_tetr)));
		ft_memdel((void **)&tmp);
	}
	ft_last_check(vars, list);
	ft_memdel((void **)&buf);
	ft_lstrev(&list);
	return (list);
}
