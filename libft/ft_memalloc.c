/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abadraja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/20 18:34:34 by abadraja          #+#    #+#             */
/*   Updated: 2016/10/20 18:34:34 by abadraja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memalloc(size_t size)
{
	unsigned char	*mem;

	mem = (unsigned char*)malloc(sizeof(unsigned char) * size);
	if (mem && size)
	{
		ft_bzero(mem, size);
		return ((void *)mem);
	}
	return ((void *)0);
}
