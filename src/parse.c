/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltreser <ltreser@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 17:11:57 by ltreser           #+#    #+#             */
/*   Updated: 2024/11/25 18:02:14 by ltreser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

void    ft_parse(char *str, t_rt *rt)
{   
    int i;
    
    i = 0;
    while (str[i])
    {
 		if (str[i] == 'A' && !rt->ambient)
			parse_ambient(str, rt);
		if (str[i] == 'C' && !rt->camera)
			parse_camera(str, rt);
		if (str[i] == 'L' && !rt->light)
			parse_light(str, rt);
		if (!strncmp("sp ", str, 3) || !strncmp("pl ", str, 3) || !strncmp("cy ", str, 3))
			parse_obj(str + 3, rt, str[i]);
		else
			//error
}

void	parse_obj(char *str, t_rt *rt, char type)
{
	rt->obj->count++;
	parse_point(ft_chop(str), rt);
	parse_vector(ft_chop(str), rt);
	if (type == 'c')
		parse_dimensions(str, rt);
	parse_color(ft_chop(str), rt);
}

void	parse_point(char *str, t_rt *rt);
{
	//TODO only numbers, komma, point, minus

}

