
#include "../include/miniRT.h"

void	render(t_rt *rt)
{
	printf("START OF RENDER\n");
	setup_viewport(rt);
	frustum_culling(rt);
	//freddys box calculation
	//renderstuff
}
