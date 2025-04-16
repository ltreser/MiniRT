#include "../include/miniRT.h"


//simple check if there is an obj between the light and the obj that is rendert
//find biggest t and compare to len obj light - EPSILON
float	shadow_loop(t_rt *rt, t_ray *ray, float len)
{
	int		i;
	// int		min_t_obj; might need to deturm color
	float	t;
	float	tmp_t;

	i = 0;
	t = EPSILON;
	// min_t_obj = -1;
	while(i < rt->obj_count)
	{
		// printf("I %i count %i\n", i, rt->obj_count);
			tmp_t = -1;
			// if (i == rt->n_obj)
			// {
			// 	i++;
			// 	continue;
			// }
			if(rt->obj[i]->type == PLANE)
			{
				tmp_t = plane_ray_calc_t(*rt->obj[i]->plane, *ray);
			}
			if(rt->obj[i]->type == SPHERE)
			{
				tmp_t = sphere_intersection(rt->obj[i]->sphere, ray);
			}
			if (rt->obj[i]->type == CYLINDER)
			{
				//tmp_t = cylinder_intersection(rt, *rt->obj[i]->cylinder, *ray);
			}
			// shadow_hit->t > EPSILON && shadow_hit->t < max_len - EPSILON)
			if(tmp_t > EPSILON && tmp_t < len)
			{
				return(tmp_t);
				// min_t_obj = i;
			}
		i++;
	}
	// if(min_t_obj < 0) //no t found
		// return;
	// printf("t = %f\n", t);

	return(t);
}

t_color	col_mult_scalar(t_color color, float scalar)
{
	t_color	result;

	result.r = color.r * scalar;
	result.g = color.g * scalar;
	result.b = color.b * scalar;
	return(result);
}

t_color	col_add(t_color color_a, t_color color_b)
{
	t_color	result;

	result.r = color_a.r + color_b.r;
	result.g = color_a.g + color_b.g;
	result.b = color_a.b + color_b.b;
	return(result);
}

t_color	calc_diffuse_light(t_rt *rt, t_vector normal, t_vector v_light)
{
	// t_ray	light;
	float	dot_product;
	t_color	diffuse;
	t_color	temp_diffuse;
//
	diffuse = (t_color){0, 0, 0,};
	// while (l != NULL && hit_rec)
	// {
		// light.direction = vec_unit(vec_sub(l->point, hit_rec->point));
		// light.origin = l->point;
		// dot_product = fmax(vec_dot(hit_rec->normal, light.direction), EPSILON);
	dot_product = v_dot_product(&normal, &v_light);
	if(dot_product > EPSILON)
	{
		temp_diffuse = col_mult_scalar(col_mult_scalar(*rt->light->c, dot_product), rt->light->bright);
		diffuse = col_add(diffuse, temp_diffuse);
	}
	// temp_diffuse = col_mult(col_mult(l->color, dot_product), l->brightness);
	return (diffuse);
}

t_color	calculate_light(t_rt *rt, t_color color, t_color diffuse)
{
	t_color	result;
	t_color	ambient;

	ambient = col_mult_scalar(*rt->ambient->c, rt->ambient->ratio);
	result.r = ((ambient.r + diffuse.r) / 255.0) * color.r;
	result.g = ((ambient.g + diffuse.g) / 255.0) * color.g;
	result.b = ((ambient.b + diffuse.b) / 255.0) * color.b;
	if (result.r > 255.0)
		result.r = 255.0;
	if (result.g > 255.0)
		result.g = 255.0;
	if (result.b > 255.0)
		result.b = 255.0;
	return (result);
}

t_color	lighting(t_rt *rt, t_obj obj, t_color color, float *t)
{
	// create a ray between obj and light
	t_ray		ray;
	t_point		p;
	t_vector	v;
	t_vector	normal;
	t_color		diffuse;
	t_color		result;
	float		len_v;
	float		shadow_t;

	// assign internal pointers to stack memory
	ray.p = &p;
	ray.v = &v;

	//calc normal

	//cal point
	// t_point	calc_endpoint_vector_nm(t_vector v, t, float scalar)
	//ray.p hit point obj
	*(ray.p) = calc_endpoint_vector_nm(*(rt->vp->render_ray->v), *(rt->vp->render_ray->p), *t);
	normal = cal_normal(rt, obj, *(ray.p));
	*(ray.p) = calc_endpoint_vector_nm(normal, *(ray.p), EPSILON);
	*(ray.v) = v_between_two_points_nm(*(ray.p), *(rt->light->p));
	len_v = v_len(*(ray.v)) - EPSILON;
	shadow_t = shadow_loop(rt, &ray, len_v);
	if(shadow_t < EPSILON)
		diffuse = calc_diffuse_light(rt, normal, *(ray.v));


	result = calculate_light(rt, color, diffuse);
	*t = shadow_t;
	return(result);

	// calculate if obj between the start obj and the light, if so make it dark
}
