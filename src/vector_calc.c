/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_calc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoth <afoth@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 23:10:32 by afoth             #+#    #+#             */
/*   Updated: 2024/12/17 17:39:10 by afoth            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/miniRT.h"

float v_len(t_vector *vector)
{
	return(sqrtf(vector->x * vector->x + vector->y * vector->y + vector->z * vector->z));
}

t_vec   *v_cross_product(t_vec *a, t_vec *b)
{
    t_vec *res;

	res = gc_malloc(rt->gc, sizeof(t_vec));
    res->x = a->y * b->z - a->z * b->y;
    res->y = a->z * b->x - a->x * b->z;
    res-> z = a->x * b->y - a->y * b->x;
    return (res);
}

t_vec   *v_normalize(t_vec *v)
{
    float   length;

    length = 0;
    length = v_len(v);
    if (!length)
        return ((t_vec{0,0,0}));
    v->x /= length;
    v->y /= length;
    v->z /= length;
    return (v);
}

t_vec	*v_add(t_vec *a, t_vec *b)
{
	t_vec *res;

	res = gc_malloc(rt->gc, sizeof(t_vec));
	res->x = a->x + b->x;
	res->y = a->y + b->y;
	res->z = a->z + b->z;
	return (res);
}

t_point   *pv_add(t_vec *a, t_point *b)
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
