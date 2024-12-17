/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_calc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoth <afoth@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 23:10:32 by afoth             #+#    #+#             */
/*   Updated: 2024/12/17 17:31:50 by afoth            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/miniRT.h"

float v_len(t_vector *vector)
{
	return(sqrtf(vector->x * vector->x + vector->y * vector->y + vector->z * vector->z));
}
t_point	calc_endpoint_vector(t_vector *v, t_point *start, float scalar)
{
	t_point	 end;

	end.x = start->x + scalar * v->x;
	end.y = start->y + scalar * v->y;
	end.z = start->z + scalar * v->z;
	return(end);
}
