/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_viewport.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoth <afoth@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 15:53:32 by afoth             #+#    #+#             */
/*   Updated: 2025/02/17 18:17:02 by ltreser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/miniRT.h"

//XXX the forward orientation vector = camera vector
void	setup_viewport(t_rt *rt) //TODO init struct variables
{
	rt->vp->width = 2 * tanf(rt->camera->fov / 2);
	rt->vp->height = rt->vp->width / rt->aspect_r;
	rt->vp->right = v_normalize(v_cross_product(rt, &(t_vector){0,1,0}, rt->camera->v));
	rt->vp->up = v_normalize(v_cross_product(rt, rt->vp->right, rt->camera->v));
	*(rt->vp->center) = vp_add_nm(*rt->camera->v, *rt->camera->p);
	*(rt->vp->top_left) = vp_add_nm(v_subtract_nm(v_mult_scalar_nm(*rt->vp->up, rt->vp->height / 2), v_mult_scalar_nm(*rt->vp->right, rt->vp->width / 2)), *rt->vp->center);
	*(rt->vp->top_right) = vp_add_nm(v_add_nm(v_mult_scalar_nm(*rt->vp->up, rt->vp->height / 2), v_mult_scalar_nm(*rt->vp->right, rt->vp->width / 2)), *rt->vp->center);
	*(rt->vp->bottom_left) = pv_subtract_nm(*rt->vp->center, v_subtract_nm(v_mult_scalar_nm(*rt->vp->up, rt->vp->height / 2), v_mult_scalar_nm(*rt->vp->right, rt->vp->width / 2)));
	*(rt->vp->bottom_right) = pv_subtract_nm(*rt->vp->center, v_add_nm(v_mult_scalar_nm(*rt->vp->up, (rt->vp->height / 2)), v_mult_scalar_nm(*rt->vp->right, (rt->vp->width / 2))));
}

