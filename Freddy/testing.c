/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: your_login <you@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 00:00:00 by your_login        #+#    #+#             */
/*   Updated: 2025/03/20 00:00:00 by your_login       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <math.h>

typedef struct s_vector
{
	float	x;
	float	y;
	float	z;
}	t_vector, t_point;

typedef struct s_ray
{
	t_point		*p;
	t_vector	*v;
}	t_ray;

t_vector	pp_sub_v_nm(t_point a, t_point b)
{
	t_vector	res;

	res.x = a.x - b.x;
	res.y = a.y - b.y;
	res.z = a.z - b.z;
	return (res);
}

t_vector	v_product_nm(t_vector a, t_vector b)
{
	t_vector	res;

	res.x = a.y * b.z - a.z * b.y;
	res.y = a.z * b.x - a.x * b.z;
	res.z = a.x * b.y - a.y * b.x;
	return (res);
}

float	v_len(t_vector vector)
{
	return (sqrtf(vector.x * vector.x + vector.y * vector.y + vector.z * vector.z));
}

float	distance_p_to_ray(t_point point, t_ray ray)
{
	t_vector	diff;
	t_vector	cross;
	float		distance;

	diff = pp_sub_v_nm(point, *ray.p);
	cross = v_product_nm(*ray.v, diff);

	printf("DEBUG: diff = (%f, %f, %f)\n", diff.x, diff.y, diff.z);
	printf("DEBUG: ray.v = (%f, %f, %f)\n", ray.v->x, ray.v->y, ray.v->z);
	printf("DEBUG: cross = (%f, %f, %f)\n", cross.x, cross.y, cross.z);

	distance = v_len(cross) / v_len(*ray.v);
	printf("DEBUG: distance = %f\n", distance);

	return (distance);
}

int	main(void)
{
	t_point		ray_origin = {1.0f, 1.0f, 4.0f};
	t_vector	ray_dir = {2.0f, -3.0f, 5.0f}; // along X-axis

	t_point		test_point = {1.0f, 5.0f, 3.0f}; // off the ray path

	t_ray		ray;
	float		dist;

	ray.p = &ray_origin;
	ray.v = &ray_dir;

	dist = distance_p_to_ray(test_point, ray);

	printf("Resulting perpendicular distance = %f\n", dist);
	return (0);
}


TESTING: orga/tests/main.rt


rt->vp->center
:0.000000 y:0.000000 z:9.000000
point
rt->vp->top_left
:0.577350 y:-0.433013 z:9.000000
point
rt->vp->top_right
:-0.577350 y:-0.433013 z:9.000000
point
rt->vp->bottom_left
:0.577350 y:0.433013 z:9.000000
point
rt->vp->bottom_right
:-0.577350 y:0.433013 z:9.000000

====== SPHERE DEBUG ======
point Position:1.500000 y:0.000000 z:-5.000000
Diameter: 2
point Upper Corner:2.500000 y:-1.000000 z:-5.000000
point Lower Corner:0.500000 y:1.000000 z:-5.000000

vector v:2.500000 y:-1.000000 z:-15.000000
point mask_corner:2.500000 y:-1.000000 z:-5.000000
point intersection point vp:-1.082532 y:0.433013 z:16.495192
point mask_corner:0.500000 y:1.000000 z:-5.000000
point intersection point vp:0.216506 y:0.433013 z:3.504809

