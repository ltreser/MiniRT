#include "../include/miniRT.h"

void	malloc_fc(t_rt *rt) // have they been inited to 0/NULL?
{
	if (!rt->fc)
		rt->fc = gc_malloc(rt->gc, sizeof(t_fc));
	if (!rt->fc->uplane_n)
		rt->fc->uplane_n = gc_malloc(rt->gc, sizeof(t_vector));
	if (!rt->fc->dplane_n)
		rt->fc->dplane_n = gc_malloc(rt->gc, sizeof(t_vector));
	if (!rt->fc->rplane_n)
		rt->fc->rplane_n = gc_malloc(rt->gc, sizeof(t_vector));
	if (!rt->fc->lplane_n)
		rt->fc->lplane_n = gc_malloc(rt->gc, sizeof(t_vector));
	if (!rt->fc->uplane_p)
		rt->fc->uplane_p = gc_malloc(rt->gc, sizeof(t_point));
	if (!rt->fc->dplane_p)
		rt->fc->dplane_p = gc_malloc(rt->gc, sizeof(t_point));
	if (!rt->fc->rplane_p)
		rt->fc->rplane_p = gc_malloc(rt->gc, sizeof(t_point));
	if (!rt->fc->lplane_p)
		rt->fc->lplane_p = gc_malloc(rt->gc, sizeof(t_point));
}

/* calculation of the normals (perpendicular/senkrecht) that define the planes that border the vision field of the camera. we dont calculate a far plane because we dont restrict that,
	the side planes and upper
	+ lower are calculated by the cross product of a vektor thats calculated and a direction vektor. the near vector is not calculated because all of the planes start at the camera point
*/

void	calculate_fplanes(t_rt *rt)
{
	*rt->fc->rplane_n = v_normalize_nm(v_cross_product_nm(*rt->vp->up, v_between_two_points_nm(*rt->vp->top_right, *rt->vp->center)))G;
	*rt->fc->lplane_n = v_normalize_nm(v_cross_product_nm(v_between_two_points_nm(*rt->vp->bottom_left, *rt->vp->center), *rt->vp->up));
	*rt->fc->uplane_n = v_normalize_nm(v_cross_product_nm(v_between_two_points_nm(*rt->vp->top_left, *rt->vp->center), *rt->vp->right));
	*rt->fc->dplane_n = v_normalize_nm(v_cross_product_nm(*rt->vp->right, v_between_two_points_nm(*rt->vp->bottom_left, *rt->vp->center)));
}

/* calculate distance of the plane itself to the origin
 1) create vector from camera to origin
 2) use formular to generate projection of that vector on the norm vector of the plane (that means you calculate the component of that vector on the norm vector,
	this vector goes from the camera point to where the norm vector that goes to the origin from the plane starts.
 3) get the endpoint of that vector projection
 4) calculate the distance of that point from the origin */

void	calculate_fplane_distances(t_rt *rt)
{
	t_vector	cam2origin;	
	t_vector	c2o_rplane_n; // projection of cam2origin on the right planes normal
	t_vector	c2o_lplane_n;
	t_vector	c2o_uplane_n;
	t_vector	c2o_dplane_n;
	t_point		rplane_nstart;
	t_point		lplane_nstart;
	t_point		uplane_nstart;
	t_point		dplane_nstart;


//TODO distances arent calculated correctly, they should be negative (?)
	cam2origin = v_between_two_points_nm(*rt->camera->p, (t_point){0, 0, 0});
	c2o_rplane_n = vector_projection(cam2origin, *rt->fc->rplane_n);
	c2o_lplane_n = vector_projection(cam2origin, *rt->fc->lplane_n);
	c2o_uplane_n = vector_projection(cam2origin, *rt->fc->uplane_n);
	c2o_dplane_n = vector_projection(cam2origin, *rt->fc->dplane_n);
	rplane_nstart = vp_add_nm(c2o_rplane_n, *rt->camera->p);
	lplane_nstart = vp_add_nm(c2o_lplane_n, *rt->camera->p);
	uplane_nstart = vp_add_nm(c2o_uplane_n, *rt->camera->p);
	dplane_nstart = vp_add_nm(c2o_dplane_n, *rt->camera->p);
	rt->fc->rplane_d = calc_p_distance(rplane_nstart, (t_point){0, 0, 0});
	rt->fc->lplane_d = calc_p_distance(lplane_nstart, (t_point){0, 0, 0});
	rt->fc->uplane_d = calc_p_distance(uplane_nstart, (t_point){0, 0, 0});
	rt->fc->dplane_d = calc_p_distance(dplane_nstart, (t_point){0, 0, 0});
	printf("distance: %f\n", rt->fc->rplane_d);
	printf("distance: %f\n", rt->fc->lplane_d);
	printf("distance: %f\n", rt->fc->uplane_d);
	printf("distance: %f\n", rt->fc->dplane_d);
}

void	frustum_culling(t_rt *rt)
{
	int i;

	i = 0;
	malloc_fc(rt);
	calculate_fplanes(rt);
	calculate_fplane_distances(rt);
	while (i < rt->n_obj)
	{
		if (rt->obj[i]->type == CYLINDER || rt->obj[i]->type == SPHERE)
		{
			frustum_check_uplane(rt, i);
			frustum_check_dplane(rt, i);
			frustum_check_rplane(rt, i);
			frustum_check_lplane(rt, i);
		}
		i++;
	}
	i = 0;
	while (i < rt->n_obj)
	{
		if (rt->obj[i]->visible)
			printf("obj nr %d is visible\n", i);
		else
			printf("obj nr %d is NOT visible\n", i);
		i++;
	}
}
