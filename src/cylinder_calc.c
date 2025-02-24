/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_calc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoth <afoth@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 19:02:13 by afoth             #+#    #+#             */
/*   Updated: 2025/02/20 16:36:56 by ltreser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/miniRT.h"

 float	cylinder_rot_radius(t_rt *rt, t_cylinder *c)
{
	t_point		up_center;
	t_point		up_side;
	t_vector	arbitrary;
	t_vector	sideways;
	float		radius;

	up_center = calc_endpoint_vector(c->v, c->p, c->h / 2);
	arbitrary.x = 0.0;
	arbitrary.y = 1.0;
	arbitrary.z = 0.0;
	if (fabs(arbitrary.x) < 1e-6 && fabs(arbitrary.z) < 1e-6)
	{
		arbitrary.x = 0.0;
		arbitrary.y = 1.0;
		arbitrary.z = 0.0;
	}
	sideways = v_cross_product_nomalloc(arbitrary, *(c->v));
	up_side	= calc_endpoint_vector(&sideways, &up_center, c->d/2);
	radius = v_len(v_between_two_points_nm(*(c->p), up_side));
	return (radius);
}
