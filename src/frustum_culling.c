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

/*
void	calculate_fplanes(t_rt *rt)
{
	printf("\n");
	printf("\n");
	*rt->fc->rplane_n = v_normalize_nm(v_cross_product_nm(*rt->vp->up, v_between_two_points_nm(*rt->vp->top_right, *rt->vp->center)));
	print_vector(*rt->fc->rplane_n, "rplane normal");
	print_point(*rt->vp->top_right, "viewport top right");
	printf("\n");
	*rt->fc->lplane_n = v_normalize_nm(v_cross_product_nm(v_between_two_points_nm(*rt->vp->bottom_left, *rt->vp->center), *rt->vp->up));
	print_vector(*rt->fc->lplane_n, "lplane normal");
	print_point(*rt->vp->bottom_left, "viewport bottom left");
	printf("\n");
	*rt->fc->uplane_n = v_normalize_nm(v_cross_product_nm(v_between_two_points_nm(*rt->vp->top_left, *rt->vp->center), *rt->vp->right));
	print_vector(*rt->fc->uplane_n, "uplane normal");
	print_point(*rt->vp->top_left, "viewport top left");
	printf("\n");
	*rt->fc->dplane_n = v_normalize_nm(v_cross_product_nm(*rt->vp->right, v_between_two_points_nm(*rt->vp->bottom_left, *rt->vp->center)));
	print_vector(*rt->fc->dplane_n, "dplane normal");
	print_point(*rt->vp->bottom_right, "viewport bottom right");
	printf("\n");
	printf("\n");
}
*/
/*
void calculate_fplanes(t_rt *rt)
{
    printf("\n");
    printf("\n");

    // Right Plane Normal: Right vector cross Top-right to Center
    t_vector v1 = *rt->vp->right;
    t_vector v2 = v_between_two_points_nm(*rt->vp->top_right, *rt->vp->center);
    print_vector(v1, "Right vector");
    print_vector(v2, "Top-right to center");
    *rt->fc->rplane_n = v_normalize_nm(v_cross_product_nm(v1, v2));
    print_vector(*rt->fc->rplane_n, "rplane normal");
    print_point(*rt->vp->top_right, "viewport top right");
    printf("\n");

    // Left Plane Normal: Bottom-left to Center cross Right vector
    v1 = v_between_two_points_nm(*rt->vp->bottom_left, *rt->vp->center);
    v2 = *rt->vp->right;
    print_vector(v1, "Bottom-left to center");
    print_vector(v2, "Right vector");
    *rt->fc->lplane_n = v_normalize_nm(v_cross_product_nm(v1, v2));
    print_vector(*rt->fc->lplane_n, "lplane normal");
    print_point(*rt->vp->bottom_left, "viewport bottom left");
    printf("\n");

    // Up Plane Normal: Up vector cross Top-left to Center
    v1 = *rt->vp->up;
    v2 = v_between_two_points_nm(*rt->vp->top_left, *rt->vp->center);
    print_vector(v1, "Up vector");
    print_vector(v2, "Top-left to center");
    *rt->fc->uplane_n = v_normalize_nm(v_cross_product_nm(v1, v2));
    print_vector(*rt->fc->uplane_n, "uplane normal");
    print_point(*rt->vp->top_left, "viewport top left");
    printf("\n");

    // Down Plane Normal: Bottom-left to Center cross Up vector
    v1 = v_between_two_points_nm(*rt->vp->bottom_left, *rt->vp->center);
    v2 = *rt->vp->up;
    print_vector(v1, "Bottom-left to center");
    print_vector(v2, "Up vector");
    *rt->fc->dplane_n = v_normalize_nm(v_cross_product_nm(v1, v2));
    print_vector(*rt->fc->dplane_n, "dplane normal");
    print_point(*rt->vp->bottom_right, "viewport bottom right");
    printf("\n");

    printf("\n");
}*/

void calculate_fplanes(t_rt *rt)
{
    printf("\n");

    // Right Plane Normal: (Top-right - Center) x Up
    t_vector v1 = v_between_two_points_nm(*rt->camera->p, *rt->vp->top_right);
    t_vector v2 = v_between_two_points_nm(*rt->camera->p, *rt->vp->bottom_right);
    *rt->fc->rplane_n = v_normalize_nm(v_cross_product_nm(v2, v1));
    print_vector(*rt->fc->rplane_n, "rplane normal");
    print_point(*rt->vp->top_right, "viewport top right");
    printf("\n");

    // Left Plane Normal: Up x (Bottom-left - Center)
    v1 = v_between_two_points_nm(*rt->camera->p, *rt->vp->top_left);
    v2 = v_between_two_points_nm(*rt->camera->p, *rt->vp->bottom_left);
    *rt->fc->lplane_n = v_normalize_nm(v_cross_product_nm(v1, v2));
    print_vector(*rt->fc->lplane_n, "lplane normal");
    print_point(*rt->vp->bottom_left, "viewport bottom left");
    printf("\n");

    // Up Plane Normal: (Top-left - Center) x Right
    v1 = v_between_two_points_nm(*rt->camera->p, *rt->vp->top_left);
    v2 = v_between_two_points_nm(*rt->camera->p, *rt->vp->top_right);
    *rt->fc->uplane_n = v_normalize_nm(v_cross_product_nm(v2, v1));
    print_vector(*rt->fc->uplane_n, "uplane normal");
    print_point(*rt->vp->top_left, "viewport top left");
    printf("\n");

    // Down Plane Normal: Right x (Bottom-left - Center)
    v1 = v_between_two_points_nm(*rt->camera->p, *rt->vp->bottom_left);
    v2 = v_between_two_points_nm(*rt->camera->p, *rt->vp->bottom_right);
    *rt->fc->dplane_n = v_normalize_nm(v_cross_product_nm(v1, v2));
    print_vector(*rt->fc->dplane_n, "dplane normal");
    print_point(*rt->vp->bottom_right, "viewport bottom right");
    printf("\n");
}



