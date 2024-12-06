/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chop.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoth <afoth@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 19:25:35 by ltreser           #+#    #+#             */
/*   Updated: 2024/12/05 21:33:57 by afoth            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_chop(char *str, char c)
{
	int		i;
	int		len;
	char	*chop;

	i = 0;
	len = 0;
	chop = NULL;
	while (str[len] && str[len] != c)
		len++;
	chop = malloc((len + 1) * sizeof(char));
	while (str[i] && i < len)
	{
		chop[i] = str[i];
		i++;
	}
	chop[i++] = '\0';
	len = i;
	i = 0;
	ft_memmove(str, str + len, (ft_strlen(str) - len));
	ft_bzero(str + (ft_strlen(str) - len), len);
	return (chop);
}
