/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_calc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoth <afoth@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 15:48:50 by afoth             #+#    #+#             */
/*   Updated: 2025/04/22 14:11:04 by ltreser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/miniRT.h"

// function has possibility to over and underflow
t_float	v_len(t_vector vector)
{
	return (sqrtf(vector.x * vector.x + vector.y * vector.y + vector.z
			* vector.z));
}

// results in a vector thats perpendicular (senkrecht) to both a and b
t_vector	*v_cross_product(t_rt *rt, t_vector *a, t_vector *b)
{
	t_vector	*res;

	res = gc_malloc(rt->gc, sizeof(t_vector));
	res->x = a->y * b->z - a->z * b->y;
	res->y = a->z * b->x - a->x * b->z;
	res->z = a->x * b->y - a->y * b->x;
	return (res);
}

t_vector	v_cross_product_nm(t_vector a, t_vector b)
{
	t_vector	res;

	res.x = a.y * b.z - a.z * b.y;
	res.y = a.z * b.x - a.x * b.z;
	res.z = a.x * b.y - a.y * b.x;
	return (res);
}

t_vector	*v_normalize(t_vector *v)
{
	t_float	length;

	length = 0;
	length = v_len(*v);
	if (length == 0)
		return (v);
	v->x /= length;
	v->y /= length;
	v->z /= length;
	return (v);
}

t_vector	*v_add(t_rt *rt, t_vector *a, t_vector *b)
{
	t_vector	*res;

	res = gc_malloc(rt->gc, sizeof(t_vector));
	res->x = a->x + b->x;
	res->y = a->y + b->y;
	res->z = a->z + b->z;
	return (res);
}
