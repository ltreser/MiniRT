/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane_equations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoth <afoth@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 14:27:20 by afoth             #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2025/02/12 22:26:38 by afoth            ###   ########.fr       */
=======
/*   Updated: 2025/02/12 17:13:10 by ltreser          ###   ########.fr       */
>>>>>>> 214ad3d3056aacf6e1bb56346fbc6b70f4e675a5
/*                                                                            */
/* ************************************************************************** */

#include "../include/miniRT.h"

/* DEL
int	intersection_plane(double *t, t_plane *plane, t_ray *ray)
{
	t_vec3	v;
	double	k;
	double	b;

	copy_vec3(&v, ray->terminus);
	substract_vec3(&v, plane->point);
	k = dot_product_vec3(ray->vec, plane->norm); //scalar product
	b = dot_product_vec3(&v, plane->norm);
	if (k == 0)
	{
		*t = NO_ROOTS;
		return (1);
	}
	*t = -b / k;
	if (*t <= EPSILON_ROOT)
		*t = NO_ROOTS;
	return (*t == NO_ROOTS);
}*/
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

float	plane_ray_calc_t(t_plane *pl, t_ray *ray)
{
	float	divident;
	float	divisor;
	float	t;

	divisor = scalar_product(pl->v, ray->v);
	if(divisor == 0)
	{
		printf("Error\nPlane_ray_calc_t: devisor is 0\n");
		return(0);
	}
	divident = scalar_product((p_sub(ray->p, pl->p)), pl->v);
	t = divident/divisor;
	if(t < 0)
	{
		printf("Error\nPlane_ray_calc_t: intersecpoint is behind camera\n");
		return(0);
	}
	else
		return(0);
}
// Ray equation = p = lo + tl
// lo = startpoint ray,
// l = vektor ray
t_point	plane_ray_calc_p(t_ray ray, float t)
{
	t_point	point;

	retpoint = calc_endpoint_vector(ray.v, ray.p, t);
}
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

float	vector2component_form(t_point *p, t_vektor *v)
{

}

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
