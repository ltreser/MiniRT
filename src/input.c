/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoth <afoth@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 17:10:44 by ltreser           #+#    #+#             */
/*   Updated: 2024/12/09 21:14:16 by afoth            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/miniRT.h"

void check_format(t_rt *rt, char *arg)
{
	int i;

	i = ft_strlen(arg);
	if (i < 3 || arg[i - 3] != '.' || arg[i - 2] != 'r' || arg[i - 1] != 't')
		ft_exit(rt, 2, gc_strdup(rt->gc, FORMAT_FAIL));
}

int check_input(t_rt *rt, int argc, char **argv)
{
	int fd;

	if (argc > 2 || argc < 2)
	{
		ft_exit(rt, 2, gc_strdup(rt->gc, AC_FAIL));
	//	printf("goes here");
	}

	check_format(rt, argv[1]);
	fd = open(argv[1], O_RDONLY);
	if (!fd)
		ft_exit(rt, 2, gc_strdup(rt->gc, OPEN_FAIL));
	return (fd);
}

void read_file(int fd, t_rt *rt)
{
	char *line;

	line = NULL;
	line = get_next_line(fd);
	while (line)
	{
		ft_parse(line, rt);
		free(line);
		line = get_next_line(fd);
	}
	free(line);

}

