/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_optimisation.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoth <afoth@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 16:36:36 by afoth             #+#    #+#             */
/*   Updated: 2024/12/16 16:45:24 by afoth            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/miniRT.h"

void	symplify_sphere(t_rt *rt)
{
	float r;
	float x;
	float y;

	x = rt->obj[rt->n_obj]->sphere->p->x;
	y = rt->obj[rt->n_obj]->sphere->p->y;
	r = rt->obj[rt->n_obj]->sphere->d / 2;

	rt->obj[rt->n_obj]->sphere->x_corner[0] = x - r;
	rt->obj[rt->n_obj]->sphere->x_corner[1] = y + r;
	rt->obj[rt->n_obj]->sphere->y_corner[0] = x + r;
	rt->obj[rt->n_obj]->sphere->y_corner[1] = y - r;
}


