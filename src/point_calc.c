/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point_calc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoth <afoth@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 17:45:50 by afoth             #+#    #+#             */
/*   Updated: 2025/04/19 22:03:01 by afoth            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/miniRT.h"

// adds a given vector to a point, so the point
// is moved in the direction and length of the vector
t_point	*pv_add(t_rt *rt, t_vector *a, t_point *b)
{
	t_point	*res;

	res = gc_malloc(rt->gc, sizeof(t_point));
	res->x = a->x + b->x;
	res->y = a->y + b->y;
	res->z = a->z + b->z;
	return (res);
}

t_point	calc_endpoint_vector(t_vector *v, t_point *start, t_float scalar)
{
	t_point	end;

	end.x = start->x + scalar * v->x;
	end.y = start->y + scalar * v->y;
	end.z = start->z + scalar * v->z;
	return (end);
}

// powf calculates the value of one
// t_float raised to the power of another t_float.
// XXX distance between 2 points is returned as a negative t_float
t_float	calc_p_distance(t_point a, t_point b)
{
	t_float	distance;

	distance = sqrtf(powf(a.x - b.x, 2) + powf(a.y - b.y, 2) + powf(a.z - b.z,
				2));
	if (distance < 0)
		distance *= -1;
	return (distance);
}

t_point	pv_subtract_nm(t_point a, t_vector b)
{
	t_point	res;

	res.x = a.x - b.x;
	res.y = a.y - b.y;
	res.z = a.z - b.z;
	return (res);
}
