
#include "../include/miniRT.h"

void    ft_parse(char *str, t_rt *rt)
{
	if (only_valid_chars(str))
	{
 		if (str[i] == 'A' && !rt->ambient)
			parse_ambient(str, rt);
		if (str[i] == 'C' && !rt->camera)
			parse_camera(str, rt);
		if (str[i] == 'L' && !rt->light)
			parse_light(str, rt);
		if (!strncmp("sp ", str, 3) || !strncmp("pl ", str, 3) || !strncmp("cy ", str, 3))
		{
			rt->obj[rt->n_obj] = malloc(sizeof(t_obj));
			parse_obj(str + 3, rt, str[i]);
		}
	}
	else
		ft_exit(rt, 2, ft_strdup(FILE_FAIL));
	}
	if (str)
	{
		free(str);
		str = NULL;
	}
}

void	parse_obj(char *str, t_rt *rt, char type)
{
	rt->obj[rt->n_obj]->type = (t_enum)type;
	if (rt->obj[rt->n_obj]->type == SPHERE)
	{
		rt->obj[rt->n_obj]->sphere = malloc(sizeof(t_sphere));
		rt->obj[rt->n_obj]->sphere->p = parse_point(ft_chop(str, ' '), rt);
		rt->obj[rt->n_obj]->sphere->v = parse_vector(ft_chop(str, ' '), rt);
		rt->obj[rt->n_obj]->sphere->c = parse_color(ft_chop(str, ' '), rt);

	}
	if (rt->obj[rt->n_obj]->type == PLANE)
	{
		rt->obj[rt->n_obj]->plane = malloc(sizeof(t_plane));
		rt->obj[rt->n_obj]->plane->p = parse_point(ft_chop(str, ' '), rt);
		rt->obj[rt->n_obj]->plane->v = parse_vector(ft_chop(str, ' '), rt);
		rt->obj[rt->n_obj]->plane->c = parse_color(ft_chop(str, ' '), rt);
	}
	if (rt->obj[rt->n_obj]->type == CYLINDER)
	{
		rt->obj[rt->n_obj]->cylinder = malloc(sizeof(t_cylinder));
		rt->obj[rt->n_obj]->cylinder->p = parse_point(ft_chop(str, ' '), rt);
		rt->obj[rt->n_obj]->cylinder->v = parse_vector(ft_chop(str, ' '), rt);
		parse_dimensions(str, rt);
		rt->obj[rt->n_obj]->cylinder->c = parse_color(ft_chop(str, ' '), rt);
	}
	rt->n_obj++;
}


t_color *parse_color(t_rt *rt, char *str)
{


}

//0.0,0.0,-10.0
// 3 Punkte
// 2 Kommas
// max 3*-
t_point	*parse_point(t_rt *rt, char *str)
{
	t_point	*point;
	int		start_of_nb;

	point = ft_gc_malloc(rt->gc, sizeof(t_point));
	start_of_nb = skip_spaces(str);
	point->x= ft_atof(ft_chop(str + start_of_nb, ','));
	point->y= ft_atof(ft_chop(str, ','));
	point->z= ft_atof(ft_chop(str, ' '));
	return(point);
}

//nomalized vektor
t_vector	*parse_vector(t_rt *rt, char *str)
{
	t_vector	*vector;
	int			start_of_nb;

	vector = ft_gc_malloc(rt->gc, sizeof(t_vector));
	start_of_nb = skip_spaces(str);
	vector->x= ft_atof(ft_chop(str + start_of_nb, ','));
	vector->y= ft_atof(ft_chop(str, ','));
	vector->z= ft_atof(ft_chop(str, ' '));
	return(vector);
}
