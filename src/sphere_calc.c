#include "../include/miniRT.h"


//TODO build in protection from vectors w length 0
float	sphere_intersection(t_sphere *s, t_ray *r)
{
	float t;
	float a;
	float b;
	float c;
	float discriminant;
	t_vector vec;

	t = 0;
	vec = v_subtract_nm(v_between_two_points_nm((t_point){0,0,0}, *r->p), v_between_two_points_nm((t_point){0,0,0}, *s->p));
	a = exp2f(v_len(*r->v));
	b = 2 * v_dot_product(r->v, &vec);
	c = exp2f(v_len(vec)) - s->rot_r * s->rot_r;
	discriminant = b * b - 4 * a * c;
	if (discriminant < 0)
		return (-1);
	t = -(b + discriminant) / (2 * a);
	if (((-b - discriminant) / (2 * a)) > 0 && ((-b - discriminant) / (2 * a)) < t)
		t = ((-b - discriminant) / (2 * a));
	return (t);
}

t_point sphere_intersection_p(t_sphere *s, t_ray *r)
{
	t_point	point;
	float	t;

	t = sphere_intersection(s, r);
	point = calc_endpoint_vector_nm(*r->v, *r->p, t);
	return (point);
}
