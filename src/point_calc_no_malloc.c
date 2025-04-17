/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point_calc_no_malloc.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoth <afoth@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 14:38:54 by afoth             #+#    #+#             */
/*   Updated: 2025/04/17 22:58:44 by afoth            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/miniRT.h"

t_point	p_add(t_vector a, t_point b)
{
	t_point	res;

	res.x = a.x + b.x;
	res.y = a.y + b.y;
	res.z = a.z + b.z;
	return (res);
}

t_vector	pp_sub_v_nm(t_point a, t_point b)
{
	t_vector	res;

	res.x = a.x - b.x;
	res.y = a.y - b.y;
	res.z = a.z - b.z;
	return (res);
}

t_point	calc_endpoint_vector_nm(t_vector v, t_point start, t_float scalar)
{
	t_point	end;

	end.x = start.x + scalar * v.x;
	end.y = start.y + scalar * v.y;
	end.z = start.z + scalar * v.z;
	return (end);
}
