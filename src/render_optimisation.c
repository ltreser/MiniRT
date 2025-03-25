/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_optimisation.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoth <afoth@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 16:36:36 by afoth             #+#    #+#             */
/*   Updated: 2025/03/25 14:40:51 by afoth            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/miniRT.h"

//DEL TEST!!!!

void	optimise_pixel_rendering(t_rt *rt)
{
	int	i;
	int error_flag;
	int	*error;

	error_flag = 0;
	error = &error_flag;
	i = 0;
	// printf("OPTIMIZE RENDER LOOP\n");//DEL
	// printf("count %i\n", rt->obj_count);//DEL

	while(i < rt->obj_count)
	{
		// printf("LOOP\n");//DEL
		// printf("I %i count %i\n", i, rt->obj_count);
		if(rt->obj[i]->visible == 1)
		{
			rt->n_obj = i;
			if(rt->obj[i]->type == SPHERE || rt->obj[i]->type == CYLINDER)
				symplify(rt, error);
			if(*error == 1)
			{
				*error = 0;
				rt->obj[i]->visible = 0;
			}
		}
		i++;
	}
	/*optimize obj
	how do I get access to the obj, how do I know wich type?
	Where do I store the squares?
	How do I know the coordinats of the squares?

	1. Calculate the coordinates of the covering square
	2. Create a vector betweem square and camera.
	3. Calculate impact point on viewport
	4. Translate impact point into pixel coordinates
		-calculate pixel size
			pixel height = rt->vp->width/rt->mlx->width
	5. Save the coordinates
	*/
	//go throught obj
	//if sphere ->

}
//DEL DEbuging plane_ray_intersec scheint zu gehen vl falsche eingabe?
void	calc_maskpoint_on_vp(t_rt *rt, t_point	*mask_corner, char corner, int *error)
{
	t_vector	vector;
	t_ray		ray;
	t_point		point;

	vector = v_between_two_points_nm(*rt->camera->p, *mask_corner);//VEktor correct
	ray.v = &vector;
	ray.p = mask_corner;
	point = plane_ray_intersec(*rt->vp->vp_plane, ray);
	if(isnan(point.x))
	{
		*error = 1;
		return;
	}

	if (corner == 'u')
	{

		ray.v = rt->vp->up;
		ray.p = rt->vp->bottom_right;

		float dist_up = distance_p_to_ray(point, ray);

		rt->obj[rt->n_obj]->uvp_x1 = ceilf(dist_up / rt->vp->pixel_w);

		ray.v = rt->vp->right;

		float dist_right = distance_p_to_ray(point, ray);
		rt->obj[rt->n_obj]->uvp_y1 = ceilf(dist_right / rt->vp->pixel_h);
	}

	if (corner == 'd')
	{

		ray.v = rt->vp->up;
		ray.p = rt->vp->bottom_right;

		float dist_up = distance_p_to_ray(point, ray);
		rt->obj[rt->n_obj]->dvp_x2 = ceilf(dist_up / rt->vp->pixel_w);

		ray.v = rt->vp->right;

		float dist_right = distance_p_to_ray(point, ray);
		rt->obj[rt->n_obj]->dvp_y2 = ceilf(dist_right / rt->vp->pixel_h);
	}
}
/* 	if(corner == 'u')
	{
		//grade aufstellen x achse p(r) + x * v(a) rt->vp->bottom_right + x * rt->vp->right
		//grade aufstellen y achse p(r) + x * v(a) rt->vp->bottom_right + x * rt->vp->up
		//y = rt->vp->right * (point -  rt->vp->bottom_right)/ rt->vp->right
		//x = rt->vp->up * (point -  rt->vp->bottom_right)/ rt->vp->up

		//abstand x achse zu punkt = y
		//ergebnis float cast zu int, wird immer abgerundet ceilf() immer auf
		ray.v = rt->vp->up;
		ray.p = rt->vp->bottom_right;
		rt->obj[rt->n_obj]->uvp_x1 = ceilf(distance_p_to_ray(point, ray)/rt->vp->pixel_w);
		ray.v = rt->vp->right;
		rt->obj[rt->n_obj]->uvp_y1 = ceilf(distance_p_to_ray(point, ray)/rt->vp->pixel_h);
		// rt->obj[rt->n_obj]->uvp_x1 = v_len(v_product_nm(*rt->vp->up, pp_sub_v_nm(point, *rt->vp->bottom_right)))/ v_len(*rt->vp->up);
		// rt->obj[rt->n_obj]->uvp_y1 = v_len(v_product_nm(*rt->vp->right, pp_sub_v_nm(point, *rt->vp->bottom_right)))/ v_len(*rt->vp->right);
	}
	if(corner == 'd')
	{
		ray.v = rt->vp->up;
		ray.p = rt->vp->bottom_right;
		rt->obj[rt->n_obj]->uvp_x1 = ceilf(distance_p_to_ray(point, ray)/rt->vp->pixel_w);
		ray.v = rt->vp->right;
		rt->obj[rt->n_obj]->uvp_y1 = ceilf(distance_p_to_ray(point, ray)/rt->vp->pixel_h);
		// rt->obj[rt->n_obj]->dvp_x2 = v_len(v_product_nm(*rt->vp->up, pp_sub_v_nm(point, *rt->vp->bottom_right)))/ v_len(*rt->vp->up);
		// rt->obj[rt->n_obj]->dvp_y2 = v_len(v_product_nm(*rt->vp->right, pp_sub_v_nm(point, *rt->vp->bottom_right)))/ v_len(*rt->vp->right);
	}
} */
/*Calculation of the points of a square mask that will
represent the square on the viewport.
Only where the mask is, pixels are renderd

Upper Corner = normalized Vektor up * r + normalized Vektor right * (r * -1)
Lower Corner = normalized Vektor up * (r -1) + normalized Vektor right * r
This creates the cordinates of a square with sidelenght r in 3D Space paralle to
the viewport
*/
void	create_sphere_mask(t_rt *rt)
{
	float		r;
	// float		x;
	// float		y;
	t_vector	tmp_u;
	t_vector	tmp_d;
	t_point		p;
	t_vector	up;
	t_vector	right;

	// x = rt->obj[rt->n_obj]->sphere->p->x;
	// y = rt->obj[rt->n_obj]->sphere->p->y;
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
	float		r;
	// float		x;
	// float		y;
	t_vector	tmp_u;
	t_vector	tmp_d;
	t_point		p;
	t_vector	up;
	t_vector	right;

	// x = rt->obj[rt->n_obj]->cylinder->p->x;
	// y = rt->obj[rt->n_obj]->cylinder->p->y;
	r = rt->obj[rt->n_obj]->cylinder->d / 2;
	p = *rt->obj[rt->n_obj]->cylinder->p;
	up = *rt->vp->up;
	right = *rt->vp->right;
	tmp_u = v_add_nm(v_mult_scalar_nm(up, r), v_mult_scalar_nm(right, r * -1));
	tmp_d = v_add_nm(v_mult_scalar_nm(up, r * -1), v_mult_scalar_nm(right, r));
	*rt->obj[rt->n_obj]->sphere->u_corner = calc_endpoint_vector(&tmp_u, &p, 1);
	*rt->obj[rt->n_obj]->sphere->d_corner = calc_endpoint_vector(&tmp_d, &p, 1);
	//DEL Safety comment, changes above
	// rt->obj[rt->n_obj]->cylinder->u_corner = calc_endpoint_vector(v_add_nm(v_mult_scalar_nm(up, r), v_mult_scalar_nm(right, r * -1), p, 1));
	// rt->obj[rt->n_obj]->cylinder->d_corner = calc_endpoint_vector(v_add_nm(v_mult_scalar_nm(up, r * -1), v_mult_scalar_nm(right, r), p, 1));
}

void	symplify(t_rt *rt, int	*error)
{

	if (rt->obj[rt->n_obj]->type == SPHERE)
	{
		create_sphere_mask(rt);
		calc_maskpoint_on_vp(rt, rt->obj[rt->n_obj]->sphere->u_corner, 'u', error);
		calc_maskpoint_on_vp(rt, rt->obj[rt->n_obj]->sphere->d_corner, 'd', error);

		mlx_pixel_put(rt->mlx->connection, rt->mlx->window, rt->obj[rt->n_obj]->dvp_x2, rt->obj[rt->n_obj]->dvp_y2, 0xFFFFFFFF);
		mlx_pixel_put(rt->mlx->connection, rt->mlx->window, rt->obj[rt->n_obj]->uvp_x1, rt->obj[rt->n_obj]->uvp_y1, 0xFFFFFFFF);
	}
	else
	{
		create_cylinder_mask(rt);
		calc_maskpoint_on_vp(rt, rt->obj[rt->n_obj]->cylinder->u_corner, 'u', error);
		calc_maskpoint_on_vp(rt, rt->obj[rt->n_obj]->cylinder->d_corner, 'd', error);
	}
}
