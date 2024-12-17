/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoth <afoth@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 15:53:26 by afoth             #+#    #+#             */
/*   Updated: 2024/12/17 15:53:27 by afoth            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/miniRT.h"

t_vec	*v_cross_product(t_vec *a, t_vec *b)
{
	t_vec *res;

	res = malloc(sizeof(t_vec));
	res->x = a->y * b->z - a->z * b->y;
	res->y = a->z * b->x - a->x * b->z;
	res-> z = a->x * b->y - a->y * b->x;
	return (res);
}

t_vec	*v_normalize(t_vec *v)
{
	float	length;

	length = 0;
	length = sqrtf(v->x * v->x + v->y * v->y + v->z * v->z);
	if (!length)
		return ((t_vec{0,0,0}));
	v->x /= length;
	v->y /= length;
	v->z /= length;
	return (v);

}
