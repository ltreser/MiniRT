#include "../include/miniRT.h"


//simple check if there is an obj between the light and the obj that is rendert
float	lighting_loop(t_rt *rt, t_ray *ray)
{
	int		i;
	// int		min_t_obj; might need to deturm color
	float	t;

	i = 0;
	t = -1;
	// min_t_obj = -1;
	while(i < rt->obj_count)
	{
		// printf("I %i count %i\n", i, rt->obj_count);

			i = i;
			t = -1;
			if(rt->obj[i]->type == PLANE)
			{
				t = plane_ray_calc_t(*rt->obj[i]->plane, *ray);
			}
			if(rt->obj[i]->type == SPHERE)
			{
				t = sphere_intersection(rt->obj[i]->sphere, ray);
			}
			if (rt->obj[i]->type == CYLINDER)
			{
				t = cylinder_intersection(*rt->obj[i]->cylinder, *ray);
			}
			if(t > 0)// && t < t)
			{
				return(t);
				// min_t_obj = i;
			}

		i++;
	}
	// if(min_t_obj < 0) //no t found
		// return;
	printf("t = %f\n", t);

	return(t);
}

float	lighting(t_rt *rt, float t)
{
	// create a ray between obj and light
	t_ray		ray;
	t_point		p;
	t_vector	v;

	// assign internal pointers to stack memory
	ray.p = &p;
	ray.v = &v;

	//cal point
	// t_point	calc_endpoint_vector_nm(t_vector v, t, float scalar)
	*(ray.p) = calc_endpoint_vector_nm(*(rt->vp->render_ray->v), *(rt->vp->render_ray->p), t);
	// renderpoint(rt, *(ray.p), "BLUB");
	*(ray.v) = v_between_two_points_nm(*(rt->light->p), *(ray.p));
	return(lighting_loop(rt, &ray));


	// calculate if obj between the start obj and the light, if so make it dark
}
