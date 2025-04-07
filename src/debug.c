/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoth <afoth@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 12:18:33 by afoth             #+#    #+#             */
/*   Updated: 2025/04/07 22:04:24 by afoth            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/miniRT.h"

void	print_vector(t_vector v, char *prompt)
{
	printf("vector %s:%f y:%f z:%f\n", prompt, v.x, v.y, v.z);
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
	// print_vector(*s->v, "Direction");
	// print_color("Color", *s->c);
	printf("Diameter: %d\n", s->d);
	// printf("Rotation (rad): %.2f\n", s->rot_r);
	print_point(*s->u_corner, "Upper Corner");
	print_point(*s->d_corner, "Lower Corner");
	printf("==========================\n");
}
