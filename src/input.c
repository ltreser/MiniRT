/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoth <afoth@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 17:10:44 by ltreser           #+#    #+#             */
/*   Updated: 2025/04/22 18:50:10 by ltreser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/miniRT.h"

void	check_format(t_rt *rt, char *arg)
{
	int	i;

	i = ft_strlen(arg);
	if (i < 3 || arg[i - 3] != '.' || arg[i - 2] != 'r' || arg[i - 1] != 't')
		ft_exit(rt, 2, gc_strdup(rt->gc, FORMAT_FAIL));
}

int	input_correct(t_rt *rt, int argc, char **argv)
{
	if (argc > 2 || argc < 2)
		ft_exit(rt, 2, gc_strdup(rt->gc, AC_FAIL));
	check_format(rt, argv[1]);
	rt->fd = open(argv[1], O_RDONLY);
	if (!rt->fd)
		ft_exit(rt, 2, gc_strdup(rt->gc, OPEN_FAIL));
	return (1);
}

void	parse_input(t_rt *rt, char **argv)
{
	char	*line;

	line = NULL;
	line = get_next_line(rt->fd);
	while (line)
	{
		ft_parse(line, rt, 1);
		free(line);
		line = get_next_line(rt->fd);
	}
	free(line);
	close(rt->fd);
	rt->obj = gc_malloc(rt->gc, sizeof(t_obj) * rt->obj_count);
	rt->fd = open(argv[1], O_RDONLY);
	if (!(rt->fd > 0))
		ft_exit(rt, 2, gc_strdup(rt->gc, OPEN_FAIL));
	line = get_next_line(rt->fd);
	while (line)
	{
		ft_parse(line, rt, 0);
		free(line);
		line = get_next_line(rt->fd);
	}
	free(line);
	close(rt->fd);
}

void	check_completion(t_rt *rt)
{
	if (!rt->camera)
		ft_exit(rt, 2, gc_strdup(rt->gc, FILE_FAIL));
}
