/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere_calc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoth <afoth@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 21:24:04 by ltreser           #+#    #+#             */
/*   Updated: 2025/04/22 19:26:22 by afoth            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/miniRT.h"

t_float	a_b_c_formula(t_float a, t_float b, t_float discriminant)
{
	t_float	intersections[2];
	t_float	t;

	t = 0;
	if (discriminant < EPSILON)
		return (-1);
	discriminant = sqrtf(discriminant);
	intersections[0] = -(b + discriminant) / (2 * a);
	intersections[1] = -(b - discriminant) / (2 * a);
	t = intersections[0];
	if (intersections[1] > EPSILON && intersections[1] < intersections[0])
		t = intersections[1];
	return (t);
}

// TODO build in protection from vectors w length 0
t_float	sphere_intersection(t_sphere *s, t_ray *r)
{
	t_float		a;
	t_float		b;
	t_float		c;
	t_float		discriminant;
	t_vector	vector;

	vector = v_subtract_nm((t_vector){r->p->x, r->p->y, r->p->z},
			(t_vector){s->p->x, s->p->y, s->p->z});
	a = (v_len(*r->v)) * (v_len(*r->v));
	b = 2 * v_dot_product(r->v, &vector);
	c = (v_len(vector)) * (v_len(vector)) - s->rot_r * s->rot_r;
	discriminant = b * b - 4 * a * c;
	return (a_b_c_formula(a, b, discriminant));
}

t_point	sphere_intersection_p(t_sphere *s, t_ray *r)
{
	t_point	point;
	t_float	t;

	t = sphere_intersection(s, r);
	point = calc_endpoint_vector_nm(*r->v, *r->p, t);
	return (point);
}
