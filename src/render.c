
#include "../include/miniRT.h"

//Vector is multiplied by -0.5 for the middle point of the pixel
t_point	calc_startpoint_render(t_rt *rt)
{
	t_vector	vector;
	t_point		point;

	vector = v_add_nm(*rt->vp->pixel_v_y, *rt->vp->pixel_v_x);
	vector = v_mult_scalar_nm(vector, (float)-0.5);
	point = p_add(vector, *rt->vp->top_left);
	return(point);
}

void	create_render_ray(t_rt *rt)
{
	*rt->vp->render_ray->p  = calc_startpoint_render(rt);
	*rt->vp->render_ray->v = v_between_two_points_nm(*rt->camera->p , *rt->vp->render_ray->p);
	//error handling?
}
// void	render_sphere()
// {

// }
void	obj_render_loop(t_rt *rt, t_ray *ray, int x, int y)
{
	int		i;
	float	t;

	i = 0;
	while(i < rt->obj_count)
	{
		// printf("LOOP\n");//DEL
		// printf("I %i count %i\n", i, rt->obj_count);
		if(rt->obj[i]->visible == 1)
		{
			rt->n_obj = i;
			if(rt->obj[i]->type == SPHERE)
			{
				t = sphere_intersection(rt->obj[rt->n_obj]->sphere, ray);
				if(t > 0)
				{
					printf("t = %f\n", t);
					mlx_pixel_put(rt->mlx->connection, rt->mlx->window, x, y , 0xFFFFFF);
					//rt->obj[i]->type == CYLINDER)
				}
			}

		}
		i++;
	}
}

void render_loop(t_rt *rt)
{
	create_render_ray(rt);
	int i = 0;//DEL DEBUG
	// rt->vp->pixel_x = 0;
	rt->vp->pixel_y = SCREEN_HEIGHT - 1;
	while(rt->vp->pixel_y >= 0)
	{
		rt->vp->pixel_x = 0;
		while(rt->vp->pixel_x < SCREEN_WIDTH)
		{
			obj_render_loop(rt, rt->vp->render_ray, rt->vp->pixel_x, rt->vp->pixel_y);
			// mlx_pixel_put(rt->mlx->connection, rt->mlx->window, rt->vp->pixel_x, rt->vp->pixel_y , 0xFFFFFF);
			// if(i < 6)
			// 	printf("Coord x: %i y: %i\n", rt->vp->pixel_x, rt->vp->pixel_y);
			i++;
			rt->vp->pixel_x++;
		}
		rt->vp->pixel_y--;
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
	// int	i;

	// i = 0;
	// while(i < rt->obj_count)
	// {
	// 	// printf("LOOP\n");//DEL
	// 	if(rt->obj[i]->visible == 1)
	// 	{

	// 	}
	// 	i++;
	// }

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
