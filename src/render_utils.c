/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltreser <ltreser@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 15:18:55 by ltreser           #+#    #+#             */
/*   Updated: 2025/04/22 15:41:20 by ltreser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/miniRT.h"

t_point	calc_startpoint_render(t_rt *rt)
{
	t_vector	vector;
	t_point		point;

	vector = v_add_nm(*rt->vp->pixel_v_y, *rt->vp->pixel_v_x);
	vector = v_mult_scalar_nm(vector, (t_float)0.5);
	point = p_add(vector, *rt->vp->bottom_left);
	return (point);
}

// DEL error handling?
// TODO problem: ray start point should be the camera

void	create_render_ray(t_rt *rt)
{
	*rt->vp->render_ray->p = *rt->camera->p;
	*rt->vp->render_ray->v = v_between_two_points_nm(*rt->camera->p,
			calc_startpoint_render(rt));
}

t_color	get_color(t_rt *rt, int i)
{
	if (rt->obj[i]->type == PLANE)
		return (*rt->obj[i]->pl->c);
	if (rt->obj[i]->type == SPHERE)
		return (*rt->obj[i]->s->c);
	return (*rt->obj[i]->cyl->c);
}
