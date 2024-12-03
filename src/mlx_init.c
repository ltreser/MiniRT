/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoth <afoth@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 15:40:56 by afoth             #+#    #+#             */
/*   Updated: 2024/12/03 20:17:14 by afoth            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/miniRT.h"

/* int	ft_close_window(t_rt *rt)
{
	mlx_destroy_window(rt->mlx->connection, rt->mlx->window);
	mlx_destroy_display(rt->mlx->connection);
}

int	keypress(int keycode, t_rt *rt)
{
	if (keycode == 65307)
		ft_close_window(rt);
}
//
void	mlx_create_window(t_rt *rt)
{
	rt->mlx->x = 0;
	rt->mlx->y = 0;
	//mlx_get_screen_size(rt->mlx_ptr, &screen_width, &screen_height); TODO check if works
	rt->mlx->width = 800; //TODO change later
	rt->mlx->height = 800; //TODO same
	rt->mlx->bpp = 24;
	rt->mlx->endian = 0;
	rt->mlx->line_len = rt->mlx->width * 3;
	rt->mlx->connection = mlx_init();
	if (!rt->mlx->connection)
		ft_exit(rt, 2, ft_strdup(FAIL_MLX)); //TODO is error code 2 correct here?
	rt->mlx->window = mlx_new_window(rt->mlx->connection, rt->mlx->width, rt->mlx->height);
	if (!rt->mlx->window)
	{
		mlx_destroy_display(rt->mlx->connection);
		ft_exit(rt, 2, ft_strdup(FAIL_MLX)); //TODO is error code 2 correct here?
	}
	rt->mlx->img = mlx_new_image(rt->mlx->connection, rt->mlx->width, rt->mlx->height);
	if (!rt->mlx->img)
	{
		mlx_destroy_window(rt->mlx->connection, rt->mlx->window);
		mlx_destroy_display(rt->mlx->connection);
		ft_exit(rt, 2, ft_strdup(FAIL_MLX)); //TODO is error code 2 correct here?
	}
	rt->mlx->pixel_adress = mlx_get_data_addr(rt->mlx->img, &rt->mlx->bpp, &rt->mlx->line_len, &rt->mlx->endian);
	//mlx_hook(rt->win_ptr, 17, 1L << 17, ft_close_window, rt);
	mlx_loop(rt->mlx_ptr);
	mlx_hook(rt->mlx->window, 2, 1L << 0, keypress, rt);
}
 */
