/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoth <afoth@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 16:23:05 by ltreser           #+#    #+#             */
/*   Updated: 2024/11/20 16:43:43 by afoth            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/miniRT.h"


void	check_command_line_input(int argc, char **argv)
{
	if (argc > 2)
	{
		perror("Argument count greater then 2");
		exit(2);
	}
	//if (argv[1] does not end in rt)
	//error and exit
}
int	input(int argc, char **argv)
{
	int	fd;
	check_command_line_input(argc, argv);
	fd = open(argv[1], O_RDONLY);
	if (!fd)
	{
		perror("open failed");
		exit;
	}

}

int	main(int argc, char **argv)
{
	//check if it is an .rt file
	input(argc, argv);
	printf("HELLO");
}
