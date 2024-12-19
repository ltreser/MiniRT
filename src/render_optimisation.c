/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_optimisation.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoth <afoth@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 16:36:36 by afoth             #+#    #+#             */
/*   Updated: 2024/12/19 12:59:17 by afoth            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/miniRT.h"

//DEL TEST!!!!
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
