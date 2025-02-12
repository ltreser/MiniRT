/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_optimisation.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoth <afoth@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 16:36:36 by afoth             #+#    #+#             */
/*   Updated: 2025/02/12 22:32:43 by afoth            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/miniRT.h"

//DEL TEST!!!!

void	optimise_pixel_rendering(t_rt *rt)
{
	/*optimize obj
	how do I get access to the obj, how do I know wich type?
	Where do I store the squares?
	How do I know the coordinats of the squares?

	1. Calculate the coordinates of the covering square
	2. Create a vector betweem square and camera.
	3. Calculate impact point on viewport
	4. Translate impact point into pixel coordinates
	5. Save the coordinates
	*/
	//go throught obj
	//if sphere ->
		symplify_sphere(rt);

}

t_vector	calc_maskpoint_on_vp(t_rt *rt, t_point	*mask_corner)
{
	t_vector	*vector;

	vector = v_between_two_points(mask_corner, rt->camera->p);

}
/*Calculation of the points of a square mask that will
represent the square on the viewport.
Only where the mask is, pixels are renderd

Upper Corner = normalized Vektor up * r + normalized Vektor right * (r * -1)
Lower Corner = normalized Vektor up * (r -1) + normalized Vektor right * r
This creates the cordinates of a square with sidelenght r in 3D Space paralle to
the viewport
*/
void	symplify_sphere(t_rt *rt)
{
	float		r;
	float		x;
	float		y;
	t_point		*p;
	t_vector	*up;
	t_vector	*right;

	x = rt->obj[rt->n_obj]->sphere->p->x;
	y = rt->obj[rt->n_obj]->sphere->p->y;
	r = rt->obj[rt->n_obj]->sphere->d / 2;
	p = rt->obj[rt->n_obj]->sphere->p;
	up = rt->vp->up;
	right = rt->vp->right;
	rt->obj[rt->n_obj]->sphere->u_corner = calc_endpoint_vector(v_add_no_maloc(v_mult_scalar(up, r), v_mult_scalar(right, r * -1), p, 1));
	rt->obj[rt->n_obj]->sphere->d_corner = calc_endpoint_vector(v_add_no_maloc(v_mult_scalar(up, r * -1), v_mult_scalar(right, r), p, 1));
}

void	symplify_cylinder(t_rt *rt)
{

}
