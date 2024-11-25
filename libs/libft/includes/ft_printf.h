/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltreser <ltreser@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 22:13:37 by ltreser           #+#    #+#             */
/*   Updated: 2023/07/18 19:55:11 by ltreser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

int		specifier_check(const char *str, int i, int *plen, va_list *pargs);
int		ft_printf(const char *str, ...);
void	ft_putchar_len(char c, int *plen);
void	ft_puthexanbr_len(unsigned long int nbr, char c, int *plen);
void	ft_putnbr_len(int n, int *plen);
void	ft_putstr_len(char *str, int *plen);
void	ft_putunsnbr_len(unsigned int n, int *plen);

#endif
