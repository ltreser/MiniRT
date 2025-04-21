#include "../include/miniRT.h"


void	create_sphere_bbox(t_rt *rt, int i)
{
	rt->obj[i]->bbox_min = (t_vector){rt->obj[i]->sphere->c->x - rt->obj[i]->sphere->rot_r, rt->obj[i]->sphere->c->y - rt->obj[i]->sphere->rot_r, rt->obj[i]->sphere->c->z - rt->obj[i]->sphere->rot_r;
	rt->obj[i]->bbox_max = (t_vector){rt->obj[i]->sphere->c->x + rt->obj[i]->sphere->ror_r, rt->obj[i]->sphere->c->y + rt->obj[i]->sphere->ror_r, rt->obj[i]->sphere->c->z + rt->obj[i]->sphere->rot_r;
}

void	create_cylinder_bbox(t_rt *rt, int i)
{
	rt->obj[i]->bbox_min = (t_vector){rt->obj[i]->cylinder->c->x - rt->obj[i]->cylinder->rot_r, rt->obj[i]->cylinder->c->y - rt->obj[i]->cylinder->rot_r, rt->obj[i]->cylinder->c->z - rt->obj[i]->cylinder->rot_r
	rt->obj[i]->bbox_max = (t_vector){rt->obj[i]->cylinder->c->x + rt->obj[i]->cylinder->ror_r, rt->obj[i]->cylinder->c->y + rt->obj[i]->cylinder->ror_r, rt->obj[i]->cylinder->c->z + rt->obj[i]->cylinder->rot_r
}

void	create_obj_bboxes(t_rt *rt)
{
	int i;

	i = 0;
	while (i < obj_count)
	{
		if (rt->obj[i]->type == CYLINDER)
			create_cylinder_bbox(rt, i);
		if (rt->obj[i]->type == SPHERE)
			create_sphere_bbox(rt, i);
		i++;
	}
}

static int	find_smallest(t_rt *rt, int axis)
{
	int i;
	t_float smallest;

	i = 0;
	if (axis == 0)
		smallest = rt->obj[0]->center->x;
	if (axis == 1)
		smallest = rt->obj[0]->center->y;
	if (axis == 2)
		smallest = rt->obj[0]->center->z;
	while (i < rt->obj_count)
	{
		if (axis == 0 && smallest > rt->obj[i]->center->x)
			smallest = rt->obj[i]->center->x;
		if (axis == 1 && smallest > rt->obj[i]->center->y)
			smallest = rt->obj[i]->center->y;
		if (axis == 2 && smallest > rt->obj[i]->center->z)
			smallest = rt->obj[i]->center->z;
		i++;
	}	
}

static int      find_biggest(t_rt *rt, int axis)
{
        int	i;
        t_float biggest;

        i = 0;
        if (axis == 0)
                biggest = rt->obj[0]->center->x;
        if (axis == 1)
                biggest = rt->obj[0]->center->y;
        if (axis == 2)
                biggest = rt->obj[0]->center->z;
        while (i < rt->obj_count)
        {
                if (axis == 0 && biggest > rt->obj[i]->center->x)
                        biggest = rt->obj[i]->center->x;
                if (axis == 1 && biggest > rt->obj[i]->center->y)
                        biggest = rt->obj[i]->center->y;
                if (axis == 2 && biggest > rt->obj[i]->center->z)
                        biggest = rt->obj[i]->center->z;
                i++;
        }
}

void find_division_axis(t_rt *rt)
{
	t_float	max_difference;
	char axis

	max_difference = 0;
	max_difference = find_biggest(rt, x) - find_smallest(rt, x);
	axis = 'x';
	if (max_difference < find_biggest(rt, y) - find_smallest(rt, y))
	{
		max_difference = find_biggest(rt, y) - find_smallest(rt, y);
		axis = 'y';
	}
	if (max_difference < find_biggest(rt, z) - find_smallest(rt, z))
	{
		max_difference = find_biggest(rt, z) - find_smallest(rt, z);
		axis = 'z';
	}
	rt->bvh->axis = axis;
}

void	init_bvh(t_rt *rt)
{
	int i;

	i = 0;
	rt->bvh = gc_malloc(rt->gc, sizeof(t_bvh));

	while (i < rt->obj_count)
	{
		if (rt->obj[i] == CYLINER)
			rt->obj[i]->center = rt->obj[i]->cylinder->p;
		if (rt->obj[i] == SPHERE)
			rt->obj[i]->center = rt->obj[i]->sphere->p;
		i++;
	}
}

void	sort_objects(t_rt *rt)
{
	int i;

	i = 0;


}


//TODO only visible ones
//
void	setup_bvh(t_rt *rt)
{
	init_bvh(rt);
	create_obj_bboxes(rt);
	find_division_axis(rt);
	sort_objects(rt);

}
