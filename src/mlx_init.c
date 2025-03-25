/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoth <afoth@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 15:40:56 by afoth             #+#    #+#             */
/*   Updated: 2025/03/25 14:39:02 by afoth            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/miniRT.h"

int	ft_close_window(t_rt *rt)
{
	mlx_destroy_image(rt->mlx->connection, rt->mlx->img);
	mlx_destroy_window(rt->mlx->connection, rt->mlx->window);
	mlx_destroy_display(rt->mlx->connection);
	free(rt->mlx->connection);
	ft_exit(rt, 0, NULL);
	return (0);
}

int	keypress(int keycode, t_rt *rt)
{
	if (keycode == 65307)
		ft_close_window(rt);
	printf("keycode is: %d\n", keycode);
	return (0);
}
void	mlx_create_window(t_rt *rt)
{
	rt->mlx->x = 0;
	rt->mlx->y = 0;
	//mlx_get_screen_size(rt->mlx_ptr, &screen_width, &screen_height); TODO check if works
	rt->mlx->width = SCREEN_WIDTH; //TODO change later
	rt->mlx->height = SCREEN_HEIGHT; //TODO same
	rt->mlx->bpp = 24;
	rt->mlx->endian = 0;
	rt->mlx->line_len = rt->mlx->width * 3;
	rt->mlx->connection = mlx_init();
	if (!rt->mlx->connection)
		ft_exit(rt, 5, ft_strdup(MLX_FAIL));
	rt->mlx->window = mlx_new_window(rt->mlx->connection, rt->mlx->width, rt->mlx->height, "MiniRT");
	if (!rt->mlx->window)
	{
		mlx_destroy_display(rt->mlx->connection);
		ft_exit(rt, 5, ft_strdup(MLX_FAIL));
	}
	rt->mlx->img = mlx_new_image(rt->mlx->connection, rt->mlx->width, rt->mlx->height);
	if (!rt->mlx->img)
	{
		mlx_destroy_window(rt->mlx->connection, rt->mlx->window);
		mlx_destroy_display(rt->mlx->connection);
		ft_exit(rt, 5, ft_strdup(MLX_FAIL));
	}
	rt->mlx->pixel_adress = mlx_get_data_addr(rt->mlx->img, &rt->mlx->bpp, &rt->mlx->line_len, &rt->mlx->endian);
	//test DEL
	// mlx_pixel_put(rt->mlx->connection, rt->mlx->window, 0, 0, 0xFFFFFFFF);
	// mlx_pixel_put(rt->mlx->connection, rt->mlx->window, 1, 1, 0xFFFFFFFF);
	// mlx_pixel_put(rt->mlx->connection, rt->mlx->window, 2, 2, 0xFFFFFFFF);
	// mlx_pixel_put(rt->mlx->connection, rt->mlx->window, 3, 3, 0xFFFFFFFF);
	mlx_hook(rt->mlx->window, 2, 1L << 0, keypress, rt);
	mlx_hook(rt->mlx->window, 17, 1L << 17, ft_close_window, rt);

}



