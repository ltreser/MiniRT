/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoth <afoth@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 16:23:05 by ltreser           #+#    #+#             */
/*   Updated: 2024/12/05 20:37:18 by ltreser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/miniRT.h"

int	main(int argc, char **argv)
{
	t_rt *rt;
	int fd;
	struct timeval	start, end;

	gettimeofday(&start, NULL);
	rt = malloc(sizeof(rt));
	fd = 0;
	fd = check_input(rt, argc, argv);
	read_file(fd, rt);
	mlx_create_window(rt);
	//render(rt);
	gettimeofday(&end, NULL);
	double runtime = (end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec) / 1e6;
	//free_data(rt);
	printf("Runtime: %.6f seconds\n", runtime);
	return (0);
}
