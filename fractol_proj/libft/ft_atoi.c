/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abadraja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/20 18:34:30 by abadraja          #+#    #+#             */
/*   Updated: 2016/10/20 18:34:30 by abadraja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		if_space(char c)
{
	if (c == ' ' || c == '\t' || c == '\n' || c == '\r' || c == '\f'
			|| c == '\v')
		return (1);
	return (0);
}

int				ft_atoi(const char *str)
{
	int			i;
	int			neg;
	int			rez;

	i = 0;
	neg = 1;
	rez = 0;
	while (if_space(str[i]))
		i++;
	if ((str[i] == '-' || str[i] == '+') && str[i + 1] >= '0' &&
		str[i + 1] <= '9')
	{
		if (str[i] == '-')
			neg = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		rez *= 10;
		rez += str[i] - '0';
		i++;
	}
	return (neg * rez);
}
