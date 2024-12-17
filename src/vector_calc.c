/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_calc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoth <afoth@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 23:10:32 by afoth             #+#    #+#             */
/*   Updated: 2024/12/17 17:49:22 by afoth            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/miniRT.h"

float v_len(t_vector *vector)
{
	return(sqrtf(vector->x * vector->x + vector->y * vector->y + vector->z * vector->z));
}

t_vector	*v_cross_product(t_rt *rt, t_vector *a, t_vector *b)
{
	t_vector *res;

	res = gc_malloc(rt->gc, sizeof(t_vector));
	res->x = a->y * b->z - a->z * b->y;
	res->y = a->z * b->x - a->x * b->z;
	res-> z = a->x * b->y - a->y * b->x;
	return (res);
}

t_vector	*v_normalize(t_vector *v)
{
	float	length;

	length = 0;
	length = v_len(v);
	if (!length)
		return ((t_vector{0,0,0}));
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
