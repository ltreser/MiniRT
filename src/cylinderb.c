/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinderb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoth <afoth@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 15:15:56 by ltreser           #+#    #+#             */
/*   Updated: 2025/04/22 16:14:13 by afoth            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/miniRT.h"

int	point_within_planes_check(t_cylinder cyl, t_point point,
		t_vector top_normal, t_vector bottom_normal)
{
	t_point		top_point;
	t_vector	top2point;
	t_vector	bottom2point;
	t_point		bottom_point;

	top_point = calc_endpoint_vector(cyl.v, cyl.p, cyl.h / 2);
	bottom_point = calc_endpoint_vector(cyl.v, cyl.p, (-(cyl.h / 2)));
	top2point = v_between_two_points_nm(top_point, point);
	bottom2point = v_between_two_points_nm(bottom_point, point);
	if (v_dot_product(&top2point, &top_normal) > 0)
		return (0);
	if (v_dot_product(&bottom2point, &bottom_normal) > 0)
		return (0);
	return (1);
}

int	point_within_planes(t_cylinder cyl, t_float intersection, t_ray ray)
{
	t_point		point;
	t_vector	top_normal;
	t_vector	bottom_normal;

	point = calc_endpoint_vector(ray.v, ray.p, intersection);
	top_normal = *cyl.v;
	bottom_normal = v_mult_scalar_nm(*cyl.v, -1);
	return (point_within_planes_check(cyl, point, top_normal, bottom_normal));
}

t_float	infinite_cylinder(t_cylinder cyl, t_ray ray, int flag)
{
	t_vector	vector1;
	t_vector	vector2;
	t_float		a;
	t_float		b;
	t_float		c;

	vector1 = v_subtract_nm(*ray.v, v_mult_scalar_nm(*cyl.v,
				v_dot_product(ray.v, cyl.v)));
	vector2 = v_subtract_nm(pp_sub_v_nm(*ray.p, *cyl.p),
			v_mult_scalar_nm(*cyl.v, scalar_product_nm(\
				pp_sub_v_nm(*ray.p, *cyl.p), *cyl.v)));
	a = scalar_product_nm(vector1, vector1);
	b = 2 * (v_dot_product(&vector1, &vector2));
	c = scalar_product_nm(vector2, vector2) - (cyl.d / 2 * cyl.d / 2);
	if (flag == 0)
		return (abc_formula(a, b, c, 0));
	return (abc_formula(a, b, c, 1));
}
