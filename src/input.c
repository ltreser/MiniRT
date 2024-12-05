/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoth <afoth@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 17:10:44 by ltreser           #+#    #+#             */
/*   Updated: 2024/12/05 20:20:01 by ltreser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/miniRT.h"

void check_format(t_rt *rt, char *arg)
{
	int i;

	i = ft_strlen(arg) - 1;
	if (arg[i] != EOF || arg[i-3] != '.' || arg[i-2] != 'r' || arg[i-1] != 't')
		ft_exit(rt, 2, ft_gc_strdup(FORMAT_FAIL));
}

int check_input(t_rt *rt, int argc, char **argv)
{
	int fd;
	if (argc > 2)
		ft_exit(rt, 2, ft_gc_strdup(AC_FAIL));
	check_format(rt, argv[1]);
	fd = open(argv[1], O_RDONLY);
	if (!fd)
		ft_exit(rt, 2, ft_gc_strdup(OPEN_FAIL));
	return (fd);
}

void read_file(int fd, t_rt *rt)
{
	char *line;

	line = NULL;
	line = get_next_line(fd);
	while (line)
	{
		if (line[0] != '\n')
			ft_parse(line, rt);
		line = get_next_line(fd);
	}	
}

