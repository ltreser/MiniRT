/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_optimisation.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoth <afoth@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 16:36:36 by afoth             #+#    #+#             */
/*   Updated: 2025/03/20 17:36:12 by afoth            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/miniRT.h"

//DEL TEST!!!!

void	optimise_pixel_rendering(t_rt *rt)
{
	int	i;

	i = 0;
	while(i < rt->obj_count)
	{
		printf("OPTIMIZE RENDER LOOP\n");//DEL
		if(rt->obj[i]->visible == 1)
		{
			// if(rt->obj[i]->type == PLANE)
				// continue;
			rt->n_obj = i;
			if(rt->obj[i]->type == SPHERE)
			{
				printf("SPHERE RENDER\n");//DEL
				symplify_sphere(rt);

				mlx_pixel_put(rt->mlx->connection, rt->mlx->window, rt->obj[rt->n_obj]->uvp_x1, rt->obj[rt->n_obj]->uvp_y1, 0xFFFFFFFF);
				mlx_pixel_put(rt->mlx->connection, rt->mlx->window, rt->obj[rt->n_obj]->dvp_x2, rt->obj[rt->n_obj]->dvp_y2, 0xFFFFFFFF);

			}

			//if(rt->obj[i]->type == CYLINDER)
				//simplify_cylinder(rt);
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

void	calc_maskpoint_on_vp(t_rt *rt, t_point	*mask_corner, char corner)
{
	t_vector	vector;
	t_ray		ray;
	t_point		point;

	vector = v_between_two_points_nm(*mask_corner, *rt->camera->p);
	ray.v = &vector;
	ray.p = mask_corner;
	point = plane_ray_intersec(*rt->vp->vp_plane, ray);
	if(corner == "u")
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
	if(corner == "d")
	{
		ray.v = rt->vp->up;
		ray.p = rt->vp->bottom_right;
		rt->obj[rt->n_obj]->uvp_x1 = ceilf(distance_p_to_ray(point, ray)/rt->vp->pixel_w);
		ray.v = rt->vp->right;
		rt->obj[rt->n_obj]->uvp_y1 = ceilf(distance_p_to_ray(point, ray)/rt->vp->pixel_h);
		// rt->obj[rt->n_obj]->dvp_x2 = v_len(v_product_nm(*rt->vp->up, pp_sub_v_nm(point, *rt->vp->bottom_right)))/ v_len(*rt->vp->up);
		// rt->obj[rt->n_obj]->dvp_y2 = v_len(v_product_nm(*rt->vp->right, pp_sub_v_nm(point, *rt->vp->bottom_right)))/ v_len(*rt->vp->right);
	}
}
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
	float		x;
	float		y;
	t_vector	tmp_u;
	t_vector	tmp_d;
	t_point		p;
	t_vector	up;
	t_vector	right;

	x = rt->obj[rt->n_obj]->sphere->p->x;
	y = rt->obj[rt->n_obj]->sphere->p->y;
	r = rt->obj[rt->n_obj]->sphere->d / 2;
	p = *rt->obj[rt->n_obj]->sphere->p;
	up = *rt->vp->up;
	right = *rt->vp->right;
	tmp_u = v_add_nm(v_mult_scalar_nm(up, r), v_mult_scalar_nm(right, r * -1));
	tmp_d = v_add_nm(v_mult_scalar_nm(up, r * -1), v_mult_scalar_nm(right, r));
	*rt->obj[rt->n_obj]->sphere->u_corner = calc_endpoint_vector(&tmp_u, &p, 1);
	*rt->obj[rt->n_obj]->sphere->d_corner = calc_endpoint_vector(&tmp_d, &p, 1);

}

void	symplify_sphere(t_rt *rt)
{
	create_sphere_mask(rt);
	calc_maskpoint_on_vp(rt, rt->obj[rt->n_obj]->sphere->u_corner, 'u');
	calc_maskpoint_on_vp(rt, rt->obj[rt->n_obj]->sphere->d_corner, 'd');

}

void	symplify_cylinder(t_rt *rt)
{

}
