/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoth <afoth@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 17:11:57 by ltreser           #+#    #+#             */
/*   Updated: 2024/11/28 23:03:40 by afoth            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/miniRT.h"

void    ft_parse(char *str, t_rt *rt)
{
	if (only_valid_chars(str))
	{
 		if (str[i] == 'A' && !rt->ambient)
			parse_ambient(str, rt);
		if (str[i] == 'C' && !rt->camera)
			parse_camera(str, rt);
		if (str[i] == 'L' && !rt->light)
			parse_light(str, rt);
		if (!strncmp("sp ", str, 3) || !strncmp("pl ", str, 3) || !strncmp("cy ", str, 3))
			parse_obj(str + 3, rt, str[i]);
	}
	else
		ft_exit(rt, 2, ft_strdup(FILE_FAIL));
	}
}

void	parse_obj(char *str, t_rt *rt, char type)
{
	rt->obj[n_obj] = malloc(sizeof(t_obj));
	rt->obj[n_obj]->type = (t_enum)type;
	if (rt->obj[n_obj]->type == SPHERE)
		rt->obj[n_obj]->sphere = malloc(sizeof(t_sphere));
	if (rt->obj[n_obj]->type == PLANE)
		rt->obj[n_obj]->plane = malloc(sizeof(t_plane));
	if (rt->obj[n_obj]->type == CYLINDER)
		rt->obj[n_obj]->cylinder = malloc(sizeof(t_cylinder));
	rt->obj[n_obj]->sphere->parse_point(ft_chop(str, ' '), rt);
	parse_vector(ft_chop(str), rt);
	if (type == CYLINDER)
		parse_dimensions(str, rt);
	parse_color(ft_chop(str), rt);
	rt->n_obj++;
}

//0.0,0.0,-10.0
// 3 Punkte
// 2 Kommas
// max 3*-
t_point	*parse_point(t_rt *rt, char *str)
{
	t_point	*point;
	int		start_of_nb;

	point = ft_gc_malloc(rt->gc, sizeof(t_point));
	start_of_nb = skip_spaces(str);
	point->x= ft_atof(ft_chop(str + start_of_nb, ','));
	point->y= ft_atof(ft_chop(str, ','));
	point->z= ft_atof(ft_chop(str, ' '));
	return(point);
}

//nomalized vektor
t_vector	*parse_vector(t_rt *rt, char *str)
{
	t_vector	*vector;
	int			start_of_nb;

	vector = ft_gc_malloc(rt->gc, sizeof(t_vector));
	start_of_nb = skip_spaces(str);
	vector->x= ft_atof(ft_chop(str + start_of_nb, ','));
	vector->y= ft_atof(ft_chop(str, ','));
	vector->z= ft_atof(ft_chop(str, ' '));
	return(vector);
}
