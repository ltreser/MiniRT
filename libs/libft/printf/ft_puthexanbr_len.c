/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexanbr_len.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltreser <ltreser@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 01:08:04 by ltreser           #+#    #+#             */
/*   Updated: 2023/07/18 20:35:22 by ltreser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_puthexanbr_len(unsigned long int nbr, char c, int *plen)
{
	const char	*lowercase;
	const char	*uppercase;

	lowercase = "0123456789abcdef";
	uppercase = "0123456789ABCDEF";
	if (c == 'p')
	{
		if (nbr == 0)
			return (ft_putstr_len("(nil)", plen));
		ft_putstr_len("0x", plen);
		c = 'x';
	}
	if (nbr >= 16)
	{
		ft_puthexanbr_len(nbr / 16, c, plen);
		ft_puthexanbr_len(nbr % 16, c, plen);
	}
	if (nbr < 16 && c == 'x')
		ft_putchar_len(lowercase[nbr], plen);
	if (nbr < 16 && c == 'X')
		ft_putchar_len(uppercase[nbr], plen);
}
