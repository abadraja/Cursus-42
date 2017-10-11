/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abadraja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/29 12:39:53 by abadraja          #+#    #+#             */
/*   Updated: 2017/01/10 10:39:53 by abadraja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

int			ft_getnbr(char *str)
{
	int		res;

	res = 0;
	if (str != NULL && str[0] == '-')
	{
		return (-ft_getnbr(&str[1]));
	}
	while ((*str >= '0') && (*str <= '9'))
	{
		res = (res * 10) + (*str - '0');
		str++;
	}
	return (res);
}
