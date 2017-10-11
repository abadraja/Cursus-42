/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abadraja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/28 15:13:10 by abadraja          #+#    #+#             */
/*   Updated: 2017/02/04 16:10:20 by abadraja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void		color_to_black(t_fractol *f)
{
	int	i;

	i = 0;
	while (i != 350)
	{
		f->info.color[i] = BLACK;
		i++;
	}
}

void		color_first(t_fractol *f)
{
	f->color.clr[0] = CL1;
	f->color.clr[1] = CL2;
	f->color.clr[2] = CL3;
	f->color.clr[3] = CL4;
	f->color.clr[4] = CL5;
	f->color.clr[5] = CL6;
	f->color.clr[6] = CL7;
	f->color.clr[7] = CL8;
	f->color.clr[8] = CL9;
	f->color.clr[9] = CL10;
	f->color.clr[10] = CL11;
	f->color.clr[11] = CL12;
	f->color.clr[12] = CL13;
	f->color.clr[13] = CL14;
	f->color.clr[14] = CL15;
	f->color.clr[15] = CL16;
	f->color.clr[16] = CL17;
}

void		color_make(t_fractol *f)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < 350)
	{
		if (j > 16)
			j = 0;
		f->info.color[i] = f->color.clr[j];
		i++;
		j++;
	}
}
