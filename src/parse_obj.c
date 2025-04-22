/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_obj.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoth <afoth@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 22:06:26 by afoth             #+#    #+#             */
/*   Updated: 2025/04/22 19:03:03 by afoth            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/miniRT.h"

t_vector	*parse_vec(t_rt *rt, char *str)
{
	t_vector	*vector;
	t_float		len;

	vector = gc_malloc(rt->gc, sizeof(t_vector));
	vector->x = ft_atof(gc_chop(rt->gc, str, ','));
	is_nan(rt, vector->x);
	vector->y = ft_atof(gc_chop(rt->gc, str, ','));
	is_nan(rt, vector->y);
	vector->z = ft_atof(gc_chop(rt->gc, str, ' '));
	is_nan(rt, vector->z);
	len = v_len(*vector);
	if (fabsf(len - 1.0f) < 0.01)
		return (vector);
	else
	{
		perror(FORMAT_FAIL);
		write(1, "Vector not normalized\n", 22);
		ft_gc_free(rt->gc);
		exit(EXIT_INPUT);
	}
}

t_point	*parse_point(t_rt *rt, char *str)
{
	t_point	*point;

	point = gc_malloc(rt->gc, sizeof(t_point));
	point->x = ft_atof(gc_chop(rt->gc, str, ','));
	is_nan(rt, point->x);
	point->y = ft_atof(gc_chop(rt->gc, str, ','));
	is_nan(rt, point->y);
	point->z = ft_atof(gc_strtrim(rt->gc, str, "\n "));
	is_nan(rt, point->z);
	return (point);
}

t_color	*parse_color(t_rt *rt, char *str)
{
	t_color	*color;

	color = gc_malloc(rt->gc, sizeof(t_color));
	if (contains_c(str, '.'))
		ft_exit(rt, 2, gc_strdup(rt->gc, FILE_FAIL));
	str += skip_spaces(str);
	color->r = (int)ft_atof(gc_chop(rt->gc, str, ','));
	is_nan(rt, (t_float)color->r);
	if (color->r < 0 || color->r > 255)
		ft_exit(rt, 2, gc_strdup(rt->gc, FILE_FAIL));
	str += skip_spaces(str);
	color->g = (int)ft_atof(gc_chop(rt->gc, str, ','));
	is_nan(rt, (t_float)color->g);
	if (color->g < 0 || color->g > 255)
		ft_exit(rt, 2, gc_strdup(rt->gc, FILE_FAIL));
	str += skip_spaces(str);
	color->b = (int)ft_atof(gc_strtrim(rt->gc, str, "'\n' "));
	is_nan(rt, (t_float)color->b);
	if (color->b < 0 || color->b > 255)
		ft_exit(rt, 2, gc_strdup(rt->gc, FILE_FAIL));
	return (color);
}

void	assign_obj(t_rt *rt, char *str)
{
	rt->obj[rt->n_obj] = gc_malloc(rt->gc, sizeof(t_obj));
	rt->obj[rt->n_obj]->type = (t_type)sqrt((str[0] - 99) % 12);
	rt->obj[rt->n_obj]->visible = 1;
	parse_obj((str + 3) + skip_spaces(str + 3), rt);
}

void	parse_obj(char *str, t_rt *rt)
{
	if (rt->obj[rt->n_obj]->type == SPHERE)
	{
		rt->obj[rt->n_obj]->s = gc_malloc(rt->gc, sizeof(t_sphere));
		rt->obj[rt->n_obj]->s->p = parse_point(rt, gc_chop(rt->gc, str, ' '));
		parse_dimensions(rt, str);
		rt->obj[rt->n_obj]->s->c = parse_color(rt, str);
		init_obj(rt);
	}
	if (rt->obj[rt->n_obj]->type == PLANE)
	{
		rt->obj[rt->n_obj]->pl = gc_malloc(rt->gc, sizeof(t_plane));
		rt->obj[rt->n_obj]->pl->p = parse_point(rt, gc_chop(rt->gc, str, ' '));
		rt->obj[rt->n_obj]->pl->v = parse_vec(rt, gc_chop(rt->gc, str, ' '));
		rt->obj[rt->n_obj]->pl->c = parse_color(rt, str);
	}
	if (rt->obj[rt->n_obj]->type == CYLINDER)
	{
		rt->obj[rt->n_obj]->cyl = gc_malloc(rt->gc, sizeof(t_cylinder));
		rt->obj[rt->n_obj]->cyl->p = parse_point(rt, gc_chop(rt->gc, str, ' '));
		rt->obj[rt->n_obj]->cyl->v = parse_vec(rt, gc_chop(rt->gc, str, ' '));
		parse_dimensions(rt, str);
		rt->obj[rt->n_obj]->cyl->c = parse_color(rt, str);
		init_obj(rt);
	}
	rt->n_obj++;
}
