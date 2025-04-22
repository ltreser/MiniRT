/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoth <afoth@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 22:55:31 by afoth             #+#    #+#             */
/*   Updated: 2025/04/22 14:06:21 by ltreser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/miniRT.h"

void	ft_parse(char *str, t_rt *rt, int count_only)
{
	if (count_only)
		rt->obj_count += (!ft_strncmp("sp ", str, 3) || !ft_strncmp("pl ", str,
					3) || !ft_strncmp("cy ", str, 3));
	else if (only_valid_chars(str))
	{
		if (str[0] == 'A' && !rt->ambient && str[1] && str[1] == ' ')
			parse_ambient(rt, str + 2);
		else if (str[0] == 'A' && rt->ambient)
			ft_exit(rt, 4, AC_FAIL);
		if (str[0] == 'C' && !rt->camera && str[1] && str[1] == ' ')
			parse_camera(rt, str + 2);
		else if (str[0] == 'C' && rt->camera)
			ft_exit(rt, 4, AC_FAIL);
		if (str[0] == 'L' && !rt->light && str[1] && str[1] == ' ')
			parse_light(rt, str + 2);
		else if (str[0] == 'L' && rt->light)
			ft_exit(rt, 4, AC_FAIL);
		if (!ft_strncmp("sp ", str, 3) || !ft_strncmp("pl ", str, 3)
			|| !ft_strncmp("cy ", str, 3))
			assign_obj(rt, str);
	}
	else
		ft_exit(rt, 2, gc_strdup(rt->gc, FILE_FAIL));
}

void	parse_ambient(t_rt *rt, char *str)
{
	t_float	ratio;

	rt->ambient = gc_malloc(rt->gc, sizeof(t_ambient));
	str += skip_spaces(str);
	ratio = ft_atof(gc_chop(rt->gc, str, ' '));
	is_nan(rt, ratio);
	if (ratio < 0 || ratio > 1)
		ft_exit(rt, 2, gc_strdup(rt->gc, FILE_FAIL));
	rt->ambient->ratio = ratio;
	rt->ambient->c = parse_color(rt, gc_strtrim(rt->gc, str, "\n "));
	*(rt->ambient->c) = col_mult_scalar(*rt->ambient->c, rt->ambient->ratio);
}

void	parse_camera(t_rt *rt, char *str)
{
	int	fov;

	fov = -1;
	rt->camera = gc_malloc(rt->gc, sizeof(t_camera));
	str += skip_spaces(str);
	rt->camera->p = parse_point(rt, gc_chop(rt->gc, str, ' '));
	str += skip_spaces(str);
	rt->camera->v = parse_vec(rt, gc_chop(rt->gc, str, ' '));
	str += skip_spaces(str);
	fov = (int)ft_atof(gc_chop(rt->gc, str, '\n'));
	is_nan(rt, (t_float)fov);
	if (fov < 0 || fov > 180)
		ft_exit(rt, 2, gc_strdup(rt->gc, FILE_FAIL));
	rt->camera->fov = fov;
}

void	parse_light(t_rt *rt, char *str)
{
	t_float	bright;

	rt->light = gc_malloc(rt->gc, sizeof(t_light));
	str += skip_spaces(str);
	rt->light->p = parse_point(rt, gc_chop(rt->gc, str, ' '));
	str += skip_spaces(str);
	bright = ft_atof(gc_chop(rt->gc, str, ' '));
	is_nan(rt, bright);
	if (bright < 0 || bright > 1)
		ft_exit(rt, 2, gc_strdup(rt->gc, FILE_FAIL));
	rt->light->bright = bright;
	rt->light->c = parse_color(rt, gc_strtrim(rt->gc, str, "\n "));
}
