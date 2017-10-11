/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abadraja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/20 18:34:43 by abadraja          #+#    #+#             */
/*   Updated: 2016/10/20 18:34:43 by abadraja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strtrim(char const *s)
{
	int		i;
	int		j;
	int		k;
	char	*tmp;

	if (!s)
		return (NULL);
	i = -1;
	j = ft_strlen((char *)s);
	while (s[j - 1] == ' ' || s[j - 1] == '\n' || s[j - 1] == '\t')
		j--;
	while (s[++i] == ' ' || s[i] == '\n' || s[i] == '\t')
		j--;
	if (j < 1)
		j = 0;
	tmp = (char *)malloc(sizeof(char) * (j + 1));
	if (!tmp)
		return (NULL);
	k = 0;
	while (k < j)
		tmp[k++] = s[i++];
	tmp[k] = '\0';
	return (tmp);
}