/* calculate distance of the plane itself to the origin
--> this distance has to be negative, bc its the scalar that you need to multiply the frustum planes normal with in order to get to the origin
then you do a projection of the point on the plane, e.g. the camera point, onto the normal of the plane to find the closest point on the plane to the origin --> dont i already get a scalar as a result thats the distance?
 1) create vector from camera to origin
 2) use formular to generate projection of that vector on the norm vector of the plane (that means you calculate the component of that vector on the norm vector,
	this vector goes from the camera point to where the norm vector that goes to the origin from the plane starts.
 3) get the endpoint of that vector projection
 4) calculate the distance of that point from the origin */


/*
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
	printf("rplane_n: (%f, %f, %f)\n", rt->fc->rplane_n->x, rt->fc->rplane_n->y, rt->fc->rplane_n->z);
printf("lplane_n: (%f, %f, %f)\n", rt->fc->lplane_n->x, rt->fc->lplane_n->y, rt->fc->lplane_n->z);
printf("uplane_n: (%f, %f, %f)\n", rt->fc->uplane_n->x, rt->fc->uplane_n->y, rt->fc->uplane_n->z);
printf("dplane_n: (%f, %f, %f)\n", rt->fc->dplane_n->x, rt->fc->dplane_n->y, rt->fc->dplane_n->z);
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
	printf("cam2origin: (%f, %f, %f)\n", cam2origin.x, cam2origin.y, cam2origin.z);
	printf("distance: %f\n", rt->fc->rplane_d);
	printf("distance: %f\n", rt->fc->lplane_d);
	printf("distance: %f\n", rt->fc->uplane_d);
	printf("distance: %f\n", rt->fc->dplane_d);
	printf("c2o_rplane_n: (%f, %f, %f)\n", c2o_rplane_n.x, c2o_rplane_n.y, c2o_rplane_n.z);
	printf("c2o_lplane_n: (%f, %f, %f)\n", c2o_lplane_n.x, c2o_lplane_n.y, c2o_lplane_n.z);
	printf("c2o_uplane_n: (%f, %f, %f)\n", c2o_uplane_n.x, c2o_uplane_n.y, c2o_uplane_n.z);
	printf("c2o_dplane_n: (%f, %f, %f)\n", c2o_dplane_n.x, c2o_dplane_n.y, c2o_dplane_n.z);
}*/

void	calculate_fplane_distances(t_rt *rt)
{
    t_vector	cam2origin;

	cam2origin = v_between_two_points_nm(*rt->camera->p, (t_point){0, 0, 0});
	rt->fc->rplane_d = v_dot_product(rt->fc->rplane_n, &cam2origin);
// / v_len(*rt->fc->rplane_n);
	rt->fc->lplane_d = v_dot_product(rt->fc->lplane_n, &cam2origin);
// / v_len(*rt->fc->lplane_n);
	rt->fc->uplane_d = v_dot_product(rt->fc->uplane_n, &cam2origin);
// / v_len(*rt->fc->uplane_n);
	rt->fc->dplane_d = v_dot_product(rt->fc->dplane_n, &cam2origin);
// / v_len(*rt->fc->dplane_n);
	printf("distance to origin r: %f\n", rt->fc->rplane_d);
    printf("distance to origin l: %f\n", rt->fc->lplane_d);
    printf("distance to origin u: %f\n", rt->fc->uplane_d);
    printf("distance to origin d: %f\n", rt->fc->dplane_d);
}

/*void	frustum_culling(t_rt *rt)
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
}*/

void	frustum_culling(t_rt *rt)
{
	int i;
	float distance;
	float radius;
	t_vector v;

	i = 0;
	malloc_fc(rt);
	calculate_fplanes(rt);
	//calculate_fplane_distances(rt);
	while (i < rt->n_obj)
	{
		distance = -1;
		if (rt->obj[i]->type == SPHERE)
		{
			v = v_between_two_points_nm(*rt->camera->p, *rt->obj[i]->sphere->p);
			radius = rt->obj[i]->sphere->rot_r;
		}
		else if (rt->obj[i]->type == CYLINDER)
		{
			v = v_between_two_points_nm(*rt->camera->p, *rt->obj[i]->cylinder->p);	
			radius = rt->obj[i]->sphere->rot_r;
		}
		printf("%s: x = %f, y = %f, z = %f\n", "this is v", v.x, v.y, v.z);
		if (rt->obj[i]->type != PLANE)
		{
			distance = v_dot_product(&v, rt->fc->rplane_n) - radius;
			if (distance > 0)
					rt->obj[i]->visible = 0;
			distance = v_dot_product(&v, rt->fc->lplane_n) - radius ;
			if (distance > 0)
					rt->obj[i]->visible = 0;
			distance = v_dot_product(&v, rt->fc->dplane_n) - radius;		
			if (distance > 0)
					rt->obj[i]->visible = 0;
			distance = v_dot_product(&v, rt->fc->uplane_n) - radius;
			if (distance > 0)
					rt->obj[i]->visible = 0;
			break ;	
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
