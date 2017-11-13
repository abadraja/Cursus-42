/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abadraja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 17:11:08 by abadraja          #+#    #+#             */
/*   Updated: 2017/02/28 17:11:26 by abadraja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

void		prepare_mlx(t_rtv1 *r)
{
	r->info.mlx = mlx_init();
	r->info.win = mlx_new_window(r->info.mlx, WIDTH, HEIGHT, "RTv1");
	r->info.img = mlx_new_image(r->info.mlx, WIDTH, HEIGHT);
	r->info.str = ft_strnew(1);
	r->info.str = mlx_get_data_addr(r->info.img, &r->info.bpp,
		&r->info.sline, &r->info.endian);
	r->info.color = 0x00FF0000;
}

void		delete_standard(void *object, size_t size)
{
	(void)size;
	free(object);
}

t_list		*ft_elementat(t_list *lst, int index)
{
	t_list	*tmp;
	int i;

	i = 0;
	tmp = lst;
	while (tmp && i < index)
	{
		tmp = tmp->next;
		i++;
	}
	return (tmp);
}

int 		winningObjectIndex(t_list *object_intersections, int size)
{
	// return the index of the winning intersection
	int 	 	index_of_minimum_value;
	t_list		*save1;
	t_list		*save2;
	int 		index;
	
	save1 = object_intersections;
	save2 = object_intersections;
	double		*l = save1->content;
	double 		*d = save2->content;

	if (size == 0)
		return -1; // if there are no intersections
	else if (size == 1)
		if (*l > 0)
			return 0; // if that intersection is greater than zero then its our index of minimum value
		else
			return -1; // otherwise the only intersection value is negative
	else
	{
		// otherwise there is more than one intersection
		// first find the maximum value
		double max = 0;
		while (save1)
		{
			d = save1->content;
			// printf("d = %f; \n", *d);
			if (max < *d)
				max = *d;
			save1 = save1->next;
		}
		// then starting from the maximum value find the minimum positive value
		if (max > 0)
		{
			index = 0;
			while (save2)
			{

				d = save2->content;
				// we only want positive intersections
				if (*d > 0 && *d <= max)
				{
					max = *d;
					index_of_minimum_value = index;
				}
				save2 = save2->next;
				index++;
			}
			return index_of_minimum_value;
		}
		else
		{
			// ft_putstr("b");
			return -1; // all the intersections were negative
		}
	}
}

void		test(t_rtv1 *r)
{
	double 		aspectratio = (double)WIDTH / (double)HEIGHT;
	double		xamnt;
	double		yamnt;
	t_vect		x;
	t_vect		y;
	t_vect		z;
	t_vect		o;
	t_vect		look_at;
	t_vect		diff_btw;
	t_vect		campos;
	t_vect		camdir;
	t_vect		camright;
	t_vect		camdown;
	t_camera	scene_cam;
	t_colors	white_light;
	t_colors	green;
	t_colors	gray;
	t_colors	black;
	t_colors	maroon;
	t_vect		light_position;
	t_vect		cam_ray_origin;
	t_vect		cam_ray_direction;
	t_light		scene_light;
	t_ray		cam_ray;
	t_sphere	scene_sphere;
	t_plane		scene_plane;
	t_list		*intersections;
	//t_object			scene_objects;
	t_list		*scene_objects;

	scene_objects = NULL;
	
	o = vect_3params(0, 0, 0);
	x = vect_3params(1, 0, 0);
	y = vect_3params(0, 1, 0);
	z = vect_3params(0, 0, 1);
	look_at = vect_zero();
	campos = vect_3params(3, 1.5, -4);
	diff_btw = vect_3params(campos.x - look_at.x,
		campos.y - look_at.y, campos.z - look_at.z);
	camdir = vect_normalize(vect_negative(diff_btw));
	camright = vect_normalize(vect_cross_prod(y, camdir));
	camdown = vect_cross_prod(camright, camdir);
	scene_cam = cam_2params(campos, camdir, camright, camdown);

	white_light = color_4param(1.0, 1.0, 1.0, 0);
	green = color_4param(0.5, 1.0, 0.5, 0.3);
	gray = color_4param(0.5, 0.5, 0.5, 0);
	black = color_4param(0.0, 0.0, 0.0, 0);
	maroon = color_4param(0.5, 0.25, 0.25, 0);

	light_position = vect_3params(-7, 10, -10);
	scene_light = light_2param(light_position, white_light);

	// scene objects
	scene_sphere = sphere_2param(o, 1, green);
	scene_plane = plane_3param(y, -1, maroon);

	int 	sc_objs_cnt;

	sc_objs_cnt = 0;

	ft_lstadd(&scene_objects, ft_lstnew(&scene_plane, sizeof(t_plane)));
	sc_objs_cnt++;
	ft_lstadd(&scene_objects, ft_lstnew(&scene_sphere, sizeof(t_sphere)));
	sc_objs_cnt++;
	prepare_mlx(r);
	// what_igo(r);
	printf("camdown.x = %f, camdown.y = %f, camdown.z = %f\n", camdown.x, camdown.y, camdown.z);


	r->eco.i = 0;
	while (r->eco.i < WIDTH)
	{
		r->eco.j = 0;
		while (r->eco.j < HEIGHT)
		{

			// start with no anti-aliasing
			if (WIDTH > HEIGHT)
			{
				// the image is wider that it is tall
				xamnt = ((r->eco.i + 0.5) / WIDTH) * aspectratio -
				((WIDTH - HEIGHT) / (double)HEIGHT / 2);
				yamnt = ((HEIGHT - r->eco.j) + 0.5) / HEIGHT;
			}
			else 
				if (HEIGHT / WIDTH)
				{
					// the imager is taller that it is wide
					xamnt = (r->eco.i + 0.5) / WIDTH;
					yamnt = (((HEIGHT - r->eco.j) + 0.5) / HEIGHT) /
					aspectratio - (((HEIGHT - WIDTH) / (double)WIDTH) / 2);
				}
				else
				{
					// the image is square`
					xamnt = (r->eco.i + 0.5) / WIDTH;
					yamnt = ((HEIGHT - r->eco.j) + 0.5) / HEIGHT;
				}

			cam_ray_origin = scene_cam.pos;
			cam_ray_direction = vect_normalize(vect_add(camdir, vect_add(vect_mult(camright, xamnt - 0.5), vect_mult(camdown, yamnt - 0.5))));
			cam_ray = ray_2params(cam_ray_origin, cam_ray_direction);

			t_list		*tmp_sc_obj = scene_objects;

			while (tmp_sc_obj)
			{
				if (LCONT(tmp_sc_obj, t_plane*)->type == T_PLANE)
				{
					double keks = plane_findIntersection(cam_ray, LCONT(tmp_sc_obj, t_plane*));
					ft_lstadd(&intersections, ft_lstnew((void *)&keks, sizeof(double)));
					double *kekosimus1 = intersections->content;
					// printf(" kek1 = %f; \n", *kekosimus1);
				}
				else if (LCONT(tmp_sc_obj, t_sphere*)->type == T_SPHERE)
				{
					double keks2 = shpere_findIntersection(cam_ray, LCONT(tmp_sc_obj, t_sphere*));
					// printf(" keks = %f;", keks2);
					ft_lstadd(&intersections, ft_lstnew((void *)&keks2, sizeof(double)));
					double *kekosimus2 = intersections->content;
					// printf("kek2 = %f; \n", *kekosimus2);
				}
				tmp_sc_obj = tmp_sc_obj->next;
			}
			int index_of_winning_object = winningObjectIndex(intersections, sc_objs_cnt);
			printf(" %d", index_of_winning_object);
			if ((r->eco.i > 200 && r->eco.i < 300) && (r->eco.j > 200 && r->eco.j < 300))
			{
				r->info.x = r->eco.i;
				r->info.y = r->eco.j;
				pixel_put(r);
			}
			r->eco.j++;
		}
		r->eco.i++;
	}
	expose_hook(r);
	//mlx_mouse_hook(r->info.win, ft_mand_mouse_exit, r);
	mlx_key_hook(r->info.win, ft_key_hook, r);
	mlx_loop(r->info.mlx);
}

int			main(int ac, char **av)
{
	// emil();
	// return (0);

	t_rtv1		rtv1;

	ft_putnbr(ac);
	ft_putendl(av[0]);
	test(&rtv1);	
	return (0);
}
