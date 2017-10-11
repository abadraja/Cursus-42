/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abadraja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/20 18:34:41 by abadraja          #+#    #+#             */
/*   Updated: 2016/10/20 18:34:41 by abadraja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnew(size_t size)
{
	char	*rez;

	if (!(rez = (char*)malloc(size + 1)))
		return (NULL);
	ft_bzero(rez, size + 1);
	return (rez);
}
