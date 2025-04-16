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
/* float	cylinder_intersection(t_rt *rt, t_cylinder cyl, t_ray ray)
{
	float	cylinder_intersection1;
	float	cylinder_intersection2;
	float	plane_intersection1;
	float	plane_intersection2;
	float	t;

	t = -1;
	// get infinite cylinder intersections first
	cylinder_intersection1 = infinite_cylinder(cyl, ray, 0);
	cylinder_intersection2 = infinite_cylinder(cyl, ray, 1);
	//printf("cylinder intersection 1 is: %f\n", cylinder_intersection1);
	//printf("cylinder intersection 2 is: %f\n", cylinder_intersection2);
	//exit(0);
	if (point_within_planes(rt, cyl, cylinder_intersection1, ray))
		t = cylinder_intersection1;// deault t that is valid bc its within the cylinder planes
	printf("t is: %f\n", t);
	if (point_within_planes(rt, cyl, cylinder_intersection2, ray) // check if valid t
		&& (t < 0 || t > cylinder_intersection2) // and also smaller than previous
		&& cylinder_intersection2 > 0) // and also not negative
		t = cylinder_intersection2; // if so, change to superior t
	//printf("t is: %f\n", t);
	// get the infinite cylinder plane intersections
	plane_intersection1 = infinite_planes(cyl, ray, 0);
	plane_intersection2 = infinite_planes(cyl, ray, 1);
	//printf("plane intersection 1 is: %f\n", plane_intersection1);
	//printf("plane intersection 2 is: %f\n", plane_intersection2);
	if (point_within_circles(cyl, plane_intersection1, ray) // check if valid bc within circles
		&& (t < 0 || t > plane_intersection1) // check if smaller than previous
		&& plane_intersection1 > 0) // check if not negative
		t = plane_intersection1; // if so, change to superior t
	//printf("t is: %f\n", t);
	if (point_within_circles(cyl, plane_intersection2, ray) // repeat process
		&& (t < 0 || t > plane_intersection2) && plane_intersection2 > 0)
		t = plane_intersection2;
	printf("t is: %f\n", t);
	return (t);
} */

/* float	infinite_planes(t_cylinder cyl, t_ray ray, int flag)
{
	t_plane		plane1;
	t_vector	v1;
	t_point		p1;
	t_plane		plane2;
	t_vector	v2;
	t_point		p2;

	plane1.v = &v1;
	plane1.p = &p1;
	plane2.v = &v2;
	plane2.p = &p2;
	*plane1.p = calc_endpoint_vector(cyl.v, cyl.p, cyl.h / 2);
	plane1.v = cyl.v;
	*plane2.p = calc_endpoint_vector(cyl.v, cyl.p, -(cyl.h / 2));
	*plane2.v = v_mult_scalar_nm(*cyl.v, -1);
	if (flag == 0)
		return (plane_ray_calc_t(plane1, ray));
	else
		return (plane_ray_calc_t(plane2, ray));
} */

/* int	point_within_circles(t_cylinder cyl, float intersection, t_ray ray)
{
	t_point		point;
	t_plane		plane1;
	t_vector	v1;
	t_point		p1;
	t_plane		plane2;
	t_vector	v2;
	t_point		p2;
	t_vector	center2point;

	plane1.v = &v1;
	plane1.p = &p1;
	plane2.v = &v2;
	plane2.p = &p2;
	point = calc_endpoint_vector(ray.v, ray.p, intersection);
	*plane1.p = calc_endpoint_vector(cyl.v, cyl.p, cyl.h / 2);
	plane1.v = cyl.v;
	*plane2.p = calc_endpoint_vector(cyl.v, cyl.p, -(cyl.h / 2));
	*plane2.v = v_mult_scalar_nm(*cyl.v, -1);
	center2point = v_between_two_points_nm(*cyl.p, point);
	if (v_dot_product(&center2point, plane1.v) != 0)
		return (0);
	if (v_dot_product(&center2point, plane2.v) != 0)
		return (0);
	if (v_len(center2point) > cyl.d / 2)
		return (0);
	return (1);
} */

/* int	point_within_planes(t_rt *rt, t_cylinder cyl, float intersection, t_ray ray)
{
	t_point		point;
	t_plane		plane1;
	t_vector	v1;
	t_plane		plane2;
	t_vector	v2;
	t_vector	camera2point;
	t_vector	camera2point;


	plane1.v = &v1;
	plane2.v = &v2;
	point = calc_endpoint_vector(ray.v, ray.p, intersection);
	plane1.v = cyl.v;

	*plane2.v = v_mult_scalar_nm(*cyl.v, -1); //here segfault
	camera2point = v_between_two_points_nm(*rt->camera->p, point);
	if (v_dot_product(&camera2point, plane1.v) > 0)
		return (0);
	if (v_dot_product(&camera2point, plane2.v) > 0)
		return (0);
	return (1);
} */

float	infinite_cylinder(t_cylinder cyl, t_ray ray, int flag)
{
	t_vector	delta_p;
	t_vector	vector1;
	t_vector	vector2;
	float		a;
	float		b;
	float		c;
	float		r;

	r = cyl.d / 2;
	delta_p = pp_sub_v_nm(*ray.p, *cyl.p);
	vector1 = v_subtract_nm(*ray.v, v_mult_scalar_nm(*cyl.v,
				v_dot_product(ray.v, cyl.v)));
	vector2 = v_subtract_nm(delta_p, v_mult_scalar_nm(*cyl.v,
				v_dot_product(&delta_p, cyl.v)));
	a = scalar_product_nm(vector1, vector1);
	b = 2 * (v_dot_product(&vector1, &vector2));
	c = scalar_product_nm(vector2, vector2) - (r * r);
	if (flag == 0)
		return (abc_formula(a, b, c, 0));
	return (abc_formula(a, b, c, 1));
}

//(−b±√(b^2−4ac))/2a
// (va, (p+v*t1)-p1) > 0 and (va,
//(p+v*t1)- p2) < 0 when nicht der fall return max float

float	abc_formula(float a, float b, float c, int flag)
{
	// float	tmp;
	float	discriminant;
	// float	intersections[2];

	discriminant = b * b - 4.f * a * c;
	if (discriminant < 0.f)
		return (-1.f);
	discriminant = sqrtf(discriminant);
	if (flag == 0)
		return ((-b + discriminant) / (2 * a));
	else
		return ((-b - discriminant) / (2 * a));
}
