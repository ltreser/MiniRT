/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_obj.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoth <afoth@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 17:23:23 by afoth             #+#    #+#             */
/*   Updated: 2024/12/17 17:24:21 by afoth            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/miniRT.h"

void	parse_dimensions(t_rt *rt, char *str)
{
	int i;

	i = skip_spaces(str);
	if (rt->obj[rt->n_obj]->type == CYLINDER)
	{
		rt->obj[rt->n_obj]->cylinder->d = ft_atof(gc_chop(rt->gc, str + i, ' '));
		i = skip_spaces(str);
		rt->obj[rt->n_obj]->cylinder->h = ft_atof(gc_chop(rt->gc, str + i, ' '));
	}
	else if (rt->obj[rt->n_obj]->type == SPHERE)
		rt->obj[rt->n_obj]->sphere->d = ft_atof(gc_chop(rt->gc, str + i, ' '));
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
		rt->obj[rt->n_obj]->cylinder->x_corner = init_point(rt->gc);
		rt->obj[rt->n_obj]->cylinder->y_corner = init_point(rt->gc);
	}
	if (rt->obj[rt->n_obj]->type == SPHERE)
	{
		rt->obj[rt->n_obj]->sphere->x_corner = init_point(rt->gc);
		rt->obj[rt->n_obj]->sphere->y_corner = init_point(rt->gc);
	}
}