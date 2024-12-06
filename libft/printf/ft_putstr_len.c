/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_len.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltreser <ltreser@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 23:49:00 by ltreser           #+#    #+#             */
/*   Updated: 2023/07/18 19:43:13 by ltreser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putstr_len(char *str, int *plen)
{
	int	i;

	i = 0;
	if (str == NULL)
	{
		write(1, "(null)", 6);
		(*plen) += 6;
	}
	else 
	{
		while (str[i])
		{
			write(1, &str[i], 1);
			(*plen)++;
			i++;
		}
	}
}
