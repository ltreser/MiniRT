/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltreser <ltreser@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 14:50:34 by ltreser           #+#    #+#             */
/*   Updated: 2024/11/26 15:08:18 by ltreser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

void	parse_dimensions(t_rt *rt, char *str)
{
	int i;

	i = 0;
	while (str[i] == ' ')
		i++;
	rt->obj[rt->obj->count]->cy->d = ft_atof(ft_chop(str + i, ' '));
	i = 0;
	while (str[i] == ' ')
		i++;
	rt->obj[rt->obj->count]->cy->h = ft_atof(ft_chop(str + i, ' '));
	free(str);
	str = NULL;
}
