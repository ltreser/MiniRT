/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_calc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoth <afoth@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 15:48:50 by afoth             #+#    #+#             */
/*   Updated: 2025/02/20 16:56:32 by ltreser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/miniRT.h"

//function has possibility to over and underflow
float v_len(t_vector vector)
{
	return(sqrtf(vector.x * vector.x + vector.y * vector.y + vector.z * vector.z));
}

//results in a scalar that descrubes the angle between the two vectors, e.g. if a * b = 0 -> they are perpendicular
//float	v_dot_product(t_rt *rt, t_vector *a, t_vector *b)


//results in a vector thats perpendicular (senkrecht) to both a and b
t_vector	*v_cross_product(t_rt *rt, t_vector *a, t_vector *b)
{
	t_vector *res;

	res = gc_malloc(rt->gc, sizeof(t_vector));
	res->x = a->y * b->z - a->z * b->y;
	res->y = a->z * b->x - a->x * b->z;
	res-> z = a->x * b->y - a->y * b->x;
	return (res);
}

t_vector	v_cross_product_nm(t_vector a, t_vector b)
{
	t_vector res;

	res.x = a.y * b.z - a.z * b.y;
	res.y = a.z * b.x - a.x * b.z;
	res. z = a.x * b.y - a.y * b.x;
	return (res);
}


t_vector	*v_normalize(t_vector *v)
{
	float	length;

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

t_vector	*v_between_two_points(t_rt *rt, t_point a, t_point b)
{
	t_vector	*res;

	res = gc_malloc(rt->gc, sizeof(t_vector));
	res->x = b.x - a.x;
	res->y = b.y - a.y;
	res->z = b.z - a.z;
	return (res);
}

//project vector a onto b
//the component of a that goes in the same direction as b

t_vector	vector_projection(t_vector a, t_vector b)
{
	t_vector res;
	res = v_mult_scalar_nm(b, ((scalar_product_nm(a, b)) / (scalar_product_nm(b, b))));
	return (res);
}

