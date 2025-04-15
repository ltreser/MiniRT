#include "../include/miniRT.h"


//simple check if there is an obj between the light and the obj that is rendert
//find biggest t and compare to len obj light - EPSILON
float	lighting_loop(t_rt *rt, t_ray *ray, float len)
{
	int		i;
	// int		min_t_obj; might need to deturm color
	float	t;
	float	tmp_t;

	i = 0;
	t = -1;
	// min_t_obj = -1;
	while(i < rt->obj_count)
	{
		// printf("I %i count %i\n", i, rt->obj_count);
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
				tmp_t = cylinder_intersection(rt, *rt->obj[i]->cylinder, *ray);
			}
			if(tmp_t > t && tmp_t < len)
			{
				t = tmp_t;
				// min_t_obj = i;
			}
		i++;
	}
	// if(min_t_obj < 0) //no t found
		// return;
	// printf("t = %f\n", t);

	return(t);
}


float	lighting(t_rt *rt, t_obj obj, float t)
{
	// create a ray between obj and light
	t_ray		ray;
	t_point		p;
	t_vector	v;
	t_vector	normal;
	float		len_v;

	// assign internal pointers to stack memory
	ray.p = &p;
	ray.v = &v;

	//calc normal

	//cal point
	// t_point	calc_endpoint_vector_nm(t_vector v, t, float scalar)
	*(ray.p) = calc_endpoint_vector_nm(*(rt->vp->render_ray->v), *(rt->vp->render_ray->p), t);
	normal = cal_normal(rt, obj, *(ray.p));
	// renderpoint(rt, *(ray.p), "BLUB");
	*(ray.v) = v_between_two_points_nm(*(ray.p), *(rt->light->p));
	len_v = v_len(*(ray.v)) - EPSILON;
	return(lighting_loop(rt, &ray, len_v));


	// calculate if obj between the start obj and the light, if so make it dark
}
