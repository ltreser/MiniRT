#include "../include/miniRT.h"

void	init(t_rt *rt)
{
	rt->fd = 0;
	rt->obj_count = 0;
	rt->gc = malloc(sizeof(t_gc));
	ft_gc_init(rt->gc);
	rt->mlx = gc_malloc(rt->gc, sizeof(t_mlx));
	calc_aspect_ratio(rt);
	rt->camera = NULL;
	rt->ambient = NULL;
	rt->light = NULL;
	rt->n_obj = 0;
	rt->fc = gc_malloc(rt->gc, sizeof(t_fc));
	init_viewport(rt);
}

void	init_viewport(t_rt *rt)
{
	rt->vp = gc_malloc(rt->gc, sizeof(t_vp));
	rt->vp->up = gc_malloc(rt->gc, sizeof(t_vector));
	rt->vp->right = gc_malloc(rt->gc, sizeof(t_vector));
	rt->vp->center = gc_malloc(rt->gc, sizeof(t_point));
	rt->vp->top_left = gc_malloc(rt->gc, sizeof(t_point));
	rt->vp->top_right = gc_malloc(rt->gc, sizeof(t_point));
	rt->vp->bottom_left = gc_malloc(rt->gc, sizeof(t_point));
	rt->vp->bottom_right = gc_malloc(rt->gc, sizeof(t_point));
}


