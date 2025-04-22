/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_normal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoth <afoth@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 20:33:53 by afoth             #+#    #+#             */
/*   Updated: 2025/04/22 19:22:06 by afoth            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/miniRT.h"

t_vector	cal_normal_plane(t_rt *rt, t_obj obj)
{
	t_vector	n;

	n = *(obj.pl->v);
	if (v_dot_product(&n, rt->vp->render_ray->v) > 0)
		n = v_mult_scalar_nm(n, -1);
	return (n);
}

// substract hitpoint from sphere center and making it len 1
t_vector	cal_normal_sphere(t_obj obj, t_point p)
{
	t_vector	n;

	n = pp_sub_v_nm(p, *obj.s->p);
	return (v_normalize_nm(n));
}

t_vector	cal_normal_cyl(t_obj obj, t_point p)
{
	t_vector	point2center;
	t_vector	neg_cyl_normal;

	neg_cyl_normal = v_mult_scalar_nm(*obj.cyl->v, -1);
	point2center = v_between_two_points_nm(p, *obj.cyl->p);
	if (located_in_endcaps(*obj.cyl, p))
	{
		if (v_dot_product(&point2center, obj.cyl->v) < 0)
			return (*obj.cyl->v);
		else
			return (neg_cyl_normal);
	}
	else
	{
		if (v_dot_product(&point2center, obj.cyl->v) < 0)
			return (v_normalize_nm(vector_projection(*obj.cyl->v,
						point2center)));
		else
			return (v_normalize_nm(vector_projection(neg_cyl_normal,
						point2center)));
	}
}

t_vector	cal_normal(t_rt *rt, t_obj obj, t_point p)
{
	if (obj.type == PLANE)
		return (cal_normal_plane(rt, obj));
	if (obj.type == SPHERE)
		return (cal_normal_sphere(obj, p));
	else
		return (cal_normal_cyl(obj, p));
}
