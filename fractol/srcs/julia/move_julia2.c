/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_julia2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abadraja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/13 17:04:36 by abadraja          #+#    #+#             */
/*   Updated: 2017/02/13 17:04:38 by abadraja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fractol.h"

void		move_julia_dec(t_fractol *f)
{
	f->julia.max_i = 250;
	expose_hook(f);
}

void		move_julia_inc(t_fractol *f)
{
	f->julia.max_i = 45;
	expose_hook(f);
}
