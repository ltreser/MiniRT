#include "../include/miniRT.h"

float	cylinder_rot_radius(t_rt *rt, t_cylinder *c)
{
	t_point		up_center;
	t_point		up_side;
	t_vector	arbitrary;
	it_vector	sideways;
	float		radius;

	up_center = calc_endpoint_vector(&c->v, &c->p, c->h / 2);
	arbitrary->x = 0.0;
	arbitrary->y = 1.0;
	arbitrary->z = 0.0;
	if (fabs(arbitrary->x) < 1e-6 && fabs(arbitrary-z) < 1e-6)
	{
		arbitrary->x = 0.0;
		arbitrary->y = 1.0;
		arbitrary->z = 0.0;
	}
	sideways = v_cross_product_nomalloc(arbitrary, c->vector);
	up_side	= calc_endpoint_vector(&sideways, &up_center, c->d/2);
	radius = v_between_two_points(c->p, up_side);
	return (radius);
}
