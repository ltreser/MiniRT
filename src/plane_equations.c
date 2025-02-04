/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane_equations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoth <afoth@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 14:27:20 by afoth             #+#    #+#             */
/*   Updated: 2025/02/04 16:18:44 by afoth            ###   ########.fr       */
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
	k = dot_product_vec3(ray->vec, plane->norm);
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
a = plane point, n = nomalized vektor plane
lo = startpoint ray, l vektor ray

Ray equation = p = lo + tl
P = lo + (- ((lo -a) *n)/(l *n)) *l
 */

t_point	*plane_ray_intersection(t_plane *pl, t_vector *v, t_point *p)
{

}


float	vector2component_form(t_point *p, t_vektor *v)
{

}

/*explanation:
given parameters:
-


t_point	ray_plane_intersect(float scalar, t_ray *ray, t_plane *plane)
{





}
