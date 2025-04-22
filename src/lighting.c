/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lighting.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoth <afoth@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 23:33:19 by afoth             #+#    #+#             */
/*   Updated: 2025/04/22 17:13:52 by afoth            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/miniRT.h"

//simple check if there is an obj between the light and the obj that is rendert
//find biggest t and compare to len obj light - EPSILON
t_float	shadow_loop(t_rt *rt, t_ray *ray, t_float len)
{
	int		i;
	t_float	tmp_t;

	i = 0;
	while (i < rt->obj_count)
	{
		tmp_t = -1;
		if (rt->obj[i]->type == PLANE)
			tmp_t = plane_ray_calc_t(*rt->obj[i]->pl, *ray);
		if (rt->obj[i]->type == SPHERE)
			tmp_t = sphere_intersection(rt->obj[i]->s, ray);
		if (rt->obj[i]->type == CYLINDER)
			tmp_t = cylinder_intersection(*rt->obj[i]->cyl, *ray);
		if (tmp_t > EPSILON && tmp_t < len)
			return (tmp_t);
		i++;
	}
	return (tmp_t);
}

t_color	calc_diffuse_light(t_rt *rt, t_vector normal, t_vector v_light)
{
	t_float	dot_product;
	t_color	diffuse;

	diffuse = (t_color){0, 0, 0,};
	dot_product = v_dot_product(&normal, &v_light);
	if (dot_product > EPSILON)
	{
		diffuse = col_mult_scalar(col_mult_scalar(*rt->light->c, \
			dot_product), rt->light->bright);
	}
	return (diffuse);
}

t_color	calculate_light(t_rt *rt, t_color color, t_color diffuse)
{
	t_color	result;
	t_color	ambient;

	ambient = *(rt->ambient->c);
	result.r = ((t_float)(ambient.r + diffuse.r) / 255.0) * color.r;
	result.g = ((t_float)(ambient.g + diffuse.g) / 255.0) * color.g;
	result.b = ((t_float)(ambient.b + diffuse.b) / 255.0) * color.b;
	if (result.r > 255.0)
		result.r = 255.0;
	if (result.g > 255.0)
		result.g = 255.0;
	if (result.b > 255.0)
		result.b = 255.0;
	return (result);
}

t_color	lighting(t_rt *rt, t_obj obj, t_color color, t_float t)
{
	t_color		diffuse;
	t_float		len_v;

	diffuse = (t_color){0, 0, 0};
	if (!rt->light)
		return (calculate_light(rt, color, diffuse));
	*(rt->intersec->hit_p) = calc_endpoint_vector_nm(*(rt->vp->render_ray->v), \
		*(rt->vp->render_ray->p), t);
	*(rt->intersec->ray->v) = v_normalize_nm(\
		v_between_two_points_nm(*(rt->intersec->hit_p), *(rt->light->p)));
	*(rt->intersec->normal) = cal_normal(rt, obj, *(rt->intersec->hit_p));
	*(rt->intersec->ray->p) = calc_endpoint_vector_nm(*(rt->intersec->normal), \
		*(rt->intersec->hit_p), EPSILON);
	len_v = v_len(v_between_two_points_nm(*(rt->intersec->ray->p), \
		*(rt->light->p))) - EPSILON;
	rt->intersec->shadow_t = shadow_loop(rt, rt->intersec->ray, len_v);
	if (rt->intersec->shadow_t < EPSILON)
	{
		diffuse = calc_diffuse_light(rt, *(rt->intersec->normal), \
			*(rt->intersec->ray->v));
		return (calculate_light(rt, color, diffuse));
	}
	else
		return (calculate_light(rt, color, diffuse));
}
