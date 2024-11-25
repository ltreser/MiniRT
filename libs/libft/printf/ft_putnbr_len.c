/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_len.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltreser <ltreser@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 00:13:13 by ltreser           #+#    #+#             */
/*   Updated: 2023/07/18 00:23:15 by ltreser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_len(int n, int *plen)
{
	if (n == -2147483648)
	{
		ft_putstr_len("-2147483648", plen);
		return ;
	}
	if (n < 0)
	{
		ft_putchar_len('-', plen);
		n = -n;
	}
	if (n >= 10)
	{
		ft_putnbr_len((n / 10), plen);
	}
	ft_putchar_len((n % 10 + '0'), plen);
}
