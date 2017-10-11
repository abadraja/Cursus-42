/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abadraja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/20 18:34:33 by abadraja          #+#    #+#             */
/*   Updated: 2016/10/20 18:34:33 by abadraja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*tmp;

	tmp = (t_list *)malloc(sizeof(t_list));
	if (!tmp)
		return (NULL);
	if (!content || !content_size)
	{
		tmp->content = NULL;
		tmp->content_size = 0;
	}
	else
	{
		tmp->content = ft_memalloc(content_size);
		tmp->content = ft_memcpy((tmp->content), content, content_size);
		tmp->content_size = content_size;
	}
	return (tmp);
}
