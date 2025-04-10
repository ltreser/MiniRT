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
	
	r->v->x = 0;
	r->v->y = 0;
	r->v->z = -1;
	t = 0;
	r->p->x = 0;
	r->p->y = 0;
	r->p->z = 10;
	//printf("%f %f %f %f %f %f\n",r->p->x,r->p->y,r->p->z,s->p->x,s->p->y,s->p->z);
	vec = v_subtract_nm((t_vector){r->p->x,r->p->y,r->p->z}, (t_vector){s->p->x,s->p->y,s->p->z});
	a = (v_len(*r->v));
	a = a * a;
	//printf("this is vec: %f %f %f\n", vec.x, vec.y, vec.z);
	//printf("a is: %f\n", a);
	b = 2 * v_dot_product(r->v, &vec);
	//printf("b is: %f\n", b);
	c = (v_len(vec)) * (v_len(vec)) - s->rot_r * s->rot_r;
	//printf("c is: %f\n", c);
	discriminant = b * b - 4 * a * c;
	//printf("this is first part: %f\n", b * b);
	//printf("this is second part: %f\n", (-4 * a * c));
	//printf("this is the discriminant : %f\n", discriminant);
	if (discriminant < 0)
		return (-1);
	//printf("discriminant is: %f\n", discriminant);
	discriminant = sqrtf(discriminant);
	t = -(b + discriminant) / (2 * a);
	if (((-b - discriminant) / (2 * a)) > 0 && ((-b - discriminant) / (2 * a)) < t)
		t = ((-b - discriminant) / (2 * a));
	//printf("\nT IS: %f\n", t);
	if (t > 0) 
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
