/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_viewport.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoth <afoth@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 15:53:32 by afoth             #+#    #+#             */
/*   Updated: 2025/04/19 22:01:45 by afoth            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/miniRT.h"

void	setup_pixel(t_rt *rt)
{
	rt->vp->pixel_w = rt->vp->width / rt->mlx->width;
	rt->vp->pixel_h = rt->vp->height / rt->mlx->height;
	*rt->vp->pixel_v_x = v_mult_scalar_nm(*rt->vp->right, rt->vp->pixel_w);
	*rt->vp->pixel_v_y = v_mult_scalar_nm(*rt->vp->up, rt->vp->pixel_h);
	*rt->vp->pixel_v_y_negative = v_mult_scalar_nm(*rt->vp->pixel_v_y, -1);
}

// XXX the forward orientation vector = camera vector
void	setup_viewport(t_rt *rt)
{
	rt->vp->render_ray = init_ray(rt->gc);
	rt->vp->width = 2 * tanf(((t_float)rt->camera->fov / 2) * (PI / 180.0f));
	calc_aspect_ratio(rt);
	rt->vp->height = rt->vp->width / rt->aspect_r;
	rt->vp->right = v_normalize(v_cross_product(rt, rt->camera->v,
				&(t_vector){0, 1, 0}));
	rt->vp->up = v_normalize(v_cross_product(rt, rt->vp->right, rt->camera->v));
	*(rt->vp->center) = p_add(*rt->camera->v, *rt->camera->p);
	*(rt->vp->top_left) = p_add(v_subtract_nm(v_mult_scalar_nm(*rt->vp->up,
					rt->vp->height / 2), v_mult_scalar_nm(*rt->vp->right,
					rt->vp->width / 2)), *rt->vp->center);
	*(rt->vp->top_right) = p_add(v_add_nm(v_mult_scalar_nm(*rt->vp->up,
					rt->vp->height / 2), v_mult_scalar_nm(*rt->vp->right,
					rt->vp->width / 2)), *rt->vp->center);
	*(rt->vp->bottom_right) = p_add(v_add_nm(\
		v_mult_scalar_nm(*rt->vp->right, rt->vp->width / 2), \
		v_mult_scalar_nm(*rt->vp->up,
					-rt->vp->height / 2)), *rt->vp->center);
	*(rt->vp->bottom_left) = p_add(v_subtract_nm(\
		v_mult_scalar_nm(*rt->vp->up,
					-rt->vp->height / 2), v_mult_scalar_nm(*rt->vp->right,
					rt->vp->width / 2)), *rt->vp->center);
	rt->vp->vp_plane->p = rt->vp->bottom_left;
	rt->vp->vp_plane->v = rt->camera->v;
	setup_pixel(rt);
}
