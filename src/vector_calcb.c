/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_calcb.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltreser <ltreser@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 14:10:39 by ltreser           #+#    #+#             */
/*   Updated: 2025/04/22 14:10:59 by ltreser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/miniRT.h"

t_vector	*v_between_two_points(t_rt *rt, t_point a, t_point b)
{
	t_vector	*res;

	res = gc_malloc(rt->gc, sizeof(t_vector));
	res->x = b.x - a.x;
	res->y = b.y - a.y;
	res->z = b.z - a.z;
	return (res);
}

// project vector a onto b
// the component of a that goes in the same direction as b
t_vector	vector_projection(t_vector a, t_vector b)
{
	t_float	dot_ab;
	t_float	dot_bb;

	dot_ab = scalar_product_nm(a, b);
	dot_bb = scalar_product_nm(b, b);
	if (dot_bb == 0)
		return ((t_vector){0, 0, 0});
	return (v_mult_scalar_nm(b, dot_ab / dot_bb));
}
