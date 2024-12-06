/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoth <afoth@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 16:23:05 by ltreser           #+#    #+#             */
/*   Updated: 2024/12/06 19:59:32 by afoth            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/miniRT.h"

int	main(int argc, char **argv)
{
	t_rt *rt;
	int fd;
	struct timeval	start, end;

	fd = 0;
	gettimeofday(&start, NULL);
	rt = malloc(sizeof(t_rt));
	init(rt);
	fd = check_input(rt, argc, argv);
	read_file(fd, rt);
	// mlx_create_window(rt);
	//render(rt);
	gettimeofday(&end, NULL);
	double runtime = (end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec) / 1e6;
	//free_data(rt);
	printf("Runtime: %.6f seconds\n", runtime);
	return (0);
}

void	init(t_rt *rt)
{
	rt->gc = malloc(sizeof(t_gc));
	ft_gc_init(rt->gc);
}
