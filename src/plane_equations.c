/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane_equations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoth <afoth@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 14:27:20 by afoth             #+#    #+#             */
/*   Updated: 2025/04/17 22:58:31 by afoth            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/miniRT.h"

/* DEL
// t = - ((lo -a) *n)/(l *n)
a = plane point,
n = nomalized vektor plane
lo = startpoint ray,
l vektor ray

Ray equation = p = lo + tl
P = lo + (- ((lo -a) *n)/(l *n)) *l

l*n = 0 Ray is parallel
(lo - a) * n = 0 Ray lies on the plane
(lo - a) * n != 0 no intersection? gpt!

t = - ((lo -a) *n)/(l *n)
result = ray->p + (-1*((ray->p - pl->p)* pl->v)/ (ray->v * pl->v)) * ray->v;
 */
t_float	plane_ray_calc_t(t_plane pl, t_ray ray)
{
	t_float		divident;
	t_float		divisor;
	t_vector	vector;
	t_float		t;

	divisor = scalar_product_nm(*pl.v, *ray.v);
	if (divisor == 0)
	{
		printf("Error\nPlane_ray_calc_t: devisor is 0\n");//DEL ERROR handeling this should be poosible !segfault prevent
		return (NAN);
	}
	vector = pp_sub_v_nm(*pl.p, *ray.p);
	divident = scalar_product_nm(vector, *pl.v);
	t = divident/divisor;
	// if (t < 0)
	// {
	// 	printf("Error\nPlane_ray_calc_t: intersecpoint is behind camera\n");//DEL frustum culling error
	// 	return (NAN);
	// }
	// else
		return (t);
}

t_point	plane_ray_intersec(t_plane pl, t_ray ray)
{
	t_point	point;
	t_float	t;

	t = plane_ray_calc_t(pl, ray);
	if (isnan(t))
		return ((t_point){NAN, NAN, NAN});
	point = calc_endpoint_vector_nm(*ray.v, *ray.p, t);
	return (point);
}
