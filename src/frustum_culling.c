#include "../include/miniRT.h"

void	malloc_fc(t_rt *rt)
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

void	calculate_fplane_distances(t_rt *rt)
{
	

}

void	frustum_culling(t_rt *rt)
{
	if (!rt->fc)
		malloc_fc(rt);
	calculate_fplanes(rt);
	calculate_fplane_distances(rt);
	
}
