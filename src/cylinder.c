#include "../include/miniRT.h"

/* The equation for a more general
cylinder of radius r oriented along
a line pa + va *t:
(q - pa - (va,q - pa)va)^2 - r^2 = 0
where q = (x,y,z) is a point on the
cylinder.
To find intersection points with a ray p + vt,
substitute q = p + vt and solve:
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
float	cylinder_intersection(t_cylinder cyl, t_ray ray)
{
	t_vector	delta_p;
	t_vector	vector;
	t_vector	vector2;
	float		a;
	float		b;
	float		c;
	float		r;

	r = cyl.d/2;
	delta_p = pp_sub_v_nm(*ray.p, *cyl.p);
	vector = v_subtract_nm( *ray.v, v_mult_scalar_nm(*cyl.v, v_dot_product(ray.v, cyl.v)));
	a = scalar_product_nm(vector, vector);
	vector2 = v_subtract_nm(delta_p, v_mult_scalar_nm(*cyl.v, v_dot_product(&delta_p, cyl.v)));
	b = 2 * (v_dot_product(&vector, &vector2));
	c = scalar_product_nm(vector2, vector2) - (r*r);
	//ENDCAPS!!!
	return(abc_formula(a,b,c));
}

float calc_cyl_endcaps(t_cylinder cyl, t_ray ray)
{

}

//(−b±√(b^2−4ac))/2a
float	abc_formula(float a, float b, float c)
{
	float	t1;
	float	t2;
	float	tmp;
	float	discriminant;

	discriminant = b*b - 4.f*a*c;
	if (discriminant < 0.f)
		return -1.f;
	discriminant = sqrtf(discriminant);
	t1 = (- b + discriminant) / (2 * a);
	// (va, (p+v*t1)-p1) > 0 and (va, (p+v*t1)- p2) < 0 when nicht der fall return max float
	t2 = (- b - discriminant) / (2 * a);
	//REWORK
	if (t1 > t2)
	{
		tmp = t1;
		t1 = t2;
		t2 = tmp;
	}
	if (t1 > 0.f)//&& !max flaot
		return t1;
	if (t2 > 0.f)//&& !max flaot
		return t2;
	return -1.f;
}
