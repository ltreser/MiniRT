/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gc_malloc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoth <afoth@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 17:04:07 by afoth             #+#    #+#             */
/*   Updated: 2024/12/05 20:06:15 by ltreser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/linft.h"

// Function to initialize the garbage collector
void	ft_gc_init(t_gc *gc)
{
	gc->next = NULL;
	gc->ptr = NULL;
}

// Function to allocate memory and add to garbage collector
// Set exit status to 1 for memory allocation failure
//TODO EXIT AND ERROR CODES
void	*ft_gc_malloc(t_rt *rt, size_t size)
{
	void		*ptr;
	t_gc	*new_node;

	ptr = malloc(size);
	if (!ptr)
	{
		perror(MALLOC_FAIL);
		exit(EXIT_FAILURE);
	}
	new_node = (t_gc *)malloc(sizeof(t_gc));
	if (!new_node)
	{
		//ft_gc_free
		perror(MALLOC_FAIL);
		free(ptr);
		exit(EXIT_FAILURE);
	}
	new_node->ptr = ptr;
	new_node->next = gc->next;
	gc->next = new_node;
	return (ptr);
}

//free rt?
void	ft_gc_free(t_gc *gc)
{
	t_gc	*tmp;

	while (gc->next)
	{
		tmp = gc->next;
		gc->next = tmp->next;
		free(tmp->ptr);
		free(tmp);
	}
}

char	*ft_gc_substr(const char *s, unsigned int start, size_t len)
{
	size_t	len_s;
	char	*dest;
	size_t	i;

	if (s == NULL)
		return (NULL);
	len_s = ft_strlen(s);
	if (start >= len_s || len == 0)
		return (NULL);
	if (len > len_s - start)
		len = len_s - start;
	if (len >= SIZE_MAX - 1)
		return (NULL);
	dest = (char *)ft_gc_malloc((len + 1) * sizeof(char));
	if (dest == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		dest[i] = s[start + i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_gc_strdup(const char *s)
{
	char	*ptr;
	int		i;

	i = ft_strlen(s);
	ptr = (char *) ft_gc_malloc(sizeof(char) * (i + 1));
	if (!ptr)
		return (0);
	ptr[i] = '\0';
	while (--i >= 0)
		ptr[i] = s[i];
	return (ptr);
}
