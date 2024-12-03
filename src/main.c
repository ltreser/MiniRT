/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoth <afoth@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 16:23:05 by ltreser           #+#    #+#             */
/*   Updated: 2024/12/03 16:54:18 by afoth            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/miniRT.h"

int	main(int argc, char **argv)
{
	t_rt *rt;
	int fd;
	struct timeval	start, end;

	gettimeofday(&start, NULL);
	rt = ft_gc_malloc(sizeof(rt));
	fd = 0;
	fd = check_input(rt, argc, argv);
	read_file(fd, rt);
		//render etc
	gettimeofday(&end, NULL);
	double runtime = (end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec) / 1e6;
	printf("Runtime: %.6f seconds\n", runtime);
}
