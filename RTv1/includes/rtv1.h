/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abadraja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 17:11:44 by abadraja          #+#    #+#             */
/*   Updated: 2017/02/28 17:11:50 by abadraja         ###   ########.fr       */
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
# include <math.h>

# include "keys.h"
# include "redpallete.h"
# include "vect.h"
# include "ray.h"
# include "camera.h"
# include "colors.h"
# include "light.h"
# include "sphere.h"
# include "object.h"
# include "plane.h"

# define HEIGHT 150
# define WIDTH 170

#define T_PLANE		0
#define T_SPHERE	1

# define MOTION_NOTIFY 6
# define PTR_MOTION_MASK (1L << 6)

# define LCONT(node, t_type) ((t_type)((node)->content))
# define LSTR(node) LCONT(node, char*)

typedef struct		s_intersections
{
	double					content;
	struct s_intersections	*next;
}					t_intersections;

typedef struct 		s_scene_objects
{
	t_sphere				spheres;
	t_plane					planes;
	struct s_scene_objects 	*next;
}					t_scene_objects;



typedef struct	s_info
{
	void		*mlx;
	void		*win;
	void		*img;
	int			color;
	char		*str;
	int			endian;
	int			bpp;
	int			sline;
	int			y;
	int			x;
	int			i;
}				t_info;

typedef	struct  s_eco
{
	int			i;
	int			j;
}				t_eco;


typedef	struct  s_rtv1
{
	t_info		info;
	t_eco		eco;
	t_vect		vect;
	t_ray		ray;
	t_camera	cam;
	t_colors	colors;
	t_light		light;
	t_object 	object;
	t_sphere 	sphere;
	t_plane 	plane;
}				t_rtv1;

int				expose_hook(t_rtv1 *r);
void			pixel_put(t_rtv1 *r);
int				ft_key_hook(int key, t_rtv1 *r);

t_vect			vect_zero();
t_vect			vect_3params(double i, double j, double k);
double			vect_magnitude(t_vect v);
t_vect			vect_normalize(t_vect v);
t_vect			vect_negative(t_vect v);
double			vect_dot_prod(t_vect v1, t_vect v2);
t_vect			vect_cross_prod(t_vect v1, t_vect v2);
t_vect			vect_add(t_vect v1, t_vect v);
t_vect			vect_mult(t_vect v, double scalar);
// double			get_vect_x(t_vect *r);
// double			get_vect_y(t_vect *r);
// double			get_vect_z(t_vect *r);

t_ray			ray_zero();
t_ray			ray_2params(t_vect o, t_vect d);

t_camera		cam_zero();
t_camera		cam_2params(t_vect p, t_vect di,
	t_vect right, t_vect d);
t_vect			get_cam_pos(t_rtv1 *r);
t_vect			get_cam_dir(t_rtv1 *r);
t_vect			get_cam_right(t_rtv1 *r);
t_vect			get_cam_down(t_rtv1 *r);

t_colors		color_zero();
t_colors		color_4param(double r, double g, double b, double sp);
double			set_color_red(t_colors col, double val);
double			set_color_green(t_colors col, double val);
double			set_color_blue(t_colors col, double val);
double			set_color_sp(t_colors col, double val);

t_light			light_zero();
t_light			light_2param(t_vect p, t_colors d);

t_sphere		sphere_zero();
t_sphere		sphere_2param(t_vect c, double r, t_colors d);
t_vect			shpere_get_normal_at(t_vect point, t_vect *center);
double			shpere_findIntersection(t_ray ray, t_sphere *center);

t_colors		get_ObjectColor();
double			obj_findIntersection(t_ray ray);

t_plane			plane_zero();
t_plane			plane_3param(t_vect c, double r, t_colors d);
double			plane_findIntersection(t_ray ray, t_plane *plane);
t_vect			getNormalAt(t_vect point, t_plane plane);
#endif
