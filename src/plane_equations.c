/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane_equations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoth <afoth@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 14:27:20 by afoth             #+#    #+#             */
/*   Updated: 2025/03/21 14:47:59 by afoth            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/miniRT.h"

/* DEL
/* t = - ((lo -a) *n)/(l *n)
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
float	plane_ray_calc_t(t_plane pl, t_ray ray)
{
	float		divident;
	float		divisor;
	t_vector	vector;
	float		t;

	divisor = scalar_product_nm(*pl.v, *ray.v);
	if(divisor == 0)
	{
		printf("Error\nPlane_ray_calc_t: devisor is 0\n");
		return(NAN);
	}
	vector = pp_sub_v_nm(*pl.p, *ray.p);
	divident = scalar_product_nm(vector, *pl.v);
	t = divident/divisor;
	if(t < 0)
	{
		printf("Error\nPlane_ray_calc_t: intersecpoint is behind camera\n");
		return(NAN);
	}
	else
		return(t);
}
/* #include <stdio.h>
#include <math.h>

float	plane_ray_calc_t(t_plane pl, t_ray ray)
{
    float		divident;
    float		divisor;
    t_vector	vector;
    float		t;

    printf("DEBUG: Starting plane_ray_calc_t function\n");

    // Debugging: Print input values
    printf("DEBUG: Plane normal vector (pl.v): [%f, %f, %f]\n", pl.v->x, pl.v->y, pl.v->z);
    printf("DEBUG: Ray direction vector (ray.v): [%f, %f, %f]\n", ray.v->x, ray.v->y, ray.v->z);

    divisor = scalar_product_nm(*pl.v, *ray.v);

    // Debugging: Check divisor
    printf("DEBUG: Calculated divisor (dot product): %f\n", divisor);

    if (divisor == 0)
    {
        printf("Error\nPlane_ray_calc_t: divisor is 0 (Ray is parallel to plane)\n");
        return (NAN);
    }

    vector = pp_sub_v_nm(*ray.p, *pl.p);

    // Debugging: Print vector from plane to ray origin
    printf("DEBUG: Vector from ray origin to plane point: [%f, %f, %f]\n",
           vector.x, vector.y, vector.z);

    divident = scalar_product_nm(vector, *pl.v);

    // Debugging: Check divident
    printf("DEBUG: Calculated divident (dot product): %f\n", divident);

    t = divident / divisor;

    // Debugging: Print calculated t-value
    printf("DEBUG: Calculated intersection t-value: %f\n", t);

    if (t < 0)
    {
        printf("Error\nPlane_ray_calc_t: intersection point is behind camera\n");
        return (NAN);
    }

    printf("DEBUG: Ray-plane intersection found at t = %f\n", t);
    return (t);
}
 */
t_point	plane_ray_intersec(t_plane pl, t_ray ray)
{
	t_point	point;
	float	t;

	t = plane_ray_calc_t(pl, ray);
	point = calc_endpoint_vector_nm(*ray.v, *ray.p, t);
	return(point);
}

// Ray equation = p = lo + tl
// lo = startpoint ray,
// l = vektor ray
/* int	plane_intersection(t_ray ray, t_plane plane, t_point *intersection)
{
	double	denom;
	double	t;
	t_vector	p0_to_origin;

	denom = dot_product(plane.normal, ray.direction);
	if (denom == 0) // Ray is parallel to the plane
		return (0);
	p0_to_origin = v_between_two_points(ray.origin, plane.point);
	t = dot_product(plane.normal, p0_to_origin) / denom;
	if (t < 0) // Intersection is behind the ray's origin
		return (0);
	intersection->x = ray.origin.x + t * ray.direction.x;
	intersection->y = ray.origin.y + t * ray.direction.y;
	intersection->z = ray.origin.z + t * ray.direction.z;
	return (1);
} */

// float	vector2component_form(t_point *p, t_vektor *v)
// {

// }

/*explanation:
given parameters:
-


t_point	ray_plane_intersect(float scalar, t_ray *ray, t_plane *plane)
{





}
*/

void	plane_check_fc(t_rt	*rt, int i)
{
//TODO
}
