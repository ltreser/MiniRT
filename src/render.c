
#include "../include/miniRT.h"

void	render(t_rt *rt)
{
	printf("START OF RENDER\n");
	setup_viewport(rt);
	frustum_culling(rt);
	optimise_pixel_rendering(rt);
	//renderstuff


	//last FT in render!!!
	mlx_loop(rt->mlx->connection);
	ft_close_window(rt);
}
