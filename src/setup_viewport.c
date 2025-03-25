/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_viewport.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoth <afoth@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 15:53:32 by afoth             #+#    #+#             */
/*   Updated: 2025/03/25 14:42:07 by afoth            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/miniRT.h"

//DEL width and height can be negative?!
void	setup_pixel(t_rt *rt)
{
	// printf("rt->vp->width %f\n", rt->vp->width);
	// printf("rt->vp->height %f\n", rt->vp->height);

	rt->vp->pixel_w = rt->vp->width/rt->mlx->width;
	rt->vp->pixel_h = rt->vp->height/rt->mlx->height;
	// printf("rt->vp->pixel_w %f\n", rt->vp->pixel_w);
	// printf("rt->vp->pixel_h %f\n\n\n", rt->vp->pixel_h);
	*rt->vp->pixel_v_x = v_mult_scalar_nm(*rt->vp->right, rt->vp->pixel_w);
	*rt->vp->pixel_v_y = v_mult_scalar_nm(*rt->vp->up, rt->vp->pixel_h);
}
//XXX the forward orientation vector = camera vector
void	setup_viewport(t_rt *rt) //TODO init struct variables
{
	printf("fov %i\n", rt->camera->fov);
	// float tang = tanf(((float)rt->camera->fov / 2))
	t_vector	plane_normal = {-0.0f, 0.0f, -1.0f};//DEBUG
	rt->vp->render_ray = init_ray(rt->gc);//init to NULL? right now to 0

	rt->vp->width = 2 * tanf(((float)rt->camera->fov / 2) * (PI / 180.0f));
	printf("rt->vp->width %f\n", rt->vp->width);
	calc_aspect_ratio(rt);
	printf("rt->aspect_r; %f\n", rt->aspect_r);
	rt->vp->height = rt->vp->width / rt->aspect_r;
	rt->vp->right = v_normalize(v_cross_product(rt, &(t_vector){0,1,0}, rt->camera->v));
	rt->vp->up = v_normalize(v_cross_product(rt, rt->vp->right, rt->camera->v));
	// rt->vp->up = &plane_normal;

	*(rt->vp->center) = vp_add_nm(*rt->camera->v, *rt->camera->p);
	*(rt->vp->top_left) = vp_add_nm(v_subtract_nm(v_mult_scalar_nm(*rt->vp->up, rt->vp->height / 2), v_mult_scalar_nm(*rt->vp->right, rt->vp->width / 2)), *rt->vp->center);
	*(rt->vp->top_right) = vp_add_nm(v_add_nm(v_mult_scalar_nm(*rt->vp->up, rt->vp->height / 2), v_mult_scalar_nm(*rt->vp->right, rt->vp->width / 2)), *rt->vp->center);
	// *(rt->vp->bottom_left) = pv_subtract_nm(*rt->vp->center, v_subtract_nm(v_mult_scalar_nm(*rt->vp->up, rt->vp->height / 2), v_mult_scalar_nm(*rt->vp->right, rt->vp->width / 2)));
	// *(rt->vp->bottom_right) = pv_subtract_nm(*rt->vp->center, v_add_nm(v_mult_scalar_nm(*rt->vp->up, (rt->vp->height / 2)), v_mult_scalar_nm(*rt->vp->right, (rt->vp->width / 2))));
	*(rt->vp->bottom_right) = vp_add_nm(v_add_nm(v_mult_scalar_nm(*rt->vp->right, rt->vp->width / 2),v_mult_scalar_nm(*rt->vp->up, -rt->vp->height / 2)),*rt->vp->center);
	*(rt->vp->bottom_left) = vp_add_nm(v_subtract_nm(v_mult_scalar_nm(*rt->vp->up, -rt->vp->height / 2),v_mult_scalar_nm(*rt->vp->right, rt->vp->width / 2)),*rt->vp->center);


	// print_point(*rt->vp->center, "\nrt->vp->center\n");
	// print_point(*rt->vp->top_left, "\nrt->vp->top_left\n");
	// print_point(*rt->vp->top_right, "\nrt->vp->top_right\n");
	// print_point(*rt->vp->bottom_left, "\nrt->vp->bottom_left\n");
	// print_point(*rt->vp->bottom_right, "\nrt->vp->bottom_right\n");
	rt->vp->vp_plane->p = rt->vp->bottom_left;
	// print_vector(*v_normalize(v_cross_product(rt, rt->vp->right, rt->vp->up)), "\nNORMALIZED shoud be equal to camera\n");
	// print_vector(*rt->camera->v,"CAMERA\n");

	rt->vp->vp_plane->v = rt->camera->v;
	// rt->vp->vp_plane->v = &plane_normal;

	// rt->vp->vp_plane->c->r = 0;
	// rt->vp->vp_plane->c->g = 0;
	// rt->vp->vp_plane->c->b = 0;
	setup_pixel(rt);//DEL?
}

