#include "../include/miniRT.h"

void	init(t_rt *rt)
{
	rt->gc = malloc(sizeof(t_gc));
	ft_gc_init(rt->gc);
	rt->mlx = NULL;
	rt->camera = NULL;
	rt->ambient = NULL;
	rt->light = NULL;
	rt->obj = gc_malloc(rt->gc, sizeof(t_obj));
	rt->n_obj = 0;
}




