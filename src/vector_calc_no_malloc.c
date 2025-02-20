/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_calc_no_malloc.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoth <afoth@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 14:26:34 by afoth             #+#    #+#             */
/*   Updated: 2025/02/20 16:35:12 by ltreser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/miniRT.h"

t_vector	v_mult_scalar_nm(t_vector v, float scalar)
{
	t_vector	result;

	result.x = v.x *scalar;
	result.y = v.y *scalar;
	result.z = v.z *scalar;
	return(result);
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

float	scalar_product_nm(t_vector a, t_vector b)
{
	float	result;
	return(result = a.x * b.x + a.y * b.y + a.z * b.z);
}

t_vector    v_between_two_points_nm(t_point a, t_point b)
{
    t_vector    res;

    res.x = b.x - a.x;
    res.y = b.y - a.y;
    res.z = b.z - a.z;
    return (res);
}
