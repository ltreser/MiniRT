/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoth <afoth@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 22:37:28 by afoth             #+#    #+#             */
/*   Updated: 2025/04/22 15:06:14 by afoth            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/miniRT.h"

/* The equation for a more general
cylinder of radius r oriented along
a line pa + va *t:
(q - pa - (va,q - pa)va)^2 - r^2 = 0
where		q = (x,y,z) is a point on the
cylinder.
To find intersection points with a ray p + vt,
substitute	q = p + vt and solve:
(p - pa + vt - (va,p - pa + vt)va)^2 - r^2 = 0
reduces to At^2 + Bt + C = 0
with
 A = (v - (v, va)va)^2
 B = 2(v - (v, va)va,[delta]p - ([delta]p,va)va)
 C = ([delta]p - ([delta]p, va)va)^2 - r^2
 where [delta]p = p - pa


	(va, (p+v*t1)-p1) > 0 and (va, (p+v*t1)- p2) < 0
	(va, (p+v*t2)-p1) > 0 and (va, (p+v*t2)- p2) < 0
*/

/* t_float	cylinder_intersection(t_cylinder cyl, t_ray ray)
{
	t_float	cylinder_intersection1;
	t_float	cylinder_intersection2;
	t_float	plane_intersection1;
	t_float	plane_intersection2;
	t_float	t;

	t = -1;
	cylinder_intersection1 = infinite_cylinder(cyl, ray, 0);
	cylinder_intersection2 = infinite_cylinder(cyl, ray, 1);
	if (cylinder_intersection1 > 0 && point_within_planes(cyl,
			cylinder_intersection1, ray))
		t = cylinder_intersection1;
	if (cylinder_intersection2 > 0 && point_within_planes(cyl,
			cylinder_intersection2, ray) && (t < 0
			|| t > cylinder_intersection2))
		t = cylinder_intersection2;
	plane_intersection1 = infinite_plane_a(cyl, ray);
	plane_intersection2 = infinite_plane_b(cyl, ray);
	if (plane_intersection1 > 0 && point_within_circles(cyl,
			plane_intersection1, ray) && (t < 0 || t > plane_intersection1))
		t = plane_intersection1;
	if (plane_intersection2 > 0 && point_within_circles(cyl,
			plane_intersection2, ray) && (t < 0 || t > plane_intersection2))
		t = plane_intersection2;
	return (t);
}

t_float	infinite_plane_a(t_cylinder cyl, t_ray ray)
{
	t_plane		plane;
	t_vector	v;
	t_point		p;

	plane.v = &v;
	plane.p = &p;
	*plane.p = calc_endpoint_vector(cyl.v, cyl.p, cyl.h / 2);
	plane.v = cyl.v;
	return (plane_ray_calc_t(plane, ray));
}

t_float	infinite_plane_b(t_cylinder cyl, t_ray ray)
{
	t_plane		plane;
	t_vector	v;
	t_point		p;

	plane.v = &v;
	plane.p = &p;
	*plane.p = calc_endpoint_vector(cyl.v, cyl.p, -(cyl.h / 2));
	*plane.v = v_mult_scalar_nm(*cyl.v, -1);
	return (plane_ray_calc_t(plane, ray));
}

int	point_within_circles_check(t_cylinder cyl, t_point point,
		t_vector top_normal, t_vector bottom_normal)
{
	t_point		bottom_center;
	t_point		top_center;
	t_vector	center2point_top;
	t_vector	center2point_bottom;

	top_center = calc_endpoint_vector(cyl.v, cyl.p, cyl.h / 2);
	bottom_center = calc_endpoint_vector(cyl.v, cyl.p, -(cyl.h / 2));
	center2point_top = v_between_two_points_nm(top_center, point);
	center2point_bottom = v_between_two_points_nm(bottom_center, point);
	if (!v_dot_product(&center2point_top, &top_normal)
		&& v_len(center2point_top) <= cyl.d / 2)
		return (1);
	if (!v_dot_product(&center2point_bottom, &bottom_normal)
		&& v_len(center2point_bottom) <= cyl.d / 2)
		return (1);
	return (0);
}

int	point_within_circles(t_cylinder cyl, t_float intersection, t_ray ray)
{
	t_point		point;
	t_vector	top_normal;
	t_vector	bottom_normal;

	point = calc_endpoint_vector(ray.v, ray.p, intersection);
	top_normal = *cyl.v;
	bottom_normal = v_mult_scalar_nm(*cyl.v, -1);
	return (point_within_circles_check(cyl, point, top_normal, bottom_normal));
}

int	point_within_planes_check(t_point point, t_vector top_normal,
		t_vector bottom_normal)
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
	return (point_within_planes_check(point, top_normal, bottom_normal));
}

t_float	infinite_cylinder(t_cylinder cyl, t_ray ray, int flag)
{
	t_vector	delta_p;
	t_vector	vector1;
	t_vector	vector2;
	t_float		r;

	r = cyl.d / 2;
	delta_p = pp_sub_v_nm(*ray.p, *cyl.p);
	vector1 = v_subtract_nm(*ray.v, v_mult_scalar_nm(*cyl.v,
				v_dot_product(ray.v, cyl.v)));
	vector2 = v_subtract_nm(delta_p, v_mult_scalar_nm(*cyl.v,
				v_dot_product(&delta_p, cyl.v)));
	if (flag == 0)
		return (abc_formula(scalar_product_nm(vector1, vector1), 2
				* (v_dot_product(&vector1, &vector2), scalar_product_nm(vector2,
						vector2) - (r * r), 0));
	return (abc_formula(scalar_product_nm(vector1, vector1), 2
			* (v_dot_product(&vector1, &vector2), scalar_product_nm(vector2,
					vector2) - (r * r), 1));
} */
