/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_obj.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoth <afoth@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 17:23:23 by afoth             #+#    #+#             */
/*   Updated: 2025/04/19 21:22:55 by ltreser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/miniRT.h"

void	parse_dimensions(t_rt *rt, char *str)
{
	int	i;

	i = skip_spaces(str);
	if (rt->obj[rt->n_obj]->type == CYLINDER)
	{
		rt->obj[rt->n_obj]->cyl->d = ft_atof(gc_chop(rt->gc, str + i, ' '));
		i = skip_spaces(str);
		rt->obj[rt->n_obj]->cyl->h = ft_atof(gc_chop(rt->gc, str + i, ' '));
	}
	else if (rt->obj[rt->n_obj]->type == SPHERE)
		rt->obj[rt->n_obj]->s->d = ft_atof(gc_chop(rt->gc, str + i, ' '));
}

t_ray	*init_ray(t_gc *gc)
{
	t_ray	*ray;

	ray = gc_malloc(gc, sizeof(t_ray));
	if (!ray)
		return (NULL);
	ray->v = gc_malloc(gc, sizeof(t_vector));
	ray->p = gc_malloc(gc, sizeof(t_point));
	ray->p->x = 0;
	ray->p->y = 0;
	ray->p->z = 0;
	ray->v->x = 0;
	ray->v->y = 0;
	ray->v->z = 0;
	return (ray);
}

t_point	*init_point(t_gc *gc)
{
	t_point	*point;

	point = gc_malloc(gc, sizeof(t_point));
	if (!point)
		return (NULL);
	point->x = 0;
	point->y = 0;
	point->z = 0;
	return (point);
}

void	init_obj(t_rt *rt)
{
	if (rt->obj[rt->n_obj]->type == CYLINDER)
	{
		rt->obj[rt->n_obj]->cyl->u_corner = init_point(rt->gc);
		rt->obj[rt->n_obj]->cyl->d_corner = init_point(rt->gc);
		rt->obj[rt->n_obj]->cyl->rot_r = cylinder_rot_radius(rt,
				rt->obj[rt->n_obj]->cyl);
	}
	if (rt->obj[rt->n_obj]->type == SPHERE)
	{
		rt->obj[rt->n_obj]->s->u_corner = init_point(rt->gc);
		rt->obj[rt->n_obj]->s->d_corner = init_point(rt->gc);
		rt->obj[rt->n_obj]->s->rot_r = rt->obj[rt->n_obj]->s->d / 2;
	}
}
