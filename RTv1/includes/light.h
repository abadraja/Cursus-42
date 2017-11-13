/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abadraja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 18:08:02 by abadraja          #+#    #+#             */
/*   Updated: 2017/03/03 18:08:03 by abadraja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIGHT_T
# define LIGHT_T

# include "rtv1.h"

typedef struct 	s_light
{
	t_vect		pos;
	t_colors	col;
}				t_light;

#endif
