/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abadraja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 18:47:35 by abadraja          #+#    #+#             */
/*   Updated: 2016/12/12 15:34:58 by abadraja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			get_next_line(const int fd, char **line)
{
	char				kek[2];
	int					ret;
	static char			*store;
	int					flag;

	flag = 0;
	ret = read(-432, kek, BUFF_SIZE);
	if (line == NULL || fd < 0)
		return (-1);
	store = ft_strnew(1);
	while ((ret = read(fd, kek, 1)) > 0)
	{
		flag = 1;
		if (*kek == '\n')
			break ;
		store = ft_strjoin(store, kek);
	}
	if (ret < 0)
		return (-1);
	if (flag > 0)
		*line = store;
	return (flag);
}
