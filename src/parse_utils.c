/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoth <afoth@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 22:51:49 by afoth             #+#    #+#             */
/*   Updated: 2025/04/19 21:16:09 by ltreser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/miniRT.h"

int	skip_spaces(char *str)
{
	int	i;

	i = 0;
	while (str[i] == ' ')
		i++;
	return (i);
}

int	only_valid_chars(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (i == 0 && (str[i] == 'A' || str[i] == 'C' || str[i] == 'L'
				|| str[i] == 'c' || str[i] == 's' || str[i] == 'p'))
			i++;
		else if (i == 1 && (str[i] == 'l' || str[i] == 'y' || str[i] == 'p'
				|| str[i] == ' '))
			i++;
		else if (str[i] == ',' || str[i] == '-' || str[i] == '.'
			|| ft_isdigit(str[i]) || str[i] == ' ' || str[i] == '\n')
			i++;
		else
			return (0);
	}
	return (1);
}

void	is_nan(t_rt *rt, t_float f)
{
	if (isnan(f))
	{
		perror(FORMAT_FAIL);
		perror("NAN returned by ft_atof\n");
		ft_gc_free(rt->gc);
		exit(EXIT_INPUT);
	}
}
