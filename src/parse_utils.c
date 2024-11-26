/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoth <afoth@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 14:50:34 by ltreser           #+#    #+#             */
/*   Updated: 2024/11/26 16:40:51 by afoth            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

void	parse_dimensions(t_rt *rt, char *str)
{
	int i;

	i = skip_spaces(str)
	rt->obj[rt->obj->count]->cy->d = ft_atof(ft_chop(str + i, ' '));
	i = skip_spaces(str)
	rt->obj[rt->obj->count]->cy->h = ft_atof(ft_chop(str + i, ' '));
	free(str);
	str = NULL;
}
 int	skip_spaces(char *str)
 {
		int	i;

		i = 0;
		while (str[i] == ' ')
			i++;
		return(i);
 }
