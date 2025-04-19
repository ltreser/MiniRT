
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


char    *gc_chop(t_gc *gc, char *str, char c)
{
        int             i;
        int             len;
        char    *chop;

        i = 0;
        len = 0;
        chop = NULL;
        if (!contains_c(str, c))
                return (str);
        while (str[len] && str[len] != c )
                len++;
        chop = gc_malloc(gc, (len + 1) * sizeof(char));
        while (str[i] && i < len)
        {
                chop[i] = str[i];
                i++;
        }
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
