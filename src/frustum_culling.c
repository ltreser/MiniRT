#include "../include/miniRT.h"

void	malloc_fc(t_rt *rt)  // have they been inited to 0/NULL?
{
	rt->fc = gc_malloc(rt->gc, sizeof(t_fc));
	if (!rt->fc->uplane_n)
		rt->fc->uplane_n = gc_malloc(rt->gc, sizeof(t_vector);
	if (!rt->fc->dplane_n)
		rt->fc->dplane_n = gc_malloc(rt->gc, sizeof(t_vector);
	if (!rt->fc->rplane_n)
		rt->fc->rplane_n = gc_malloc(rt->gc, sizeof(t_vector);
	if (!rt->fc->lplane_n)
		rt->fc->lplane_n = gc_malloc(rt->gc, sizeof(t_vector);
	if (!rt->fc->uplane_p)
		rt->fc->uplane_p = gc_malloc(rt->gc, sizeof(t_point);
	if (!rt->fc->dplane_p)
		rt->fc->dplane_p = gc_malloc(rt->gc, sizeof(t_point);
	if (!rt->fc->rplane_p)
		rt->fc->rplane_p = gc_malloc(rt->gc, sizeof(t_point);
	if (!rt->fc->lplane_p)
		rt->fc->lplane_p = gc_malloc(rt->gc, sizeof(t_point);
}


//calculation of the normals (perpendicular/senkrecht) that define the planes that border the vision field of the camera. we dont calculate a far plane because we dont restrict that, the side planes and upper + lower are calculated by the cross product of a vektor thats calculated and a direction vektor. the near vector is not calculated because all of the planes start at the camera point.
void	calculate_fplanes(rt)
{
	rt->fc->rplane_n = v_normalize(v_cross_product(rt->vp->up, rt->vp->top_right
				- rt->vp->center));
	rt->fc->lplane_n = v_normalize(v_cross_product(rt->vp->bottom_left
				- rt->vp->center, rt->vp->up));
	rt->fc->uplane_n = v_normalize(v_cross_product(rt->vp->top_left
				- rt->vp->center, rt->vp->right));
	rt->fc->dplane_n = v_normalize(v_cross_product(rt->vp->right,
				rt->vp->bottom_left - rt->vp->center));
}

//calculate distance of the plane itself to the origin
void	calculate_fplane_distances(t_rt *rt)
{
	// calculate vector between camera and origin
	// this ray needs to be projected onto the plane
	// distance to origin and plane are perpendicular by default
	// so that means 
	// how do you calculate the distance? because all i have is one point, not the closest to the origin, on the planes. is there a fis there a formular?
	// @JorgeVinoRodriguez: You do a projection of the point onto the normal of the plane to find the closest point on the plane to the origin. There's a video about it somewhere in here.
	rt->fc->uplane_d = - (rt->vp->top_left - 

}

void	frustum_culling(t_rt *rt)
{
	if (!rt->fc)
		malloc_fc(rt);
	calculate_fplanes(rt);
	calculate_fplane_distances(rt);

}
