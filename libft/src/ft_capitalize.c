/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_capitalize.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltreser <ltreser@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 19:24:11 by ltreser           #+#    #+#             */
/*   Updated: 2024/12/05 20:49:40 by ltreser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*capitalize(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		if (ft_islower(str[i]))
			str[i] += 32;
	return (str);
}
