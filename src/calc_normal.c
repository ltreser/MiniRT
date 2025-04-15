#include "../include/miniRT.h"
/* {
	t_vector n = normalize(*(plane->normal));

	// Check if normal is in the same direction as the ray
	if (dot_product(n, *(ray->v)) > 0)
		n = scale_vector(n, -1); // flip the normal

	return n;
} */

t_vector cal_normal_plane(t_rt *rt, t_obj obj, t_point p)
{
	t_vector	n;

	n = *(obj.plane->v);
	if(v_dot_product(&n, rt->vp->render_ray->v) > 0)
		n = v_mult_scalar_nm(n, -1);
	return(n);
}

//substract hitpoint from sphere center and making it len 1
t_vector	cal_normal_sphere(t_rt *rt, t_obj obj, t_point p)
{
	t_vector n;

	n = pp_sub_v_nm(p, *obj.sphere->p);
	return (v_normalize_nm(n));
}

// t_vector	cal_normal_cyl(t_rt *rt, t_obj obj, t_point p)
// {

// }

t_vector	cal_normal(t_rt *rt, t_obj obj, t_point p)
{
	if(obj.type == PLANE)
		return(cal_normal_plane(rt, obj, p));
	if(obj.type == SPHERE)
		return(cal_normal_sphere(rt, obj, p));
	// if (obj.type == CYLINDER)
	// 	return(cal_normal_cyl());}
}
