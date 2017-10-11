/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abadraja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 17:31:16 by abadraja          #+#    #+#             */
/*   Updated: 2017/02/13 17:07:16 by abadraja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void		pixel_put(t_fractol *f)
{
	int		offset;

	offset = f->info.x * 4;
	offset += f->info.y * f->info.sline;
	*(int*)(f->info.str + offset) = f->info.color[f->mand.i];
}

void		pixel_put2(t_fractol *f)
{
	int		offset;

	offset = f->info.x * 4;
	offset += f->info.y * f->info.sline;
	*(int*)(f->info.str + offset) = f->info.color[f->julia.i];
}

void		pixel_put3(t_fractol *f)
{
	int		offset;

	offset = f->info.x * 4;
	offset += f->info.y * f->info.sline;
	*(int*)(f->info.str + offset) = f->info.color[f->ship.i];
}

int			expose_hook(t_fractol *f)
{
	mlx_clear_window(f->info.mlx, f->info.win);
	pixel_put(f);
	mlx_put_image_to_window(f->info.mlx, f->info.win, f->info.img, 0, 0);
	return (0);
}
