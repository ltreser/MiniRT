/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frustum_culling.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoth <afoth@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 22:43:17 by afoth             #+#    #+#             */
/*   Updated: 2025/04/19 19:10:34 by afoth            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/miniRT.h"
// have they been inited to 0/NULL?
void	malloc_fc(t_rt *rt)
{
	if (!rt->fc)
		rt->fc = gc_malloc(rt->gc, sizeof(t_fc));
	if (!rt->fc->uplane_n)
		rt->fc->uplane_n = gc_malloc(rt->gc, sizeof(t_vector));
	if (!rt->fc->dplane_n)
		rt->fc->dplane_n = gc_malloc(rt->gc, sizeof(t_vector));
	if (!rt->fc->rplane_n)
		rt->fc->rplane_n = gc_malloc(rt->gc, sizeof(t_vector));
	if (!rt->fc->lplane_n)
		rt->fc->lplane_n = gc_malloc(rt->gc, sizeof(t_vector));
	if (!rt->fc->uplane_p)
		rt->fc->uplane_p = gc_malloc(rt->gc, sizeof(t_point));
	if (!rt->fc->dplane_p)
		rt->fc->dplane_p = gc_malloc(rt->gc, sizeof(t_point));
	if (!rt->fc->rplane_p)
		rt->fc->rplane_p = gc_malloc(rt->gc, sizeof(t_point));
	if (!rt->fc->lplane_p)
		rt->fc->lplane_p = gc_malloc(rt->gc, sizeof(t_point));
}

void	calculate_fplanes(t_rt *rt)
{
	t_vector	v1;
	t_vector	v2;

	v1 = v_between_two_points_nm(*rt->camera->p, *rt->vp->top_right);
	v2 = v_between_two_points_nm(*rt->camera->p, *rt->vp->bottom_right);
	*rt->fc->rplane_n = v_normalize_nm(v_cross_product_nm(v2, v1));
	v1 = v_between_two_points_nm(*rt->camera->p, *rt->vp->top_left);
	v2 = v_between_two_points_nm(*rt->camera->p, *rt->vp->bottom_left);
	*rt->fc->lplane_n = v_normalize_nm(v_cross_product_nm(v1, v2));
	v1 = v_between_two_points_nm(*rt->camera->p, *rt->vp->top_left);
	v2 = v_between_two_points_nm(*rt->camera->p, *rt->vp->top_right);
	*rt->fc->uplane_n = v_normalize_nm(v_cross_product_nm(v2, v1));
	v1 = v_between_two_points_nm(*rt->camera->p, *rt->vp->bottom_left);
	v2 = v_between_two_points_nm(*rt->camera->p, *rt->vp->bottom_right);
	*rt->fc->dplane_n = v_normalize_nm(v_cross_product_nm(v1, v2));
}

void	frustum_culling(t_rt *rt)
{
	int			i;
	t_float		distance;
	t_float		radius;
	t_vector	cam2obj;

	i = 0;
	malloc_fc(rt);
	calculate_fplanes(rt);
	while (i < rt->n_obj)
	{
		distance = -1;
		if (rt->obj[i]->type == SPHERE)
		{
			cam2obj = v_between_two_points_nm(*rt->camera->p, *rt->obj[i]->s->p);
			radius = rt->obj[i]->s->rot_r;
		}
		else if (rt->obj[i]->type == CYLINDER)
		{
			cam2obj = v_between_two_points_nm(*rt->camera->p, *rt->obj[i]->cyl->p);
			radius = rt->obj[i]->s->rot_r;
		}
		if (rt->obj[i]->type != PLANE)
		{
			distance = v_dot_product(&cam2obj, rt->fc->rplane_n) - radius;
			if (distance > 0)
					rt->obj[i]->visible = 0;
			distance = v_dot_product(&cam2obj, rt->fc->lplane_n) - radius ;
			if (distance > 0)
					rt->obj[i]->visible = 0;
			distance = v_dot_product(&cam2obj, rt->fc->dplane_n) - radius;
			if (distance > 0)
					rt->obj[i]->visible = 0;
			distance = v_dot_product(&cam2obj, rt->fc->uplane_n) - radius;
			if (distance > 0)
					rt->obj[i]->visible = 0;
			break ;
		}
		i++;
	}
	/*i = 0;
	while (i < rt->n_obj)
	{
		if (rt->obj[i]->visible)
			printf("obj nr %d is visible\n", i);
		else
			printf("obj nr %d is NOT visible\n", i);
		i++;
	}*/
}
