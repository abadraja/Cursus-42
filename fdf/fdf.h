/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abadraja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/28 15:48:38 by abadraja          #+#    #+#             */
/*   Updated: 2017/01/10 10:28:41 by abadraja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# define BUFF_SIZE 32

# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include <stdio.h>
# include <mlx.h>
# include <fcntl.h>
# include "libft/libft.h"

# define PPAP "Pen Pineapple Apple Pen!"
# define WIDTH 800
# define HEIGHT 800
# define WHITE 0x00FFFFFF
# define BLACK 0x00000000
# define MAG 0.105
# define K 100000

typedef struct	s_info
{
	void	*mlx;
	void	*win;
	int		*x;
	int		*y;
	int		*z;
	int		color;
	float	coss;
	float	sinn;
}				t_info;

typedef	struct	s_map
{
	int		**kek;
	int		rows;
	int		cols;
	int		cnt;
}				t_map;

typedef struct	s_eco
{
	float	space;
	float	cos_angle;
	float	sin_angle;
	int		i;
	int		j;
	int		savex0;
	int		savex1;
	int		savey0;
	int		savey1;
	int		dx;
	int		dy;
	int		err;
	int		sx;
	int		sy;
	int		e2;
	int		x;
	int		y;
	int		zoom;
}				t_eco;

typedef	struct	s_draw
{
	int			**x_iso;
	int			**y_iso;
}				t_draw;

typedef struct	s_fdf
{
	t_info		*info;
	t_draw		*draw;
	t_eco		*eco;
	t_map		*map;
}				t_fdf;

t_fdf			*calc_eco(t_fdf *fdf);
t_fdf			*mal_draw(t_fdf *fdf);
t_fdf			*mal_draw2(t_fdf *fdf);
int				how_much(char *str);
void			prep_win(t_fdf *fdf);
void			eval(t_fdf *fdf);
void			use_gnl(int fd, t_map *map, char **av);
void			inc_xyz(int x, int y, t_map *map);
void			draw_dots(t_fdf *fdf);
void			draw_lines(t_fdf *fdf);
void			ft_exit2(int keycode, t_fdf *fdf);
void			put_toleft(t_fdf *fdf, int i, int j);
void			put_todown(t_fdf *fdf, int i, int j);
t_fdf			*savein1(t_fdf *fdf, int i, int j);
t_fdf			*saveout1(t_fdf *fdf, int i, int j);
t_fdf			*ecospace1(t_fdf *fdf, int i, int j);
t_fdf			*savein2(t_fdf *fdf, int i, int j);
t_fdf			*saveout2(t_fdf *fdf, int i, int j);
void			draw_plus_sinn(t_fdf *fdf);
void			draw_minus_sinn(t_fdf *fdf);
void			draw_plus_coss(t_fdf *fdf);
void			draw_minus_coss(t_fdf *fdf);
void			draw_key_right(t_fdf *fdf);
void			draw_key_up(t_fdf *fdf);
void			draw_key_left(t_fdf *fdf);
void			draw_key_down(t_fdf *fdf);
void			draw_zoomin(t_fdf *fdf);
void			draw_zoomout(t_fdf *fdf);
void			draw_18(t_fdf *fdf);
void			draw_19(t_fdf *fdf);
void			draw_colorpp(t_fdf *fdf);
void			draw_colormm(t_fdf *fdf);
void			draw_leg(t_fdf *fdf);

#endif
