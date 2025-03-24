/* void	ft_window_init(t_game *game)
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
 */
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: you <you@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 00:00:00 by you               #+#    #+#             */
/*   Updated: 2025/03/20 00:00:00 by you              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <math.h>

typedef struct s_vector {
	float	x;
	float	y;
	float	z;
}	t_vector, t_point;

typedef struct s_plane {
	t_point		*p;
	t_vector	*v;
}	t_plane;

typedef struct s_ray {
	t_point		*p;
	t_vector	*v;
}	t_ray;

float	scalar_product_nm(t_vector a, t_vector b)
{
	return (a.x * b.x + a.y * b.y + a.z * b.z);
}

t_vector	pp_sub_v_nm(t_point a, t_point b)
{
	t_vector	res;

	res.x = a.x - b.x;
	res.y = a.y - b.y;
	res.z = a.z - b.z;
	return (res);
}

t_point	calc_endpoint_vector_nm(t_vector dir, t_point origin, float t)
{
	t_point	result;

	result.x = origin.x + t * dir.x;
	result.y = origin.y + t * dir.y;
	result.z = origin.z + t * dir.z;
	return (result);
}

// Add your intersection functions here (from earlier)
float	plane_ray_calc_t(t_plane pl, t_ray ray)
{
	float		divident;
	float		divisor;
	t_vector	vector;
	float		t;

	printf("DEBUG: Starting plane_ray_calc_t()\n");

	printf("DEBUG: Plane normal:      (%f, %f, %f)\n", pl.v->x, pl.v->y, pl.v->z);
	printf("DEBUG: Ray direction:     (%f, %f, %f)\n", ray.v->x, ray.v->y, ray.v->z);

	divisor = scalar_product_nm(*pl.v, *ray.v);
	printf("DEBUG: Dot product (divisor): %f\n", divisor);

	if (divisor == 0)
	{
		printf("Error\nPlane_ray_calc_t: divisor is 0 (Ray is parallel to the plane)\n");
		return (NAN);
	}
	printf("\nVECTOR\n");

	printf("DEBUG: Ray point:     (%f, %f, %f)\n", ray.p->x, ray.p->y, ray.p->z);
	printf("DEBUG: Plane point:      (%f, %f, %f)\n", pl.p->x, pl.p->y, pl.p->z);
	vector = pp_sub_v_nm(*pl.p, *ray.p);
	printf("DEBUG: Vector from ray origin to plane point: (%f, %f, %f)\n\n",
		vector.x, vector.y, vector.z);

	divident = scalar_product_nm(vector, *pl.v);
	printf("DEBUG: Dot product (divident): %f\n", divident);

	t = divident / divisor;
	printf("DEBUG: Calculated t = %f\n", t);

	// Commented out section
	// if (t < 0)
	// {
	// 	printf("Error\nPlane_ray_calc_t: intersecpoint is behind camera\n");
	// 	return (NAN);
	// }

	return (t);
}

t_point	plane_ray_intersec(t_plane pl, t_ray ray)
{
	t_point	point;
	float	t;

	printf("DEBUG: Starting plane_ray_intersec()\n");

	t = plane_ray_calc_t(pl, ray);

	if (isnan(t))
	{
		printf("DEBUG: No intersection found (t is NaN)\n");
		return ((t_point){NAN, NAN, NAN});
	}

	point = calc_endpoint_vector_nm(*ray.v, *ray.p, t);
	printf("DEBUG: Intersection point: (%f, %f, %f)\n", point.x, point.y, point.z);

	return (point);
}

/* float	plane_ray_calc_t(t_plane pl, t_ray ray)
{
	float		divident;
	float		divisor;
	t_vector	vector;
	float		t;

	divisor = scalar_product_nm(*pl.v, *ray.v);
	if (divisor == 0)
	{
		printf("Error\nPlane_ray_calc_t: divisor is 0\n");
		return (NAN);
	}
	vector = pp_sub_v_nm(*pl.p, *ray.p);
	divident = scalar_product_nm(vector, *pl.v);
	t = divident / divisor;
	// if (t < 0)
	// {
	// 	printf("Error\nPlane_ray_calc_t: intersecpoint is behind camera\n");
	// 	return (NAN);
	// }
	// else
		return (t);
}

t_point	plane_ray_intersec(t_plane pl, t_ray ray)
{
	t_point	point;
	float	t;

	t = plane_ray_calc_t(pl, ray);
	point = calc_endpoint_vector_nm(*ray.v, *ray.p, t);
	return (point);
}
 */
int	main(void)
{
	// t_point	plane_origin = {1.0f, 1.0f, 2.0f};//r0
	// t_vector	plane_normal = {2.0f, 1.0f, 1.0f}; // n

	// t_point	ray_origin = {2.0f, 0.0f, 5.0f};//r1
	// t_vector	ray_dir = {3.0f, -4.0f, -1.0f}; // a
	t_point	plane_origin = {0.577350318f, 0.433012724f, 9.0f};//r0
	t_vector	plane_normal = {-0.0f, 1.0f, -0.0f}; // n

	t_point	ray_origin = {2.5f, -1.0f, -5.0f};//r1
	t_vector	ray_dir = {2.5f, -1.0f, -15.0f}; // a

	t_plane	plane = {&plane_origin, &plane_normal};
	t_ray	ray = {&ray_origin, &ray_dir};

	t_point	hit = plane_ray_intersec(plane, ray);

	printf("Intersection Point: (%.2f, %.2f, %.2f)\n", hit.x, hit.y, hit.z);
	return (0);
}












