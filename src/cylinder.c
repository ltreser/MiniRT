#include "../include/miniRT.h"

/* The equation for a more general
cylinder of radius r oriented along
a line pa + va *t:
(q - pa - (va,q - pa)va)^2 - r^2 = 0
where q = (x,y,z) is a point on the
cylinder.
To find intersection points with a ray p + vt,
substitute q = p + vt and solve:
(p - pa + vt - (va,p - pa + vt)va)^2 - r^2 = 0
reduces to At^2 + Bt + C = 0
with
 A = (v - (v, va)va)^2
 B = 2(v - (v, va)va,[delta]p - ([delta]p,va)va)
 C = ([delta]p - ([delta]p, va)va)^2 - r^2
 where [delta]p = p - pa

*/
float	cylinder_intersection(t_cylinder cyl, t_ray ray)
{

}
