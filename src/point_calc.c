/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point_calc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoth <afoth@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 17:45:50 by afoth             #+#    #+#             */
/*   Updated: 2024/12/17 17:46:36 by afoth            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/miniRT.h"

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
