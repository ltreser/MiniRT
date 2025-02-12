/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_calc_no_malloc.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoth <afoth@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 14:26:34 by afoth             #+#    #+#             */
/*   Updated: 2025/02/12 22:16:42 by afoth            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/miniRT.h"

t_vector	v_mult_scalar(t_vector v, float scalar)
{
	t_vector	result;

	result.x = v.x *scalar;
	result.y = v.y *scalar;
	result.z = v.z *scalar;
	return(result);
}

t_vector	v_add(t_vector a, t_vector b)
{
	t_vector	res;

	res.x = a.x + b.x;
	res.y = a.y + b.y;
	res.z = a.z + b.z;
	return (res);
}

t_vector	v_subst(t_vector a, t_vector b)
{
	t_vector	res;

	res.x = a.x - b.x;
	res.y = a.y - b.y;
	res.z = a.z - b.z;
	return (res);
}

t_vector	v_mult(t_vector a, t_vector b)
{
	t_vector	res;

	res.x = a.x * b.x;
	res.y = a.y * b.y;
	res.z = a.z * b.z;
	return (res);
}

float	scalar_product(t_vector a, t_vector b)
{
	float	result;
	return(result = a.x * b.x + a.y * b.y + a.z * b.z);
}
