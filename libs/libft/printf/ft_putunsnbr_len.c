/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsnbr_len.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltreser <ltreser@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 00:55:06 by ltreser           #+#    #+#             */
/*   Updated: 2023/07/18 19:45:06 by ltreser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putunsnbr_len(unsigned int n, int *plen)
{
	if (n >= 10)
	{
		ft_putnbr_len((n / 10), plen);
	}
	ft_putchar_len((n % 10 + '0'), plen);
}
