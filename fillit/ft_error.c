/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abadraja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 16:23:37 by abadraja          #+#    #+#             */
/*   Updated: 2016/11/21 16:37:14 by abadraja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hf.h"

void		ft_exit_werror(char *text)
{
	ft_putstr(text);
	ft_putchar('\n');
	exit(0);
}

void		ft_check(char *str)
{
	int		i;
	int		conex;

	conex = 0;
	i = -1;
	while (str[++i] != '\0')
	{
		if (ft_b(str[i]))
		{
			if (ft_b(str[i + 1]))
				conex++;
			if (ft_b(str[i - 1]))
				conex++;
			if (ft_b(str[i + 5]))
				conex++;
			if (ft_b(str[i - 5]))
				conex++;
		}
	}
	if (conex == 6 || conex == 8)
		return ;
	ft_exit_werror("error");
}

int			ft_count_elements(char *str)
{
	int		i;
	int		emp;
	int		blocks;

	emp = 0;
	i = 0;
	blocks = 0;
	while (i < 20)
	{
		if (str[i] == '#')
			blocks++;
		else if (str[i] == '.')
			emp++;
		i++;
	}
	if (blocks != 4 || emp != 12)
		ft_exit_werror("error");
	return (0);
}
