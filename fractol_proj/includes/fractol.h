/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abadraja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/13 17:45:52 by abadraja          #+#    #+#             */
/*   Updated: 2017/04/27 18:46:20 by abadraja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <mlx.h>
# include <fcntl.h>
# include "../libft/libft.h"
# include "redpallete.h"
# include "keys.h"
# include <math.h>

# define ERROR "Use only one type of fractal from the following:"
# define JULIA "Julia"
# define MANDELBROT "Mandelbrot"
# define TEST "Test"
# define SHIP "Ship"

# define HIGH 500
# define WIDTH 500

# define MAND_CX_MIN -2.5
# define MAND_CX_MAX 1.5
# define MAND_CY_MIN -2.0
# define MAND_CY_MAX 2.0
# define MAND_ESCAPE_RADIUS 2

# define MOTION_NOTIFY 6
# define PTR_MOTION_MASK (1L << 6)

typedef struct	s_color
{
	int			clr[17];
}				t_color;

typedef struct	s_info
{
	void		*mlx;
	void		*win;
	void		*img;
	int			*color;
	char		*str;
	int			endian;
	int			bpp;
	int			sline;
	int			y;
	int			x;
	int			i;
	int			originx;
	int			originy;
}				t_info;

typedef	struct	s_mand
{
	double		pr;
	double		pi;
	double		newre;
	double		newim;
	double		oldre;
	double		oldim;
	double		zoom;
	double		move_x;
	double		move_y;
	long		max_i;
	int			i;
	int			y;
	int			x;
}				t_mand;

typedef	struct	s_julia
{
	double		c_re;
	double		c_im;
	double		newre;
	double		newim;
	double		oldre;
	double		oldim;
	double		zoom;
	double		move_x;
	double		move_y;
	long		max_i;
	int			i;
	int			y;
	int			x;
	int			stop;
}				t_julia;

typedef	struct	s_ship
{
	double		pr;
	double		pi;
	double		newre;
	double		newim;
	double		oldre;
	double		oldim;
	double		zoom;
	double		move_x;
	double		move_y;
	long		max_i;
	int			i;
	int			y;
	int			x;
}				t_ship;

typedef struct	s_mouse
{
	int		x;
	int		y;
	int		but;
}				t_mouse;

typedef struct	s_eco
{
	int		count1;
	int		count2;
}				t_eco;

typedef struct	s_fractol
{
	t_info		info;
	t_mand		mand;
	t_color		color;
	t_mouse		mouse;
	t_eco		eco;
	t_julia		julia;
	t_ship		ship;
}				t_fractol;

void			color_to_black(t_fractol *f);
void			pixel_put(t_fractol *f);
void			pixel_put2(t_fractol *f);
void			pixel_put3(t_fractol *f);
int				expose_hook(t_fractol *f);
void			color_first(t_fractol *f);
void			color_make(t_fractol *f);
void			color_2(t_fractol *f);
void			color_3(t_fractol *f);
void			color_4(t_fractol *f);
void			color_5(t_fractol *f);
void			color_6(t_fractol *f);

int				ft_mand_key_exit(int key, t_fractol *f);
int				ft_mand_mouse_exit(int but, int x, int y, t_fractol *f);
void			prep_var_mandelbrot(t_fractol *f);
void			draw_mandelbrot_ph1(t_fractol *f);
void			draw_mandelbrot_ph2(t_fractol *f);
void			start_mandelbrot(t_fractol *f);
void			draw_mand(t_fractol *f, int i);

void			move_mand_increase(t_fractol *f);
void			move_mand_zoom_plus(t_fractol *f);
void			move_mand_wasd(t_fractol *f, int key);
void			move_mand_zoom_mins(t_fractol *f);

void			prep_var_julia(t_fractol *f);
void			draw_julia_ph2(t_fractol *f);
void			draw_julia_ph1(t_fractol *f);
void			draw_julia(t_fractol *f, int i);
void			start_julia(t_fractol *f);

void			move_julia_inc(t_fractol *f);
void			move_julia_dec(t_fractol *f);
int				ft_mouse_motion(int x, int y, t_fractol *f);
void			move_julia_wasd(t_fractol *f, int key);
int				ft_julia_key_exit(int key, t_fractol *f);
int				ft_julia_mouse_exit(int but, int x, int y, t_fractol *f);
void			move_julia_zoom_mins(t_fractol *f);
void			move_julia_zoom_plus(t_fractol *f);
void			ft_exit2(t_fractol *f, int key);

void			start_ship(t_fractol *f);
void			draw_ship_ph1(t_fractol *f);
void			draw_ship_ph2(t_fractol *f);
void			move_ship_wasd(t_fractol *f, int key);
void			move_ship_zoom_plus(t_fractol *f);
void			move_ship_zoom_mins(t_fractol *f);
void			move_ship_increase(t_fractol *f);
void			prep_var_ship(t_fractol *f);
void			draw_ship(t_fractol *f, int i);
int				ft_ship_key_exit(int key, t_fractol *f);
int				ft_ship_mouse_exit(int but, int x, int y, t_fractol *f);

#endif
