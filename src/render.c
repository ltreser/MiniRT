/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoth <afoth@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 19:04:32 by afoth             #+#    #+#             */
/*   Updated: 2025/04/22 16:25:42 by afoth            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/miniRT.h"

float	obj_type_to_render(t_rt *rt, t_ray *ray, int i)
{
	float	tmp_t;

	tmp_t = -1;
	if (rt->obj[i]->type == PLANE)
		tmp_t = plane_ray_calc_t(*rt->obj[i]->pl, *ray);
	if (rt->obj[i]->type == SPHERE)
		tmp_t = sphere_intersection(rt->obj[i]->s, ray);
	if (rt->obj[i]->type == CYLINDER)
		tmp_t = cylinder_intersection(*rt->obj[i]->cyl, *ray);
	return (tmp_t);
}

// mlx_pixel_put(rt->mlx->connection, rt->mlx->window,
// x, SCREEN_HEIGHT - 1 - y , 0x0000FF);//BACKGROUND
void	put_pixel_vp(t_rt *rt, float t, int min_t_obj)
{
	t_color	color;

	if (min_t_obj < 0)
	{
		return ;
	}
	rt->n_obj = min_t_obj;
	color = get_color(rt, min_t_obj);
	color = lighting(rt, *(rt->obj[min_t_obj]), color, t);
	*(unsigned int *)(rt->mlx->pixel_adress + \
				((SCREEN_HEIGHT - 1 - rt->vp->pixel_y)
				* rt->mlx->line_len + rt->vp->pixel_x * rt->mlx->bpp
				/ 8)) = color_to_hex(color);
}

void	obj_render_loop(t_rt *rt, t_ray *ray, int x, int y)
{
	int		i;
	int		min_t_obj;
	t_float	t;
	t_float	tmp_t;

	i = 0;
	t = MAX_RENDER;
	min_t_obj = -1;
	while (i < rt->obj_count)
	{
		if (rt->obj[i]->visible == 1)
		{
			tmp_t = obj_type_to_render(rt, ray, i);
			if (tmp_t > EPSILON && tmp_t < t)
			{
				t = tmp_t;
				min_t_obj = i;
			}
		}
		i++;
	}
	put_pixel_vp(rt, t, min_t_obj);
}

/* Main loop that sends out a ray for every pixel
Starts in the upper left corner. (xmin ymax)
Warning! in the mlx lib (rendering) y is inverted
so y = 0 is the the highest up.
Our coordinate system 0.0 for the viewport is still
at the bottom left corner for ease of thinking.
Rendering starts at the bootm left
*/
void	render_loop(t_rt *rt)
{
	t_vector	start_vec;

	create_render_ray(rt);
	start_vec = *rt->vp->render_ray->v;
	rt->vp->pixel_y = 0;
	while (rt->vp->pixel_y < SCREEN_HEIGHT - 1)
	{
		rt->vp->pixel_x = 0;
		while (rt->vp->pixel_x < SCREEN_WIDTH)
		{
			obj_render_loop(rt, rt->vp->render_ray, rt->vp->pixel_x,
				rt->vp->pixel_y);
			*rt->vp->render_ray->v = v_add_nm(*rt->vp->render_ray->v,
					*rt->vp->pixel_v_x);
			rt->vp->pixel_x++;
		}
		*rt->vp->render_ray->v = start_vec;
		rt->vp->pixel_y++;
		*rt->vp->render_ray->v = v_add_nm(*rt->vp->render_ray->v,
				v_mult_scalar_nm(*rt->vp->pixel_v_y, rt->vp->pixel_y));
	}
	mlx_put_image_to_window(rt->mlx->connection, rt->mlx->window, rt->mlx->img,
		0, 0);
}
