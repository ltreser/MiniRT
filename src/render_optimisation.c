/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_optimisation.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoth <afoth@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 16:36:36 by afoth             #+#    #+#             */
/*   Updated: 2025/04/17 23:06:53 by afoth            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/miniRT.h"

void	optimise_pixel_rendering(t_rt *rt)
{
	int	i;
	int	error_flag;
	int	*error;

	error_flag = 0;
	error = &error_flag;
	i = 0;
	while (i < rt->obj_count)
	{
		if (rt->obj[i]->visible == 1)
		{
			rt->n_obj = i;
			if (rt->obj[i]->type == SPHERE || rt->obj[i]->type == CYLINDER)
				symplify(rt, error);
			if (*error == 1)
			{
				*error = 0;
				rt->obj[i]->visible = 0;
			}
		}
		i++;
	}
}
//DEL DEbuging plane_ray_intersec scheint zu gehen vl falsche eingabe?
/* Calculating the 2D point on the viewport of a 3d point.
The point has to lay on the screen
The tranformation is done by calculating the distance of the point to
the x and y axis of the viewport
1. Ray is created for the axis
2. Distance to axis is calculated and translated into pixels(dist_up / rt->vp->pixel_w)
ceilf is used to round up(no half pixels)
*/
void	calc_maskpoint_on_vp(t_rt *rt, t_point	*mask_corner, char corner, int *error)
{
	t_vector	vector;
	t_ray		ray;
	t_point		point;

	vector = v_between_two_points_nm(*rt->camera->p, *mask_corner);
	ray.v = &vector;
	ray.p = mask_corner;
	point = plane_ray_intersec(*rt->vp->vp_plane, ray);
	if (isnan(point.x))
	{
		*error = 1;
		return;
	}

	if (corner == 'u')
	{

		ray.v = rt->vp->up;
		ray.p = rt->vp->bottom_left;

		t_float dist_up = distance_p_to_ray(point, ray);

		rt->obj[rt->n_obj]->uvp_x1 = ceilf(dist_up / rt->vp->pixel_w);
		printf("uvp_x1 %i, ", rt->obj[rt->n_obj]->uvp_x1);

		ray.v = rt->vp->right;

		t_float dist_right = distance_p_to_ray(point, ray);
		rt->obj[rt->n_obj]->uvp_y1 = ceilf(dist_right / rt->vp->pixel_h);
		printf("uvp_y1 %i, ", rt->obj[rt->n_obj]->uvp_y1);

	}

	if (corner == 'd')
	{

		ray.v = rt->vp->up;
		ray.p = rt->vp->bottom_left;

		t_float dist_up = distance_p_to_ray(point, ray);
		rt->obj[rt->n_obj]->dvp_x2 = ceilf(dist_up / rt->vp->pixel_w);
		printf("dvp_x2 %i, ", rt->obj[rt->n_obj]->dvp_x2);

		ray.v = rt->vp->right;

		t_float dist_right = distance_p_to_ray(point, ray);
		rt->obj[rt->n_obj]->dvp_y2 = ceilf(dist_right / rt->vp->pixel_h);
		printf("dvp_y2 %i, ", rt->obj[rt->n_obj]->dvp_y2);

	}
}

void	create_sphere_mask(t_rt *rt)
{
	t_float		r;
	t_vector	tmp_u;
	t_vector	tmp_d;
	t_point		p;
	t_vector	up;
	t_vector	right;

	r = rt->obj[rt->n_obj]->sphere->d / 2;
	p = *rt->obj[rt->n_obj]->sphere->p;
	up = *rt->vp->up;
	right = *rt->vp->right;
	tmp_u = v_add_nm(v_mult_scalar_nm(up, r), v_mult_scalar_nm(right, r * -1));
	tmp_d = v_add_nm(v_mult_scalar_nm(up, r * -1), v_mult_scalar_nm(right, r));
	*rt->obj[rt->n_obj]->sphere->u_corner = calc_endpoint_vector(&tmp_u, &p, 1);
	*rt->obj[rt->n_obj]->sphere->d_corner = calc_endpoint_vector(&tmp_d, &p, 1);
}

void	create_cylinder_mask(t_rt *rt)
{
	t_float		r;
	t_vector	tmp_u;
	t_vector	tmp_d;
	t_point		p;
	t_vector	up;
	t_vector	right;

	r = rt->obj[rt->n_obj]->cylinder->d / 2;
	p = *rt->obj[rt->n_obj]->cylinder->p;
	up = *rt->vp->up;
	right = *rt->vp->right;
	tmp_u = v_add_nm(v_mult_scalar_nm(up, r), v_mult_scalar_nm(right, r * -1));
	tmp_d = v_add_nm(v_mult_scalar_nm(up, r * -1), v_mult_scalar_nm(right, r));
	*rt->obj[rt->n_obj]->sphere->u_corner = calc_endpoint_vector(&tmp_u, &p, 1);
	*rt->obj[rt->n_obj]->sphere->d_corner = calc_endpoint_vector(&tmp_d, &p, 1);
}

/* uncoment for mask render points visualing
mlx_pixel_put(rt->mlx->connection,
rt->mlx->window, rt->obj[rt->n_obj]->dvp_x2, rt->obj[rt->n_obj]->dvp_y2,
 0xFFFFFFFF);
mlx_pixel_put(rt->mlx->connection,
rt->mlx->window, rt->obj[rt->n_obj]->uvp_x1, rt->obj[rt->n_obj]->uvp_y1,
 0xFFFFFFFF); */
void	symplify(t_rt *rt, int	*error)
{
	if (rt->obj[rt->n_obj]->type == SPHERE)
	{
		create_sphere_mask(rt);
		calc_maskpoint_on_vp(rt, rt->obj[rt->n_obj]->sphere->u_corner, \
			'u', error);
		calc_maskpoint_on_vp(rt, rt->obj[rt->n_obj]->sphere->d_corner, \
			'd', error);
	}
	else
	{
		create_cylinder_mask(rt);
		calc_maskpoint_on_vp(rt, rt->obj[rt->n_obj]->cylinder->u_corner, \
			'u', error);
		calc_maskpoint_on_vp(rt, rt->obj[rt->n_obj]->cylinder->d_corner, \
			'd', error);
	}
}
