/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoth <afoth@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 22:50:43 by afoth             #+#    #+#             */
/*   Updated: 2025/04/19 19:17:31 by afoth            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/miniRT.h"

int	main(int argc, char **argv)
{
	double			runtime;
	t_rt			*rt;
	struct timeval	start;
	struct timeval	end;

	printf("\n\n\nTESTING: %s\n\n", argv[1]);
	gettimeofday(&start, NULL);
	rt = malloc(sizeof(t_rt));
	init(rt);
	if (input_correct(rt, argc, argv))
	{
		parse_input(rt, argv);
		mlx_create_window(rt);
		render(rt);
	}
	gettimeofday(&end, NULL);
	runtime = (end.tv_sec - start.tv_sec) + \
	(end.tv_usec - start.tv_usec) / 1e6;
	ft_gc_free(rt->gc);
	free(rt);
	printf("Runtime: %.6f seconds\n", runtime);
	return (0);
}
