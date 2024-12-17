#include "../include/miniRT.h"

//XXX the forward orientation vector = camera vector
void	setup_viewport(t_rt *rt) //TODO init struct variables
{
	rt->vp->width = 2 * tanf(rt->camera->fov / 2);
	rt->vp->height = width / calc_aspect_ratio(t_rt *rt);
	rt->vp->distance = 1;
	rt->vp->rplane_o = v_normalize(v_cross_product(rt->gc, t_vec{0,0,0}, rt->camera->v));
	rt->vp->uplane_o = v_normalize(v_cross_product(rt->gc, rt->vp->rplane_o, rt->camera->v));
	rt->vp->center = pv_add(rt->gc, rt->camera->v, rt->camera->p);
	rt->vp->top_left = rt->vp->center + rt->vp->up * (rt->vp->height / 2) - rt->vp->right * (rt->vp->width / 2);
	rt->vp->top_right = rt->vp->center + rt->vp->up * (rt->vp->height / 2) + rt->vp->right * (rt->vp->width / 2);
	rt->vp->bottom_left = rt->vp->center - rt->vp->up * (rt->vp->height / 2) - rt->vp->right * (rt->vp->width / 2);
	rt->vp->bottom_right = rt->vp->center - rt->vp->up * (rt->vp->height / 2) + rt->vp->right * (rt->vp->width / 2);
}
	
	
