#include "../include/miniRT.h"

void	init(t_rt *rt)
{
	rt->fd = 0;
	rt->obj_count = 0;
	rt->gc = malloc(sizeof(t_gc));
	ft_gc_init(rt->gc);
	rt->mlx = gc_malloc(rt->gc, sizeof(t_mlx));
	rt->camera = NULL;
	rt->ambient = NULL;
	rt->light = NULL;
	rt->n_obj = 0;
}




