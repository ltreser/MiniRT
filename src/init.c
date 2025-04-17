/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoth <afoth@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 17:51:38 by afoth             #+#    #+#             */
/*   Updated: 2025/04/17 22:47:34 by afoth            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/miniRT.h"

void	init(t_rt *rt)
{
	rt->fd = 0;
	rt->obj_count = 0;
	rt->gc = malloc(sizeof(t_gc));
	ft_gc_init(rt->gc);
	rt->mlx = gc_malloc(rt->gc, sizeof(t_mlx));
	calc_aspect_ratio(rt);
	rt->camera = NULL;
	rt->ambient = NULL;
	rt->light = NULL;
	rt->n_obj = 0;
	rt->fc = gc_malloc(rt->gc, sizeof(t_fc));
	init_viewport(rt);
	init_fc(rt->fc);
}

void	init_viewport(t_rt *rt)
{
	rt->vp = gc_malloc(rt->gc, sizeof(t_vp));
	rt->vp->up = gc_malloc(rt->gc, sizeof(t_vector));
	rt->vp->right = gc_malloc(rt->gc, sizeof(t_vector));
	rt->vp->pixel_v_x = gc_malloc(rt->gc, sizeof(t_vector));
	rt->vp->pixel_v_y = gc_malloc(rt->gc, sizeof(t_vector));
	rt->vp->pixel_v_y_negative = gc_malloc(rt->gc, sizeof(t_vector));
	rt->vp->center = gc_malloc(rt->gc, sizeof(t_point));
	rt->vp->top_left = gc_malloc(rt->gc, sizeof(t_point));
	rt->vp->top_right = gc_malloc(rt->gc, sizeof(t_point));
	rt->vp->bottom_left = gc_malloc(rt->gc, sizeof(t_point));
	rt->vp->bottom_right = gc_malloc(rt->gc, sizeof(t_point));
	rt->vp->vp_plane = gc_malloc(rt->gc, sizeof(t_plane));
}

void	init_fc(t_fc *fc)
{
	fc->uplane_n = NULL;
	fc->dplane_n = NULL;
	fc->rplane_n = NULL;
	fc->lplane_n = NULL;
	fc->uplane_p = NULL;
	fc->dplane_p = NULL;
	fc->rplane_p = NULL;
	fc->lplane_p = NULL;
}
