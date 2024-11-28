/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoth <afoth@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 17:11:57 by ltreser           #+#    #+#             */
/*   Updated: 2024/11/28 21:23:58 by ltreser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

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

void	parse_point(t_rt *rt, t_point point, char *str)
{
	//TODO only numbers, komma, point, minus
	int	i;
	int	start_of_nb

	i = skip_spaces(str)
	start_of_nb
	if(str[i] == '-')
		i++;
	while
}

//nomalized vektor
void	parse_vector(t_rt *rt, t_vector vector, char *str)
{

}
