/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoth <afoth@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 20:32:07 by ltreser           #+#    #+#             */
/*   Updated: 2024/11/28 20:25:49 by afoth            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int valid_float(const char *str, int *error_code)
{
	int i;

	i = 0;
	if (!(ft_isdigit(str[i]) || str[i] != '-'))
		*error_code = 4;
	if (str[i] == '-')
		i++;
	while (ft_isdigit(str[i]))
		i++;
	if (str[i] && str[i] != '.')
		*error_code = 4;
	while (ft_isdigit(str[i]))
		i++;
	if (str[i])
		*error_code = 4;
	if (*error_code = 0)
		return (1);
}

double	ft_atof(const char *str, int *error_code)
{
	double	result;
	double	power;
	char	*dec_point;
	int		sign;
	int		i;

	sign = 1;
	power = 1.0;
	if (!valid_float(str, error_code))
		return (4);
	if (str[0] == '-' && str++)
		sign = -1;
	result = (double)ft_atoi(str++);
	dec_point = ft_strchr(str, '.');
	if (dec_point)
	{
		i = dec_point - str + 1;
		while (ft_isdigit(str[i]) && result < FLT_MAX / 10)
		{
			result = result * 10.0 + (str[i++] - '0');
			power *= 10.0;
		}
	}
	return (result * sign / power);
}
