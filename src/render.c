
#include "../include/miniRT.h"

//Vector is multiplied by -0.5 for the middle point of the pixel
t_point	calc_startpoint_render(t_rt *rt)
{
	t_vector	vector;
	t_point		point;

	vector = v_add_nm(*rt->vp->pixel_v_y, *rt->vp->pixel_v_x);
	vector = v_mult_scalar_nm(vector, (t_float)0.5);
	point = p_add(vector, *rt->vp->bottom_left);
	return(point);
}

void	create_render_ray(t_rt *rt)
{
	*rt->vp->render_ray->p  =  *rt->camera->p;  //TODO problem: ray start point should be the camera
	*rt->vp->render_ray->v = v_between_two_points_nm(*rt->camera->p, calc_startpoint_render(rt));
	//error handling?
}
// void	render_sphere()
// {

// }

/* Check for closes distance (t)
This Point is rendert
tmp_t init
*/
void	obj_render_loop(t_rt *rt, t_ray *ray, int x, int y)
{
	int		i;
	int		min_t_obj;
	t_float	t;
	t_float	tmp_t;
	t_color	color;

	i = 0;
	t = MAX_RENDER;
	min_t_obj = -1;
	while(i < rt->obj_count)
	{
		// printf("I %i count %i\n", i, rt->obj_count);
		if(rt->obj[i]->visible == 1)
		{
			i = i;
			tmp_t = -1;
			if(rt->obj[i]->type == PLANE)
			{
				tmp_t = plane_ray_calc_t(*rt->obj[i]->plane, *ray);
				color = *rt->obj[i]->plane->c;

			}
			if(rt->obj[i]->type == SPHERE)
			{
		 	 	tmp_t = sphere_intersection(rt->obj[i]->sphere, ray);
				color = *rt->obj[i]->sphere->c;

			}
			if (rt->obj[i]->type == CYLINDER)
			{
				tmp_t = cylinder_intersection(*rt->obj[i]->cylinder, *ray);
				color = *rt->obj[i]->cylinder->c;
			}
			if(tmp_t > EPSILON && tmp_t < t)
			{
				t = tmp_t;
				min_t_obj = i;
			}
		}
		i++;
	}
	//no t found
	if(min_t_obj < 0)
	{
		mlx_pixel_put(rt->mlx->connection, rt->mlx->window, x, SCREEN_HEIGHT - 1 - y , 0x0000FF);
		return;
	}
	// printf("t = %f\n", t);
	// printf("t = %f y= %i x= %i\n", t, rt->vp->pixel_y, rt->vp->pixel_x);
	rt->n_obj = min_t_obj;
	color = lighting(rt, *(rt->obj[min_t_obj]), color, &t);

	// if (t > EPSILON)
	// {

	// // 	// printf("tmp_t = %f\n", tmp_t);
	// 	mlx_pixel_put(rt->mlx->connection, rt->mlx->window, x, SCREEN_HEIGHT - 1 - y , color_to_hex(color));
	// }
	// else
		mlx_pixel_put(rt->mlx->connection, rt->mlx->window, x, SCREEN_HEIGHT - 1 - y , color_to_hex(color));
		// mlx_pixel_put(rt->mlx->connection, rt->mlx->window, x, SCREEN_HEIGHT - 1 - y , 0xFFFFFF);

	// mlx_pixel_put(rt->mlx->connection, rt->mlx->window, x, y , 0xFFFFFF);

	//CALC LIGHTING ETC
	//unsigned int scale_color_by_value(struct s_color color, t_float value)
}


/* Main loop that sends out a ray for every pixel
Starts in the upper left corner. (xmin ymax)
Warning! in the mlx lib (rendering) y is inverted so y = 0 is the the highest up.
Our coordinate system 0.0 for the viewport is still at the bottom left corner for ease of thinking.
Rendering starts at the bootm left
*/
void render_loop(t_rt *rt)
{
	t_vector	start_vec;

	create_render_ray(rt);
	start_vec = *rt->vp->render_ray->v;
	// int i = 0;//DEL DEBUG
	// rt->vp->pixel_x = 0;
	rt->vp->pixel_y = SCREEN_HEIGHT - 1;
	//mlx_pixel_put(rt->mlx->connection, rt->mlx->window, 0, rt->vp->pixel_y, 0xFF00FF);
	while(rt->vp->pixel_y > 0)
	{
		rt->vp->pixel_x = 0;
		while(rt->vp->pixel_x < SCREEN_WIDTH)
		{
			obj_render_loop(rt, rt->vp->render_ray, rt->vp->pixel_x, rt->vp->pixel_y);


			if(rt->vp->pixel_x == 400 && rt->vp->pixel_y == 300)
				print_vector(*rt->vp->render_ray->v, "renderray");

			// mlx_pixel_put(rt->mlx->connection, rt->mlx->window, rt->vp->pixel_x, rt->vp->pixel_y , 0x0000FF);
			// if(i < 6)
			// i++;
			*rt->vp->render_ray->v = v_add_nm(*rt->vp->render_ray->v, *rt->vp->pixel_v_x);
			rt->vp->pixel_x++;
		}
		//RESET RAY
		*rt->vp->render_ray->v = start_vec;

		rt->vp->pixel_y--;
		*rt->vp->render_ray->v = v_add_nm(*rt->vp->render_ray->v, v_mult_scalar_nm(*rt->vp->pixel_v_y, rt->vp->pixel_y));
		// print_vector(*rt->vp->render_ray->v, "y");
		// printf("pixel y %i\n", rt->vp->pixel_y);
	}
	/*
	start: create ray pixel coord + camera
	start a the top most left pixel? y max x min
	Go throught obj array and see if obj is visble
	(y obj max <= y pixel >= y obj min;  if x obj max <= x pixel >= x obj min -> render)
	move ray
	call function related to obj type

	if point found-> retun t compare render smallest positve t
	if point not found/ behind camera-> return t negative

	y pixel++ until y max verschiebung vektor?

*/
}



void	render(t_rt *rt)
{
	printf("START OF RENDER\n");
	setup_viewport(rt);
	frustum_culling(rt);
	optimise_pixel_rendering(rt);
	render_loop(rt);


	//last FT in render!!!
	mlx_loop(rt->mlx->connection);
	ft_close_window(rt);
}
