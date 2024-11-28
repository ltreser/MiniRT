/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoth <afoth@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 17:11:57 by ltreser           #+#    #+#             */
/*   Updated: 2024/11/28 22:28:25 by afoth            ###   ########.fr       */
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
	//TODO malloc for obj
	parse_point(ft_chop(str), rt);
	parse_vector(ft_chop(str), rt);
	if (type == 'c')
		parse_dimensions(str, rt);
	parse_color(ft_chop(str), rt);
	rt->obj->n++;
}
rt->camera->point = parse_point
//0.0,0.0,-10.0
// 3 Punkte
// 2 Kommas
// max 3*-
t_point	parse_point(t_rt *rt, char *str)
{
	//TODO only numbers, komma, point, minus
	t_point	*point;
	int	i;
	int nb_of_points
	int	nb_of_coordinates;
	int	start_of_nb;

	point = ft_gc_malloc(rt->gc, sizeof(t_point));
	nb_of_cordinates = 0;
	start_of_nb = skip_spaces(str);
	i = start_of_nb;
	point->x=
	point->y=
	point->z=
	while(nb_of_coordinates < 3)
	{
		if(str[i] == '-')
			i++;
		while

		nb_of_coordinates++;
	}
}

//nomalized vektor
void	parse_vector(t_rt *rt, t_vector vector, char *str)
{

}
