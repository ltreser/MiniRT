/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoth <afoth@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 18:19:20 by ltreser           #+#    #+#             */
/*   Updated: 2024/11/25 19:09:40 by afoth            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long	ft_whichsign(char c)
{
	if (c != 45 && c != 43)
		return (0);
	if (c == 45)
		return (-1);
	else
		return (1);
}

long	ft_atol(const char *av)
{
	long	i;
	long	sign;
	long	res;

	i = 0;
	sign = 1;
	res = 0;
	while (av[i] == 32 || av[1] == 9)
		i++;
	if (ft_whichsign(av[i]) != 0)
	{
		sign *= ft_whichsign(av[i]);
		i++;
	}
	while (av[i] && (av[i] >= 48 && av[i] <= 57))
	{
		res = (av[i] - '0') + (res * 10);
		i++;
	}
	return (sign * res);
}
