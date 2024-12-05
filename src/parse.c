
#include "../include/miniRT.h"

void	ft_parse(char *str, t_rt *rt)
{
	if (only_valid_chars(str))
	{
 		//if (str[0] == 'A' && !rt->ambient)
			//parse_ambient(str, rt);
		//if (str[0] == 'C' && !rt->camera)
			//parse_camera(str, rt);
		//if (str[0] == 'L' && !rt->light)
			//parse_light(str, rt);
		if (!ft_strncmp("sp ", str, 3) || !ft_strncmp("pl ", str, 3) || !ft_strncmp("cy ", str, 3))
		{
			rt->obj[rt->n_obj] = ft_gc_malloc(rt, sizeof(t_obj));
			parse_obj(str + 3, rt, str[0]);
		}
	}
	else
		ft_exit(rt, 2, ft_gc_strdup(FILE_FAIL));
	if (str)
	{
		free(str);
		str = NULL;
	}
}

void	parse_ambient(rt *rt, char *str)

void	parse_obj(char *str, t_rt *rt, char type)
{
	rt->obj[rt->n_obj]->type = (t_type)sqrt((type - 99) % 12);
	if (rt->obj[rt->n_obj]->type == SPHERE)
	{
		rt->obj[rt->n_obj]->sphere = ft_gc_malloc(rt, sizeof(t_sphere));
		rt->obj[rt->n_obj]->sphere->p = parse_point(rt, ft_chop(str, ' '));
		rt->obj[rt->n_obj]->sphere->v = parse_vector(rt, ft_chop(str, ' '));
		rt->obj[rt->n_obj]->sphere->c = parse_color(rt, ft_chop(str, ' '));

	}
	if (rt->obj[rt->n_obj]->type == PLANE)
	{
		rt->obj[rt->n_obj]->plane = ft_gc_malloc(rt, sizeof(t_plane));
		rt->obj[rt->n_obj]->plane->p = parse_point(rt, ft_chop(str, ' '));
		rt->obj[rt->n_obj]->plane->v = parse_vector(rt, ft_chop(str, ' '));
		rt->obj[rt->n_obj]->plane->c = parse_color(rt, ft_chop(str, ' '));
	}
	if (rt->obj[rt->n_obj]->type == CYLINDER)
	{
		rt->obj[rt->n_obj]->cylinder = ft_gc_malloc(rt, sizeof(t_cylinder));
		rt->obj[rt->n_obj]->cylinder->p = parse_point(rt, ft_chop(str, ' '));
		rt->obj[rt->n_obj]->cylinder->v = parse_vector(rt, ft_chop(str, ' '));
		parse_dimensions(rt, str);
		rt->obj[rt->n_obj]->cylinder->c = parse_color(rt, ft_chop(str, ' '));
	}
	rt->n_obj++;
}


t_color *parse_color(t_rt *rt, char *str)
{
	t_color *color;

	color = ft_gc_malloc(sizeof(t_color));
	if (contains_c(str, "."))
		ft_exit(rt, 2, ft_gc_strdup(FILE_FAIL));
	color->r = (int)ft_atof(ft_chop(str + skip_spaces(str), ','));
		if (color->r < 0 || color->r > 225)
			ft_exit(rt, 2, ft_gc_strdup(FILE_FAIL));
	color->g = (int)ft_atof(ft_chop(str + skip_spaces(str), ','));
		if (color->r < 0 || color->r > 225)
			ft_exit(rt, 2, ft_gc_strdup(FILE_FAIL));
	color->b = (int)ft_atof(ft_strtrim(str + skip_spaces(str), "'\n' "));
		if (color->r < 0 || color->r > 225)
			ft_exit(rt, 2, ft_gc_strdup(FILE_FAIL));
	if (str)
	{
		free(str);
		str = NULL;
	}
	return (color);
}

//0.0,0.0,-10.0
// 3 Punkte
// 2 Kommas
// max 3*-
t_point	*parse_point(t_rt *rt, char *str)
{
	t_point	*point;
	int		start_of_nb;

	point = ft_gc_malloc(rt, sizeof(t_point));
	start_of_nb = skip_spaces(str);
	point->x= ft_atof(ft_chop(str + start_of_nb, ','));
	is_nan(rt, point->x);
	point->y= ft_atof(ft_chop(str, ','));
	is_nan(rt, point->x);
	point->z= ft_atof(ft_chop(str, ' '));
	is_nan(rt, point->x);
	return(point);
}

//nomalized vektor
t_vector	*parse_vector(t_rt *rt, char *str)
{
	t_vector	*vector;
	float		len;
	int			start_of_nb;

	vector = ft_gc_malloc(rt, sizeof(t_vector));
	start_of_nb = skip_spaces(str);
	vector->x= ft_atof(ft_chop(str + start_of_nb, ','));
	is_nan(rt, vector->x);
	vector->y= ft_atof(ft_chop(str, ','));
	is_nan(rt, vector->y);
	vector->z= ft_atof(ft_chop(str, ' '));
	is_nan(rt, vector->z);
	len = v_len(*vector);
	if (len == 1 || len == -1)
		return(vector);
	else
	{
		perror(FORMAT_FAIL);
		perror("Vector not normalized");
		ft_gc_free(rt);
		exit(EXIT_INPUT);
	}
}
