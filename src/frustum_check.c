#include "../include/miniRT.h"


//if object is on the other side of the plane (not inside of the frustum), dist_plane will be negative
void	frustum_check_uplane(t_rt *rt, int i)
{
	t_vector	*pos;
	float		pos_prime_len;
	float		dist_plane;

	t_vector *pos_prime; // position projected onto n
	if (rt->obj[i]->type == CYLINDER)
		pos = v_between_two_points({0, 0, 0}, rt->obj[i]->cylinder->p);
	else
		pos = v_between_two_points({0, 0, 0}, rt->obj[i]->sphere->p);
	pos_prime = vector_projection(pos, rt->fc->uplane_n);
	pos_prime_len = v_len(pos_prime);
	dist_plane = pos_prime_len + rt->fc->uplane_d;
	if (rt->obj[i]->type == CYLINDER)
		dist_plane += rt->obj[i]->cylinder->r;
	else
		dist_plane += rt->obj[i]->sphere->r;
	if (dist_plane > 0 && rt->obj[i]->visible == 1)
		rt->obj[i]->visible = 1;
	else
		rt->obj[i]->visible = 0;
}
