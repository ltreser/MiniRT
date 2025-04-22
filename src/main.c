/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoth <afoth@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 22:50:43 by afoth             #+#    #+#             */
/*   Updated: 2025/04/22 18:44:43 by ltreser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/miniRT.h"

void	render(t_rt *rt)
{
	setup_viewport(rt);
	frustum_culling(rt);
	render_loop(rt);
	mlx_loop(rt->mlx->connection);
	ft_close_window(rt);
}

int	main(int argc, char **argv)
{
	t_rt			*rt;

	rt = malloc(sizeof(t_rt));
	init(rt);
	if (input_correct(rt, argc, argv))
	{
		parse_input(rt, argv);
		check_completion(rt);
		mlx_create_window(rt);
		render(rt);
	}
	return (0);
}
