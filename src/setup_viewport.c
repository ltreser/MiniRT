/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_viewport.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoth <afoth@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 15:53:32 by afoth             #+#    #+#             */
/*   Updated: 2025/01/21 17:21:40 by afoth            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/miniRT.h"

//XXX the forward orientation vector = camera vector
void	setup_viewport(t_rt *rt) //TODO init struct variables
{
	rt->vp->width = 2 * tanf(rt->camera->fov / 2);
	rt->vp->height = rt->vp->width / rt->aspect_r;
	rt->vp->right = v_normalize(v_cross_product(rt->gc, t_vec{0,1,0}, rt->camera->v));
	rt->vp->up = v_normalize(v_cross_product(rt->gc, rt->vp->right, rt->camera->v));
	rt->vp->center = pv_add(rt->gc, rt->camera->v, rt->camera->p);
	rt->vp->top_left = rt->vp->center + rt->vp->up * (rt->vp->height / 2) - rt->vp->right * (rt->vp->width / 2);
	rt->vp->top_right = rt->vp->center + rt->vp->up * (rt->vp->height / 2) + rt->vp->right * (rt->vp->width / 2);
	rt->vp->bottom_left = rt->vp->center - rt->vp->up * (rt->vp->height / 2) - rt->vp->right * (rt->vp->width / 2);
	rt->vp->bottom_right = rt->vp->center - rt->vp->up * (rt->vp->height / 2) + rt->vp->right * (rt->vp->width / 2);
}


