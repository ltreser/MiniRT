#include "../include/miniRT.h"

void	setup_viewport(t_rt *rt) //TODO init struct variables
{
	rt->viewport_width = 2 * tanf(rt->camera->fov / 2);
	rt->viewport_height = viewport_width / calc_aspect_ratio(t_rt *rt);

