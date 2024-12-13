void	ft_window_init(t_game *game)
{
	game->mlx_ptr = mlx_init();
	if (game->mlx_ptr == NULL)
	{
		ft_printf("\nERROR\nMLX DID NOT INIT\n");
		free(game);
	}
	game->win_ptr = mlx_new_window(game->mlx_ptr, \
	game->pos_newline * 32, game->i_mapsize_y * 32, "DUCK DUCK GAME!");
	if (game->win_ptr == NULL)
		ft_error_win_ptr(game);
	mlx_hook(game->win_ptr, 2, 1L << 0, keypress, game);
	mlx_hook(game->win_ptr, 17, 1L << 17, ft_close_window, game);
	ft_graphics(game);
	mlx_loop(game->mlx_ptr);
	ft_close_window(game);
}

void	ft_graphics(t_game *game)
{
	ft_graphic_init(game);
	ft_open(game->arg, game);
	ft_build_map(game);
	ft_map_loop(game);
}

int	keypress(int keycode, t_game *game)
{
	if (keycode == 65307)
		ft_close_window(game);
	if (game->win == 0)
	{
		if (keycode == 119 || keycode == 65362)
			ft_move_up(game);
		if (keycode == 100 || keycode == 65363)
			ft_move_right(game);
		if (keycode == 115 || keycode == 65364)
			ft_move_down(game);
		if (keycode == 97 || keycode == 65361)
			ft_move_left(game);
	}
	if (game->win == 1)
	{
		if (keycode == 65293)
			ft_close_window(game);
	}
	ft_display_mov(game);
	ft_printf("Number of movement:%i\n", game->player_mov);
	return (0);
}

// put me to error and free.c
int	ft_close_window(t_game *game)
{
	ft_destroy_img(game);
	mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	mlx_destroy_display(game->mlx_ptr);
	ft_free_map(game);
	free(game->mlx_ptr);
	free(game);
	exit(0);
}
