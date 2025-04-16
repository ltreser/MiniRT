//added (t_float)
result.r = ((t_float)(ambient.r + diffuse.r) / 255.0) * color.r;
result.g = ((t_float)(ambient.g + diffuse.g) / 255.0) * color.g;
result.b = ((t_float)(ambient.b + diffuse.b) / 255.0) * color.b;

//normalized v
*(ray.v) = v_normalize_nm(v_between_two_points_nm(*(ray.p), *(rt->light->p)));

changed EPSILON to 0,001



//old version yet
t_color	lighting(t_rt *rt, t_obj obj, t_color color, t_float *t)
{
	// create a ray between obj and light
	t_ray		ray;
	t_point		p;
	t_point		hitpoint;
	t_vector	v;
	t_vector	normal;
	t_color		diffuse;
	t_color		result;
	t_float		len_v;
	t_float		shadow_t;

	// assign internal pointers to stack memory
	ray.p = &p;
	ray.v = &v;
	*(ray.p) = calc_endpoint_vector_nm(*(rt->vp->render_ray->v), *(rt->vp->render_ray->p), *t);

	// *(ray.p) = calc_endpoint_vector_nm(*(rt->vp->render_ray->v), *(rt->vp->render_ray->p), *t);
	*(ray.v) = v_normalize_nm(v_between_two_points_nm(*(ray.p), *(rt->light->p)));
	normal = cal_normal(rt, obj, *(ray.p));
	*(ray.p) = calc_endpoint_vector_nm(normal, *(ray.p), EPSILON);
	len_v = v_len(*(ray.v)) - EPSILON;
	shadow_t = shadow_loop(rt, &ray, len_v);
	if(shadow_t < EPSILON)
		diffuse = calc_diffuse_light(rt, normal, *(ray.v));
	result = calculate_light(rt, color, diffuse);
	*t = shadow_t;
	return(result);

}
