#include "../include/miniRT.h"

//XXX the forward orientation vector = camera vector
void	setup_viewport(t_rt *rt) //TODO init struct variables
{
	rt->vp->viewport_width = 2 * tanf(rt->camera->fov / 2);
	rt->vp->viewport_height = viewport_width / calc_aspect_ratio(t_rt *rt);
	rt->vp->viewport_distance = 1;
	rt->vp->rplane_o = v_normalize(v_cross_product(t_vec{0,0,0}, rt->camera->v));
	rt->vp->uplane_o = v_normalize(v_cross_product(rt->vp->rplane_o, rt->camera->v));
}
	
	
