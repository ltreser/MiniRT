/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoth <afoth@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 15:40:56 by afoth             #+#    #+#             */
/*   Updated: 2024/12/03 18:29:52 by afoth            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/miniRT.h"

/* int	ft_close_window(t_rt *rt)
{
	mlx_destroy_window(rt->mlx_ptr, rt->win_ptr);
	mlx_destroy_display(rt->mlx_ptr);
	free(rt->mlx_ptr);
	free(rt);
	exit(0);
}

int	keypress(int keycode, t_rt *rt)
{
	if (keycode == 65307)
		ft_close_window(rt);
}
//
void	mlx_create_window(t_rt *rt)
{
	int screen_width;
	int screen_height;

	rt->mlx->connection = mlx_init();
	if (rt->mlx->connection == NULL)
	{
		perror("ERROR, MLX DID NOT INIT\n");
		//free stuff
		exit(1);
	}
	mlx_get_screen_size(rt->mlx_ptr, &screen_width, &screen_height);
	rt->win_ptr = mlx_new_window(rt->mlx_ptr, screen_width, screen_height, "MiniRT");
	if (rt->win_ptr == NULL)
		//error
	mlx_hook(rt->win_ptr, 2, 1L << 0, keypress, rt);
	//mlx_hook(rt->win_ptr, 17, 1L << 17, ft_close_window, rt);
	mlx_loop(rt->mlx_ptr);
}
 */
