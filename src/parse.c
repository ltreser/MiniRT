
#include "../include/miniRT.h"

void	ft_parse(char *str, t_rt *rt, int count_only)
{
	if (count_only)
		rt->obj_count += (!ft_strncmp("sp ", str, 3) || !ft_strncmp("pl ", str, 3) || !ft_strncmp("cy ", str, 3));
	else if (only_valid_chars(str))
	{
 		if (str[0] == 'A' && !rt->ambient && str[1] && str[1] == ' ')
		{
			printf("Parsing ambient\n");
			parse_ambient(rt, str + 2);
			write(1, "ambient done\n", 13);
		}
		else if (str[0] == 'A' && rt->ambient)
			ft_exit(rt,4, AC_FAIL);
		if (str[0] == 'C' && !rt->camera && str[1] && str[1] == ' ')
		{
			printf("Parsing Camera\n");
			parse_camera(rt, str + 2);
			write(1, "camera done\n", 12);
		}
		else if (str[0] == 'C' && rt->camera)
			ft_exit(rt,4, AC_FAIL);
		if (str[0] == 'L' && !rt->light && str[1] && str[1] == ' ')
		{
			printf("Parsing Ligth\n");
			parse_light(rt, str + 2);
			write(1, "light done\n", 11);
		}
		else if (str[0] == 'L' && rt->light)
			ft_exit(rt,4, AC_FAIL);
		if (!ft_strncmp("sp ", str, 3) || !ft_strncmp("pl ", str, 3) || !ft_strncmp("cy ", str, 3))
		{
			rt->obj[rt->n_obj] = gc_malloc(rt->gc, sizeof(t_obj));
			rt->obj[rt->n_obj]->type = (t_type)sqrt((str[0] - 99) % 12);
			printf("this is type now: %d", rt->obj[rt->n_obj]->type);
			parse_obj((str + 3) + skip_spaces(str + 3), rt);
		}
	}
	else
		ft_exit(rt, 2, gc_strdup(rt->gc,FILE_FAIL));
}

void	parse_ambient(t_rt *rt, char *str)
{
	float ratio;
	rt->ambient = gc_malloc(rt->gc, sizeof(t_ambient));
	str += skip_spaces(str);
	ratio = ft_atof(gc_chop(rt->gc, str, ' '));
	is_nan(rt, ratio);
	if (ratio < 0 || ratio > 1)
		ft_exit(rt, 2, gc_strdup(rt->gc,FILE_FAIL));
	rt->ambient->ratio = ratio;
	rt->ambient->ratio = ratio;
	rt->ambient->c = parse_color(rt, gc_strtrim(rt->gc, str, "\n "));
}

void	parse_camera(t_rt *rt, char *str)
{
	int fov;

	printf("string in parse camera: %s\n", str);
	fov = -1;
	rt->camera = gc_malloc(rt->gc, sizeof(t_camera));
	str += skip_spaces(str);
	rt->camera->p = parse_point(rt, gc_chop(rt->gc, str, ' '));
	str += skip_spaces(str);
	rt->camera->v = parse_vector(rt, gc_chop(rt->gc, str, ' '));
	str += skip_spaces(str);
	fov = (int)ft_atof(gc_chop(rt->gc, str, '\n'));
	is_nan(rt, (float)fov);
	if (fov < 0 || fov > 180)
		ft_exit(rt, 2, gc_strdup(rt->gc,FILE_FAIL));
	rt->camera->fov = fov;
}

void	parse_light(t_rt *rt, char *str)
{
	float bright;
	rt->light = gc_malloc(rt->gc, sizeof(t_light));
	str += skip_spaces(str);
	rt->light->p = parse_point(rt, gc_chop(rt->gc, str, ' '));
	str += skip_spaces(str);
	bright = ft_atof(gc_chop(rt->gc, str, ' '));
	is_nan(rt, bright);
	if (bright < 0 || bright > 1)
		ft_exit(rt, 2, gc_strdup(rt->gc,FILE_FAIL));
	rt->light->bright = bright;
	rt->light->c = parse_color(rt, gc_strtrim(rt->gc, str, "\n "));
}

