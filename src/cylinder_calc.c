
#include "../include/miniRT.h"

 t_float	cylinder_rot_radius(t_rt *rt, t_cylinder *c)
{
	t_point		up_center;
	t_point		up_side;
	t_vector	arbitrary;
	t_vector	sideways;
	t_float		radius;

	up_center = calc_endpoint_vector(c->v, c->p, c->h / 2);
	arbitrary.x = 0.0;
	arbitrary.y = 1.0;
	arbitrary.z = 0.0;
	if (fabs(arbitrary.x) < 1e-6 && fabs(arbitrary.z) < 1e-6)
	{
		arbitrary.x = 0.0;
		arbitrary.y = 1.0;
		arbitrary.z = 0.0;
	}
	sideways = v_cross_product_nm(arbitrary, *(c->v));
	up_side	= calc_endpoint_vector(&sideways, &up_center, c->d/2);
	radius = v_len(v_between_two_points_nm(*(c->p), up_side));
	return (radius);
}

int located_in_endcaps(t_cylinder cyl, t_point point)
{
    t_vector    top_normal;
    t_point     top_center;
    t_vector    bottom_normal;
    t_point     bottom_center;
    t_vector    center2point_top;
    t_vector    center2point_bottom;

    top_center = calc_endpoint_vector(cyl.v, cyl.p, cyl.h / 2);
    top_normal = *cyl.v;
    bottom_center = calc_endpoint_vector(cyl.v, cyl.p, -(cyl.h / 2));
    bottom_normal = v_mult_scalar_nm(*cyl.v, -1);
    center2point_top = v_between_two_points_nm(top_center, point);
    center2point_bottom = v_between_two_points_nm(bottom_center, point);
    if (!v_dot_product(&center2point_top, &top_normal) && v_len(center2point_top) <= cyl.d/2)
        return (1);
    if (!v_dot_product(&center2point_bottom, &bottom_normal) && v_len(center2point_bottom) <= cyl.d/2)
        return (1);
    return (0);
}

