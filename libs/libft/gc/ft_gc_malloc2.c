/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gc_malloc2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltreser <ltreser@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 16:00:07 by ltreser           #+#    #+#             */
/*   Updated: 2025/04/22 16:00:44 by ltreser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*gc_strdup(t_gc *gc, const char *s)
{
	char	*ptr;
	int		i;

	i = ft_strlen(s);
	ptr = (char *)gc_malloc(gc, sizeof(char) * (i + 1));
	if (!ptr)
		return (0);
	ptr[i] = '\0';
	while (--i >= 0)
		ptr[i] = s[i];
	return (ptr);
}

char	*gc_chop(t_gc *gc, char *str, char c)
{
	int		i;
	int		len;
	char	*chop;

	i = -1;
	len = 0;
	chop = NULL;
	if (!contains_c(str, c))
		return (str);
	while (str[len] && str[len] != c)
		len++;
	chop = gc_malloc(gc, (len + 1) * sizeof(char));
	while (str[++i] && i < len)
		chop[i] = str[i];
	chop[i++] = '\0';
	len = i;
	ft_memmove(str, str + len, (ft_strlen(str) - len));
	ft_bzero(str + (ft_strlen(str) - len), len);
	i = 0;
	while (str[i] == ' ')
		i++;
	ft_memmove(str, str + i, (ft_strlen(str) - i));
	ft_bzero(str + (ft_strlen(str) - i), i);
	return (chop);
}

char	*gc_strtrim(t_gc *gc, char const *s1, char const *set)
{
	size_t	i;
	size_t	ri;
	size_t	setlen;

	i = 0;
	ri = (ft_strlen(s1) - 1);
	setlen = ft_strlen(set);
	while (setlen--)
	{
		if (s1[i] == set[setlen])
		{
			i++;
			setlen = ft_strlen(set);
		}
	}
	setlen = ft_strlen(set);
	while (setlen--)
	{
		if (s1[ri] == set[setlen])
		{
			ri--;
			setlen = ft_strlen(set);
		}
	}
	return (gc_substr(gc, s1, i, (ri - i + 1)));
}
