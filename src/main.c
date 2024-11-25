/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoth <afoth@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 16:23:05 by ltreser           #+#    #+#             */
/*   Updated: 2024/11/25 16:58:01 by ltreser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/miniRT.h"

void	check_command_line_input(int argc, char **argv)
{
	if (argc > 2)
	{
		perror(AC_FAIL);
		ft_exit(2);
	}
}

check_format(char *arg)
{
	int i;
	
	i = ft_strlen(arg) - 1;
	if (arg[i] != EOF || arg[i-1] != 't' || arg[i-2] != 'r' || arg[i-3] != '.')
	{
		perror(AC_FAIL);
		exit(2);
	}
}

int	input_correct(int argc, char **argv)
{
	int	fd;
	
	check_command_line_input(argc, argv);
	check_format(argv[1]);
	fd = open(argv[1], O_RDONLY);
	if (!fd)
	{
		perror("OPEN_FAIL");
		exit;
	}
}

void read_file(char *file)
{
	
}

int	main(int argc, char **argv)
{
	if (input_correct)
	{
		read_file(argv[1]);
		//render etc
	}
	printf("HELLO");
}
