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

//TODO what if t hasnt been set yet
float	cylinder_intersection(t_rt *rt, t_cylinder cyl, t_ray ray)
{
	float	cylinder_intersections[2];
	float	plane_intersections[2];
	float	t;

	// get infinite cylinder intersections first
	cylinder_intersections[0] = infinite_cylinder(cyl, ray, 0);
	cylinder_intersections[1] = infinite_cylinder(cyl, ray, 1);
	//exit(0);
	if (point_within_planes(rt, cyl, cylinder_intersections[0], ray))
		t = cylinder_intersections[0];// deault t that is valid bc its within the cylinder planes
	if (point_within_planes(rt, cyl, cylinder_intersections[1], ray) // check if valid t
		&& cylinder_intersections[0] > cylinder_intersections[1] // and also smaller than previous
		&& cylinder_intersections[1] > 0) // and also not negative
		t = cylinder_intersections[1]; // if so, change to superior t
	// get the infinite cylinder plane intersections
	plane_intersections[0] = infinite_planes(cyl, ray, 0);
	plane_intersections[1] = infinite_planes(cyl, ray, 1);
	if (point_within_circles(cyl, plane_intersections[0], ray) // check if valid bc within circles
		&& t > plane_intersections[0] // check if smaller than previous
		&& plane_intersections[0] > 0) // check if not negative
	t = plane_intersections[0]; // if so, change to superior t
	if (point_within_circles(cyl, plane_intersections[1], ray) // repeat process
		&& t > plane_intersections[1] && plane_intersections > 0)
		t = plane_intersections[1];
	return (t);
}

float	infinite_planes(t_cylinder cyl, t_ray ray, int flag)
{
	t_plane	planes[2];

	*planes[0].p = calc_endpoint_vector(cyl.v, cyl.p, cyl.h / 2);
	planes[0].v = cyl.v;
	*planes[1].p = calc_endpoint_vector(cyl.v, cyl.p, -(cyl.h / 2));
	*planes[1].v = v_mult_scalar_nm(*cyl.v, -1);
	if (flag == 0)
		return (plane_ray_calc_t(planes[0], ray));
	else
		return (plane_ray_calc_t(planes[1], ray));
}

int	point_within_circles(t_cylinder cyl, float intersection, t_ray ray)
{
	t_point		point;
	t_plane		planes[2];
	t_vector	center2point;

	point = calc_endpoint_vector(ray.v, ray.p, intersection);
	*planes[0].p = calc_endpoint_vector(cyl.v, cyl.p, cyl.h / 2);
	planes[0].v = cyl.v;
	*planes[1].p = calc_endpoint_vector(cyl.v, cyl.p, -(cyl.h / 2));
	*planes[1].v = v_mult_scalar_nm(*cyl.v, -1);
	center2point = v_between_two_points_nm(*cyl.p, point);
	if (v_dot_product(&center2point, planes[0].v) != 0)
		return (0);
	if (v_dot_product(&center2point, planes[1].v) != 0)
		return (0);
	if (v_len(center2point) > cyl.d / 2)
		return (0);
	return (1);
}

int	point_within_planes(t_rt *rt, t_cylinder cyl, float intersection, t_ray ray)
{
	t_point		point;
	t_plane		planes[2];
	t_vector	camera2point;

	point = calc_endpoint_vector(ray.v, ray.p, intersection);
	planes[0].v = cyl.v;
	//exit(0);
	*planes[1].v = v_mult_scalar_nm(*cyl.v, -1);
	exit(0);
	camera2point = v_between_two_points_nm(*rt->camera->p, point);
	if (v_dot_product(&camera2point, planes[0].v) > 0)
		return (0);
	if (v_dot_product(&camera2point, planes[1].v) > 0)
		return (0);
	return (1);
}

float	infinite_cylinder(t_cylinder cyl, t_ray ray, int flag)
{
	t_vector	delta_p;
	t_vector	vector[2];
	float		a;
	float		b;
	float		c;
	float		r;

	r = cyl.d / 2;
	delta_p = pp_sub_v_nm(*ray.p, *cyl.p);
	vector[0] = v_subtract_nm(*ray.v, v_mult_scalar_nm(*cyl.v,
				v_dot_product(ray.v, cyl.v)));
	vector[1] = v_subtract_nm(delta_p, v_mult_scalar_nm(*cyl.v,
				v_dot_product(&delta_p, cyl.v)));
	a = scalar_product_nm(vector[0], vector[0]);
	b = 2 * (v_dot_product(&vector[0], &vector[1]));
	c = scalar_product_nm(vector[1], vector[1]) - (r * r);
	if (flag = 0)
		return (abc_formula(a, b, c, 0));
	return (abc_formula(a, b, c, 1));
}

//(−b±√(b^2−4ac))/2a
// (va, (p+v*t1)-p1) > 0 and (va,
//(p+v*t1)- p2) < 0 when nicht der fall return max float

float	abc_formula(float a, float b, float c, int flag)
{
	float	tmp;
	float	discriminant;
	float	intersections[2];

	discriminant = b * b - 4.f * a * c;
	if (discriminant < 0.f)
		return (-1.f);
	discriminant = sqrtf(discriminant);
	if (flag = 0)
		return ((-b + discriminant) / (2 * a));
	else
		return ((-b - discriminant) / (2 * a));
}
