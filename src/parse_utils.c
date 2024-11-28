/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoth <afoth@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 14:50:34 by ltreser           #+#    #+#             */
/*   Updated: 2024/11/28 22:35:34 by afoth            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/miniRT.h"

void	parse_dimensions(t_rt *rt, char *str)
{
	int i;

	i = skip_spaces(str);
	rt->obj[rt->obj->count]->cy->d = ft_atof(ft_chop(str + i, ' '));
	i = skip_spaces(str);
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

int	only_valid_chars(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (i == 0 && (str[i] == 'A' || str[i] == 'C' || str[i] == 'L' || str[i] == 'c' || str[i] == 's' || str[i] == 'p'))
		else if (i = 1 && (str[i] == 'l' || str[i] == 'y' || str[i] == 'p' || str[i] == ' '))
		else if (str[i] == ',' || str[i] == '-' || str[i] == '.' || ft_isdigit(str[i]) || str[i] == ' ' || str[i] == '\n')
		else
			return (0);
		i++;
	}
	return (1);
}
