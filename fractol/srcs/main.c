/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abadraja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 14:11:02 by abadraja          #+#    #+#             */
/*   Updated: 2017/02/13 17:41:24 by abadraja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int			ft_strcomp(char *s1, char *s2)
{
	int			i;
	size_t		k;

	i = 0;
	k = 0;
	while (s1[i] != '\0' && s2[i] != '\0')
	{
		if (s1[i] == s2[i])
			k++;
		i++;
	}
	if (k == ft_strlen(s1))
		return (1);
	return (0);
}

int			analize(char *str)
{
	if (ft_strcomp(str, JULIA))
		return (1);
	if (ft_strcomp(str, MANDELBROT))
		return (1);
	if (ft_strcomp(str, SHIP))
		return (1);
	return (0);
}

void		ft_exit_fwerror(char *text)
{
	ft_putendl(text);
	ft_putendl("-> Mandelbrot Set");
	ft_putendl("-> Julia Set");
	ft_putendl("-> Test Set");
	exit(0);
}

void		start(char *s, t_fractol *f)
{
	ft_putendl("========== Welcome ==========");
	ft_putendl("|      P - Start mouse      |");
	ft_putendl("|      O - Pause mouse      |");
	ft_putendl("|      W ,A,S,D - Move      |");
	ft_putendl("|      1 .. 6 - Colors      |");
	ft_putendl("|         Esc - Exit        |");
	ft_putendl("|      m. wheel - zoom      |");
	ft_putendl("=============================");
	if (ft_strcomp(s, JULIA))
		start_julia(f);
	if (ft_strcomp(s, MANDELBROT))
		start_mandelbrot(f);
	if (ft_strcomp(s, SHIP))
		start_ship(f);
}

int			main(int ac, char **av)
{
	t_fractol f;

	if (ac != 2 || !analize(av[1]))
		ft_exit_fwerror(ERROR);
	start(av[1], &f);
	return (0);
}
