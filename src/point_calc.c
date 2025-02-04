/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point_calc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoth <afoth@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 17:45:50 by afoth             #+#    #+#             */
/*   Updated: 2025/02/03 15:37:22 by ltreser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/miniRT.h"

//adds a given vector to a point, so the point is moved in the direction and length of the vector
t_point	*pv_add(t_vector *a, t_point *b)
{
	t_point *res;

	res = gc_malloc(rt->gc, sizeof(t_point));
	res->x = a->x + b->x;
	res->y = a->y + b->y;
	res->z = a->z + b->z;
	return (res);
}
t_point	calc_endpoint_vector(t_vector *v, t_point *start, float scalar)
{
	t_point	 end;

	end.x = start->x + scalar * v->x;
	end.y = start->y + scalar * v->y;
	end.z = start->z + scalar * v->z;
	return(end);
}

float	calc_p_distance(t_point a, t_point b)
{
	float distance;

	distance = sqrtf(powf(a->x - b->x) + powf(a->y - b->y) + powf(a-> - b->z));
	if (distance < 0)
		distance *= -1;
	return (distance);
}
