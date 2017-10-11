/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abadraja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/20 16:23:49 by abadraja          #+#    #+#             */
/*   Updated: 2016/11/21 16:37:57 by abadraja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hf.h"

int			ft_lstlen(t_list *list)
{
	int		len;

	len = 0;
	while (list)
	{
		len++;
		list = list->next;
	}
	return (len);
}

void		ft_lstrev(t_list **alst)
{
	t_list	*prev;
	t_list	*curr;
	t_list	*next;

	prev = NULL;
	curr = *alst;
	while (curr != NULL)
	{
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}
	*alst = prev;
}

int			ft_b(char c)
{
	if (c == '#')
		return (1);
	return (0);
}

char		**ft_tetrimino_to_bitab(char *str)
{
	int		i;
	char	**rez;

	i = 0;
	ft_count_elements(str);
	ft_check(str);
	rez = (char**)malloc(sizeof(char*) * 4);
	while (i < 4)
		rez[i++] = (char*)malloc(sizeof(char) * 5);
	i = 0;
	while (i < 4)
	{
		ft_strncpy(rez[i], str + i * 5, 4);
		rez[i][4] = '\0';
		i++;
	}
	return (rez);
}
