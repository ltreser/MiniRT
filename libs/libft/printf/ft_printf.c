/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltreser <ltreser@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 00:04:52 by ltreser           #+#    #+#             */
/*   Updated: 2023/08/06 21:39:52 by ltreser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	specifier_check(const char *str, int i, int *plen, va_list *pargs)
{
	if (str[i + 1] == 'c')
		ft_putchar_len((char)(va_arg(*pargs, int)), plen);
	else if (str[i + 1] == 's')
		ft_putstr_len((va_arg(*pargs, char *)), plen);
	else if (str[i + 1] == 'd' || str[i + 1] == 'i')
		ft_putnbr_len((va_arg(*pargs, int)), plen);
	else if (str[i + 1] == 'u')
		ft_putunsnbr_len((va_arg(*pargs, unsigned int)), plen);
	else if (str[i + 1] == 'p')
		ft_puthexanbr_len((va_arg(*pargs, unsigned long int)),
			str[i + 1], plen);
	else if (str[i + 1] == 'x' || str[i + 1] == 'X')
		ft_puthexanbr_len((unsigned long int)(va_arg(*pargs, unsigned int)), 
			str[i + 1], plen);
	else
		return (0);
	return (1);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		len;
	int		*plen;
	va_list	*pargs;

	plen = &len;
	pargs = &args;
	i = 0;
	len = 0;
	va_start(args, str);
	if (!str)
		return (-1);
	while (str[i])
	{
		if ((str[i] == '%' && str[i + 1] == '%' && ++i) || str[i] != '%')
			ft_putchar_len(str[i], plen);
		else if (str[i] == '%' && specifier_check(str, i, plen, pargs))
			i++;
		else
			return (0);
		i++;
	}
	va_end(args);
	return (len);
}
