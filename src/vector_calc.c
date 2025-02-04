/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_calc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoth <afoth@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 23:10:32 by afoth             #+#    #+#             */
/*   Updated: 2025/02/04 16:26:37 by ltreser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/miniRT.h"

//function has possibility to over and underflow
float v_len(t_vector *vector)
{
	if (!vector)
	{
		printf("Error in v_len\nVector is NULL\n");//DEL?
		return (0);
	}
	return(sqrtf(vector->x * vector->x + vector->y * vector->y + vector->z * vector->z));
}

//results in a scalar that descrubes the angle between the two vectors, e.g. if a * b = 0 -> they are perpendicular
float	v_dot_product(t_rt *rt, t_vector *a, t_vector *b)


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

t_vector	*v_normalize(t_vector *v)
{
	float	length;

	length = 0;
	length = v_len(v);
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

t_vector	v_mult_scalar(t_vector v, float scalar)
{
	t_vector	result;

	result.x = v.x *scalar;
	result.y = v.y *scalar;
	result.z = v.z *scalar;
	return(result);
}


t_vector	*v_add_no_maloc(t_vector *a, t_vector *b)
{
	t_vector	*res;

	res->x = a->x + b->x;
	res->y = a->y + b->y;
	res->z = a->z + b->z;
	return (res);
}

t_vector	*v_between_two_points(t_point a, t_point b)
{
	t_vector	*res;

	res->x = b.x - a.x;
	res->y = b.y - a.y;
	res->z = b.z - a.z;
	return (res);
}

//project vector a onto b
t_vector	vector_projection(t_vector a, t_vector b)
{
	t_vector res;
	res = ((b * a) / (b * b)) * b;
	return (res);
}

}
