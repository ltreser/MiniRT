/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoth <afoth@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 12:18:33 by afoth             #+#    #+#             */
/*   Updated: 2025/04/17 22:42:36 by afoth            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/miniRT.h"

void	print_vector(t_vector v, char *prompt)
{
	printf("vector %s x:%f y:%f z:%f\n", prompt, v.x, v.y, v.z);
}

void	print_point(t_point p, char *prompt)
{
	printf("point %s x:%f y:%f z:%f\n", prompt, p.x, p.y, p.z);
}

void	print_sphere(t_sphere *s)
{
	if (!s)
	{
		printf("Sphere: (null)\n");
		return ;
	}
	printf("====== SPHERE DEBUG ======\n");
	print_point(*s->p, "Position");
	print_vector(*s->v, "Direction");
	printf("Diameter: %d\n", s->d);
	print_point(*s->u_corner, "Upper Corner");
	print_point(*s->d_corner, "Lower Corner");
	printf("==========================\n");
}

//Y is inverted because of MLX!!
void	renderpoint(t_rt *rt, t_point point, char *prompt)
{
	int		x;
	int		y;

	printf("%s ", prompt);
	x = calc_point_on_screen(rt, point, 'x');
	printf("x= %i ", x);
	y = calc_point_on_screen(rt, point, 'y');
	printf("y= %i\n", y);
	mlx_pixel_put(rt->mlx->connection, rt->mlx->window, x, y, 0xFF0000);
}

/* Calculating the 2D point
on the viewport of a 3d point.
The point has to lay on the screen
The tranformation is done by calculating the distance of the point to
the x and y axis of the viewport
1. Ray is created for the axis
2. Distance to axis is calculated and translated into pixels(dist_up / rt->vp->pixel_w)
ceilf is used to round up(no half pixels)*/
int	calc_point_on_screen(t_rt *rt, t_point point, char axis)
{
	t_ray		ray;
	t_float		dist_right;
	t_float		dist_up;

	ray.v = rt->vp->up;
	ray.p = rt->vp->bottom_left;
	if (axis == 'x')
	{
		dist_up = distance_p_to_ray(point, ray);
		return (ceilf(dist_up / rt->vp->pixel_w));
	}
	if (axis == 'y')
	{
		ray.v = rt->vp->right;
		dist_right = distance_p_to_ray(point, ray);
		return (ceilf(dist_right / rt->vp->pixel_h));
	}
	else
		return (-1);
}
