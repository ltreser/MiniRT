/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gc_malloc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltreser <ltreser@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 15:52:37 by ltreser           #+#    #+#             */
/*   Updated: 2025/04/22 16:03:34 by ltreser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

// Function to initialize the garbage collector
void	ft_gc_init(t_gc *gc)
{
	gc->next = NULL;
	gc->ptr = NULL;
}

// Function to allocate memory and add to garbage collector
// Set exit status to 1 for memory allocation failure
void	*gc_malloc(t_gc *gc, size_t size)
{
	void	*ptr;
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
		ft_gc_free(gc);
		perror(MALLOC_FAIL);
		free(ptr);
		exit(EXIT_FAILURE);
	}
	new_node->ptr = ptr;
	new_node->next = gc->next;
	gc->next = new_node;
	return (ptr);
}

// free rt?
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
	free(gc);
}

char	*gc_substr(t_gc *gc, const char *s, unsigned int start, size_t len)
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
	dest = (char *)gc_malloc(gc, (len + 1) * sizeof(char));
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
