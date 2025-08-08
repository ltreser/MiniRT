/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bvh.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltreser <ltreser@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 14:09:45 by ltreser           #+#    #+#             */
/*   Updated: 2025/08/09 00:11:26 by ltreser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/miniRT.h"

//README 
//A Bounding Volume Hierarchy (BVH) is a tree structure used in 3D graphics and ray tracing to speed up intersection tests. It groups objects into nested bounding boxes (volumes), so you can quickly discard large sets of objects that don’t intersect a ray by testing their bounding boxes first. This reduces the number of expensive ray-object intersection tests, making rendering much faster. Each node in the BVH contains a bounding box that encloses all objects in its subtree, and the tree is built by recursively splitting objects based on their spatial distribution.

//PSEUDO 
// initialize, calculate bounding boxes for objects
// in a loop, recursively:		- create a node that contains all current objects (start with all) and a single AABB (axis aligned bounding box) entailing the current objects
//								- find division axis (the axis that has the most spread-out values, in this case the most difference between highest and lowest of e.g. y-value of the centrepoint for the y axis)
//								- sort the objects along this axis (e.g. by y-values)
//								- split them in half according to this order
//								- create node for both of these halfes
//								- repeat the process with(in) these nodes
// in the rendering loop, for each ray, check root bounding box intersection first, keep traversing the tree top-down, until you reach a(/multiple) leaf-nodes(objects) that the ray hits, only calculate intersection with this(/these) object(/s)
// this results in an efficiency of O(log(N)) instead of O(N)
// especially checking for intersections with bounding boxes is very cheap, so a lot of time can be saved.


//create axis-aligned bounding box (min and max value points) by using the radius of the sphere as minimum and maximum distance from the centre
void	create_sphere_bbox(t_rt *rt, int i)
{
	rt->obj[i]->bbox_min = (t_vector){rt->obj[i]->sphere->c->x
		- rt->obj[i]->sphere->rot_r, rt->obj[i]->sphere->c->y
		- rt->obj[i]->sphere->rot_r, rt->obj[i]->sphere->c->z
		- rt->obj[i]->sphere->rot_r};
	rt->obj[i]->bbox_max = (t_vector){rt->obj[i]->sphere->c->x
		+ rt->obj[i]->sphere->ror_r, rt->obj[i]->sphere->c->y
		+ rt->obj[i]->sphere->ror_r, rt->obj[i]->sphere->c->z
		+ rt->obj[i]->sphere->rot_r};
}

//create simple bounding boxes by taking the rotation radius of the cylinder as minimum and maximum distance of the centre
void	create_cylinder_bbox(t_rt *rt, int i)
{
	rt->obj[i]->bbox_min = (t_vector){rt->obj[i]->cylinder->c->x
		- rt->obj[i]->cylinder->rot_r, rt->obj[i]->cylinder->c->y
		- rt->obj[i]->cylinder->rot_r, rt->obj[i]->cylinder->c->z
		- rt->obj[i]->cylinder->rot_r
	rt->obj[i]->bbox_max = (t_vector){rt->obj[i]->cylinder->c->x
		+ rt->obj[i]->cylinder->ror_r, rt->obj[i]->cylinder->c->y
		+ rt->obj[i]->cylinder->ror_r, rt->obj[i]->cylinder->c->z
		+ rt->obj[i]->cylinder->rot_r
}

//loop through objects and create bounding boxes for cylinder and sphere, neglect plans because they are infinite
void	create_obj_bboxes(t_rt *rt)
{
	int	i;

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

//find the smallest value along a given axis
static int	find_smallest(t_rt *rt, char axis)
{
	int		i;
	t_float	smallest;

	i = 0;
	if (axis == 'x')
		smallest = rt->obj[0]->center->x;
	if (axis == 'y')
		smallest = rt->obj[0]->center->y;
	if (axis == 'z')
		smallest = rt->obj[0]->center->z;
	while (i < rt->obj_count)
	{
		if (axis == 'x' && smallest > rt->obj[i]->center->x)
			smallest = rt->obj[i]->center->x;
		if (axis == 'y' && smallest > rt->obj[i]->center->y)
			smallest = rt->obj[i]->center->y;
		if (axis == 'z' && smallest > rt->obj[i]->center->z)
			smallest = rt->obj[i]->center->z;
		i++;
	}
	return (smallest);
}

//find the biggest value along a given axis
static int	find_biggest(t_rt *rt, int axis)
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
		return (biggest);
}

//find the division axis by simply checking which axis has the biggest difference between its biggest and smallest value
void	find_division_axis(t_rt *rt)
{
	t_float	max_difference;

	char axis;
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

//initialize - malloc and transfer centre point into obj struct
void	init_bvh(t_rt *rt)
{
	int	i;

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
	int	i;

	i = 0;
}


//TODO only visible ones - through frustum culling?
//TODO fix minor bugs in code so far
//TODO sort objects ft for sorting along the corresponding axis
//TODO is_sorted ft in case int array already sorted
//TODO split int array in 2 ft -> that also manages the recursive call?
//TODO create bbox for current node
//TODO setup recursive loop for building binary tree with helper fts already written
//TODO implement in render loop

void	setup_bvh(t_rt *rt)
{
	init_bvh(rt);
	create_obj_bboxes(rt);
	//create_node_bbox //TODO
	find_division_axis(rt);
	sort_objects(rt);
	//TODO update init ft
	//TODO modify code so that not visible objs wont be calculated here
	//TODO alter code so that instaed of passing whole struct, pass the node, or smth, so that recursion can happen
	//TODO build recursive loop here	
}
