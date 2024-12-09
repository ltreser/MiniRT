/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoth <afoth@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 18:04:10 by afoth             #+#    #+#             */
/*   Updated: 2024/12/10 17:12:15 by ltreser          ###   ########.fr       */
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
# define AC_FAIL "\033[0;31m Error\n Wrong number of arguments!\n \033[0m"
# define OPEN_FAIL "\033[0;31m Error\n Failed to open file!\n \033[0m"
# define FORMAT_FAIL "\033[0;31m Error\n Wrong Format!\n \033[0m"
# define FILE_FAIL "\033[0;31m Error\n Scene to render is not correctly provided!\n \033[0m"
# define MLX_FAIL "\033[0;31m Error\n MLX failed to initialize!\n \033[0m"


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
# include "../libft/includes/ft_printf.h"
# include "../libft/includes/get_next_line.h"
# include "../libft/includes/libft.h"

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
typedef struct s_obj		t_obj;
typedef struct s_gc			t_gc;
typedef struct s_mlx		t_mlx;
typedef enum e_type			t_type;

enum						e_type
{
	CYLINDER,
	PLANE,
	SPHERE,
};


/*main struct*/

struct						s_rt
{
	float					aspect_r;
	float					screen_h_rad;
	float					screen_w_rad;
	t_mlx					*mlx;
	t_gc					*gc;
	t_camera				*camera;
	t_ambient				*ambient;
	t_light					*light;
	t_obj					**obj;
	int						n_obj;
	int						obj_count;
	int						fd;
};

/*minilibx graphical library struct*/

struct						s_mlx
{
	void	*connection;
	void	*window;
	void	*img;
	char	*pixel_adress;
	int		x;
	int		y;
	int		width;
	int		height;
	int		bpp;
	int		endian;
	int		line_len;
	//float	zoom;
};

/*objects*/

struct						s_obj
{
	t_type					type;
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
	float					ratio;
};

struct						s_camera
{
	t_vector				*v;
	t_point					*p;
	int						fov;
};

struct						s_light
{
	t_point					*p;
	float					bright;
	t_color					*c;
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


//init
void						init(t_rt *rt);

//input
int							check_input(t_rt *rt, int argc, char **argv);
void						read_file(int fd, t_rt *rt);

//exit
void						ft_exit(t_rt *rt, int exit_code, char *error_message);
void						free_all(t_rt *rt);

//parse
void						ft_parse(char *str, t_rt *rt, int count_only);
void						parse_obj(char *str, t_rt *rt);
t_color						*parse_color(t_rt *rt, char *str);
t_point						*parse_point(t_rt *rt, char *str);
t_vector					*parse_vector(t_rt *rt, char *str);
void						parse_ambient(t_rt *rt, char *str);
void						parse_camera(t_rt *rt, char *str);
void						parse_light(t_rt *rt, char *str);

//parse_utils
void						parse_dimensions(t_rt *rt, char *str);
int							skip_spaces(char *str);
int							only_valid_chars(char *str);
void						is_nan(t_rt *rt, float f);

//mlx
void    mlx_create_window(t_rt *rt);
int keypress(int keycode, t_rt *rt);
int ft_close_window(t_rt *rt);

//vector_calc
float						v_len(t_vector *vector);

//render
void calc_aspect_ratio(t_rt *rt);


#endif
