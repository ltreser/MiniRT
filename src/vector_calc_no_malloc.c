/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_calc_no_malloc.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoth <afoth@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 14:26:34 by afoth             #+#    #+#             */
/*   Updated: 2025/04/19 21:26:01 by ltreser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/miniRT.h"

t_vector	v_mult_scalar_nm(t_vector v, t_float scalar)
{
	t_vector	result;

	result.x = v.x * scalar;
	result.y = v.y * scalar;
	result.z = v.z * scalar;
	return (result);
}

t_vector	v_add_nm(t_vector a, t_vector b)
{
	t_vector	res;

	res.x = a.x + b.x;
	res.y = a.y + b.y;
	res.z = a.z + b.z;
	return (res);
}

t_vector	v_subtract_nm(t_vector a, t_vector b)
{
	t_vector	res;

	res.x = a.x - b.x;
	res.y = a.y - b.y;
	res.z = a.z - b.z;
	return (res);
}

t_vector	v_mult_nm(t_vector a, t_vector b)
{
	t_vector	res;

	res.x = a.x * b.x;
	res.y = a.y * b.y;
	res.z = a.z * b.z;
	return (res);
}

t_vector	v_product_nm(t_vector a, t_vector b)
{
	t_vector	res;

	res.x = a.y * b.z - a.z * b.y;
	res.y = a.z * b.x - a.x * b.z;
	res.z = a.x * b.y - a.y * b.x;
	return (res);
}

t_float	scalar_product_nm(t_vector a, t_vector b)
{
	t_float	result;

	return (result = a.x * b.x + a.y * b.y + a.z * b.z);
}

/*returns vector that points from a to b*/
t_vector	v_between_two_points_nm(t_point a, t_point b)
{
	t_vector	res;

	res.x = b.x - a.x;
	res.y = b.y - a.y;
	res.z = b.z - a.z;
	return (res);
}

t_vector	v_normalize_nm(t_vector v)
{
	t_float	length;

	length = 0;
	length = v_len(v);
	if (length == 0)
		return (v);
	v.x /= length;
	v.y /= length;
	v.z /= length;
	return (v);
}

t_float	distance_p_to_ray(t_point point, t_ray ray)
{
	return (v_len(v_product_nm(*ray.v, pp_sub_v_nm(point, *ray.p)))
		/ v_len(*ray.v));
}

t_float	v_dot_product(t_vector *a, t_vector *b)
{
	return (a->x * b->x + a->y * b->y + a->z * b->z);
}
