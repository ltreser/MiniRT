/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoth <afoth@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 18:04:10 by afoth             #+#    #+#             */
/*   Updated: 2024/12/03 17:39:13 by afoth            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

// 1920x1080? DEL
# define SCREEN_WIDTH 800
# define SCREEN_HEIGHT 600

/*Error Codes*/
# define EXIT_MALLOC 2
# define EXIT_READ 3
# define EXIT_INPUT 4

/*Error Messages*/

# define MALLOC_FAIL "\033[0;31m Error\nMalloc failed!\n \033[0m"
# define AC_FAIL "\033[0;31m Error\nWrong number of arguments!\n \033[0m"
# define OPEN_FAIL "\033[0;31m Error\nFailed to open file!\n \033[0m"
# define FORMAT_FAIL "\033[0;31m Error\nWrong Format!\n \033[0m"
# define FILE_FAIL "\033[0;31m Error\nScene to render is not correctly provided!\n \033[0m"

/* Standard Libraries */
# include <fcntl.h>
# include <float.h>
# include <limits.h>
# include <stdint.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
#include <sys/time.h>

//# include "./libs/libft/libft.h"
# include "../libs/libft/includes/ft_printf.h"
# include "../libs/libft/includes/get_next_line.h"
# include "../libs/libft/includes/libft.h"

/* MiniLibX */
# include <mlx.h>

typedef struct s_rt			t_rt;
typedef struct s_ambient	t_ambient;
typedef struct s_camera		t_camera;
typedef struct s_plane		t_plane;
typedef struct s_vector		t_vector;
typedef struct s_point		t_point;
typedef struct s_light		t_light;
typedef struct s_sphere		t_sphere;
typedef struct s_cylinder	t_cylinder;
typedef struct s_color		t_color;
typedef struct s_object		t_object;
typedef struct s_gc			t_gc;
typedef enum e_obj			t_obj;

enum						e_obj
{
	SPHERE = 115,
	PLANE = 112,
	CYLINDER = 99,
};

struct						s_rt
{
	float					ar;
	float					screen_h_rad;
	float					screen_w_rad;
	void					*mlx_ptr;
	void					*win_ptr;
	t_gc					*gc;
	t_camera				*camera;
	t_ambient				*ambient;
	t_light					*light;
	t_object				**obj;
	int						n_obj;
};

/*objects*/

struct						s_obj
{
	t_obj					*type;
	union
	{
		t_plane				*plane;
		t_sphere			*sphere;
		t_cylinder			*cylinder;
	};
};

struct						s_plane
{
	t_color					*c;
	t_vector				*v;
	t_point					*p;
};

struct						s_sphere
{
	t_color					*c;
	t_vector				*v;
	t_point					*p;
	int						d;
};

struct						s_cylinder
{
	t_color					*c;
	t_vector				*v;
	t_point					*p;
	float					d;
	float					h;
};

/*parameters*/

struct						s_ambient
{
	t_color					*c;
	float					bright;
};

struct						s_camera
{
	t_vector				*v;
	t_point					*p;
	int						fov;
};

struct						s_light
{
	// t_color c;
	t_vector				*v;
	t_point					*p;
	float					bright;
};

/*variables*/

struct						s_vector
{
	float					x;
	float					y;
	float					z;
};

struct						s_point
{
	float					x;
	float					y;
	float					z;
};

struct						s_color
{
	int						r;
	int						g;
	int						b;
};

typedef struct s_gc
{
	void					*ptr;
	struct s_gc				*next;
};


//garbage collector
void						ft_gc_init(t_rt *rt);
void						*ft_gc_malloc(t_rt *rt, size_t size);
void						ft_gc_free(t_rt *rt);
char						*ft_gc_substr(t_rt *rt, const char *s, unsigned int start, size_t len);

//input
int							check_input(int argc, char **argv);
void						read_file(int fd, t_rt *rt);
#endif
