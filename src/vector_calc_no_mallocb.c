/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_calc_no_mallocb.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltreser <ltreser@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 14:08:34 by ltreser           #+#    #+#             */
/*   Updated: 2025/04/22 14:08:46 by ltreser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/miniRT.h"

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
