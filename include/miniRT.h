/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoth <afoth@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 18:04:10 by afoth             #+#    #+#             */
/*   Updated: 2024/11/25 14:49:42 by ltreser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

//1920x1080? DEL
#define SCREEN_WIDTH  800
#define SCREEN_HEIGHT 600

/*Error Messages*/

#define MALLOC_FAIL "Malloc failed!\n"
#define AC_FAIL "Wrong number of arguments!\n"
#define OPEN_FAIL "Failed to open file!\n"


/* Standard Libraries */
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <math.h>
//# include "./libs/libft/libft.h"
# include "/home/afoth/Desktop/MiniRT/libs/libft/libft.h"

/* MiniLibX */
#include <mlx.h>

typedef struct s_rt t_rt;
typedef struct s_ambient t_ambient;
typedef struct s_camera t_camera;
typedef struct s_plane t_plane;
typedef struct s_vector t_vector;
typedef struct s_point t_point;
typedef struct s_light t_light;
typedef struct s_sphere t_sphere;
typedef struct s_cylinder t_cylinder;
typedef struct s_color t_color;
typedef struct s_object t_object;


struct s_rt
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_camera	camera;
	t_ambient	ambient;
	t_light	light;
	t_sphere	*sphere;
	t_plane	*plane;
	t_cylinder	*cylinder;
	t_object	*obj;
};


/*objects*/

struct s_obj
{
	int	count;
	union
	{
		t_plane *plane;
		t_sphere *sphere;
		t_cylinder *cylinder;
	}
};

struct s_plane
{
	t_color c;
	t_vector v;
	t_point	p;
};

struct s_sphere
{
	t_color c;
	t_vector v;
	t_point	p;
	int	d;
};

struct s_cylinder
{
	t_color c;
	t_vector v;
	t_point	p;
	float	d;
	float	h;
};

/*parameters*/

struct s_ambient
{
	t_color c;
	float	bright;
};

struct s_camera
{
	t_vector v;
	t_point	p;
	int	fov;
};

struct s_light
{
	//t_color c;
	t_vector v;
	t_point	p;
	float bright;
};

/*variables*/

struct vector
{
	float	x;
	float	y;
	float	z;
};

struct s_point
{
	float	x;
	float	y;
	float	z;
};

struct s_color
{
	int	r;
	int	g;
	int	b;
};

#endif