void	parse_obj(char *str, t_rt *rt)
{
	printf("this is sphere: %d\n", SPHERE);
	printf("this is type: %d\n", rt->obj[rt->n_obj]->type);
	if (rt->obj[rt->n_obj]->type == SPHERE)
	{
		printf("Parsing Sphere\n");

		rt->obj[rt->n_obj]->sphere = gc_malloc(rt->gc, sizeof(t_sphere));
		rt->obj[rt->n_obj]->sphere->p = parse_point(rt, gc_chop(rt->gc, str, ' '));
		parse_dimensions(rt, str);
		rt->obj[rt->n_obj]->sphere->c = parse_color(rt, str);

	}
	if (rt->obj[rt->n_obj]->type == PLANE)
	{
		printf("Parsing Plane\n");

		rt->obj[rt->n_obj]->plane = gc_malloc(rt->gc, sizeof(t_plane));
		rt->obj[rt->n_obj]->plane->p = parse_point(rt, gc_chop(rt->gc, str, ' '));
		rt->obj[rt->n_obj]->plane->v = parse_vector(rt, gc_chop(rt->gc, str, ' '));
		rt->obj[rt->n_obj]->plane->c = parse_color(rt, str);
	}
	if (rt->obj[rt->n_obj]->type == CYLINDER)
	{
		printf("Parsing Cylinder\n");
		rt->obj[rt->n_obj]->cylinder = gc_malloc(rt->gc, sizeof(t_cylinder));
		rt->obj[rt->n_obj]->cylinder->p = parse_point(rt, gc_chop(rt->gc, str, ' '));
		rt->obj[rt->n_obj]->cylinder->v = parse_vector(rt, gc_chop(rt->gc, str, ' '));
		parse_dimensions(rt, str);
		rt->obj[rt->n_obj]->cylinder->c = parse_color(rt, str);
	}
	parse_dimensions(rt, str);
	rt->n_obj++;
}

t_color *parse_color(t_rt *rt, char *str)
{
	t_color *color;

	color = gc_malloc(rt->gc, sizeof(t_color));
	if (contains_c(str, '.'))
		ft_exit(rt, 2, gc_strdup(rt->gc,FILE_FAIL));
	str += skip_spaces(str);
	color->r = (int)ft_atof(gc_chop(rt->gc, str + skip_spaces(str), ','));
	is_nan(rt, (float)color->r);
	if (color->r < 0 || color->r > 255)
		ft_exit(rt, 2, gc_strdup(rt->gc,FILE_FAIL));
	str += skip_spaces(str);
	color->g = (int)ft_atof(gc_chop(rt->gc, str + skip_spaces(str), ','));
	is_nan(rt, (float)color->g);
	if (color->g < 0 || color->g > 255)
		ft_exit(rt, 2, gc_strdup(rt->gc,FILE_FAIL));
	str += skip_spaces(str);
	color->b = (int)ft_atof(gc_strtrim(rt->gc, str + skip_spaces(str), "'\n' "));
	is_nan(rt, (float)color->b);
	if (color->b < 0 || color->b > 255)
		ft_exit(rt, 2, gc_strdup(rt->gc,FILE_FAIL));
	return (color);
}

//0.0,0.0,-10.0
// 3 Punkte
// 2 Kommas
// max 3*-
t_point	*parse_point(t_rt *rt, char *str)
{
	t_point	*point;

	point = gc_malloc(rt->gc, sizeof(t_point));
	point->x = ft_atof(gc_chop(rt->gc, str, ','));
	printf("point x is: %f\n", point->x);
	is_nan(rt, point->x);
	point->y = ft_atof(gc_chop(rt->gc, str, ','));
	printf("point y is: %f\n", point->y);
	is_nan(rt, point->y);
	point->z = ft_atof(gc_strtrim(rt->gc, str, "\n "));
	is_nan(rt, point->z);
	printf("point z is: %f\n", point->z);
	return(point);
}

//nomalized vektor
t_vector	*parse_vector(t_rt *rt, char *str)
{
	t_vector	*vector;
	float		len;

	vector = gc_malloc(rt->gc, sizeof(t_vector));
	vector->x= ft_atof(gc_chop(rt->gc, str, ','));
	printf("vektor point x is: %f\n", vector->x);
	is_nan(rt, vector->x);
	vector->y= ft_atof(gc_chop(rt->gc, str, ','));
	printf("vektor point y is: %f\n", vector->y);
	is_nan(rt, vector->y);
	vector->z= ft_atof(gc_chop(rt->gc, str, ' '));
	printf("vektor point z is: %f\n", vector->z);
	is_nan(rt, vector->z);
	len = v_len(vector);
	if (len == 1 || len == -1)
		return(vector);
	else
	{

		perror(FORMAT_FAIL);
		write(1, "Vector not normalized\n", 22);
		ft_gc_free(rt->gc);
		exit(EXIT_INPUT);
	}
}
