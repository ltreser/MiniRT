/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoth <afoth@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 16:54:13 by afoth             #+#    #+#             */
/*   Updated: 2025/04/22 19:19:51 by afoth            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

/* Standard Libraries */
# include <fcntl.h>
# include <limits.h>
# include <math.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

//# include "./libs/libft/libft.h"
# include "../libs/libft/includes/ft_printf.h"
# include "../libs/libft/includes/get_next_line.h"
# include "../libs/libft/includes/libft.h"

/* MiniLibX */
# include <mlx.h>
# define PI 3.14159265f
# define SCREEN_WIDTH 1600
# define SCREEN_HEIGHT 800
# define MAX_RENDER 3.402823466e+38F
// Comparing t_floats, if the difference is smaller than EPSILON,
// they are considered equal
# define EPSILON 0.0001f

typedef double				t_float;

/*Error Codes*/
# define EXIT_MALLOC 2
# define EXIT_READ 3
# define EXIT_INPUT 4
# define EXIT_MLX 5

/*Error Messages*/
# define MALLOC_FAIL "\033[0;31m Error\nMalloc failed!\n \033[0m"
# define AC_FAIL "\033[0;31m Error\n Wrong number of arguments!\n \033[0m"
# define OPEN_FAIL "\033[0;31m Error\n Failed to open file!\n \033[0m"
# define FORMAT_FAIL "\033[0;31m Error\n Wrong Format!\n \033[0m"
# define FILE_FAIL \
	"\033[0;31m Error\n Scene to render \
is not correctly provided!\n \033[0m"
# define MLX_FAIL "\033[0;31m Error\n MLX failed to initialize!\n \033[0m"

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
typedef struct s_intersect	t_intersect;
typedef struct s_gc			t_gc;
typedef struct s_mlx		t_mlx;
typedef struct s_vp			t_vp;
typedef struct s_fc			t_fc;
typedef struct s_ray		t_ray;
typedef enum e_type			t_type;
typedef struct s_bvh		t_bvh;

enum						e_type
{
	CYLINDER,
	PLANE,
	SPHERE,
};

/*main struct*/

struct						s_rt
{
	t_float					aspect_r;
	t_float					screen_h_rad;
	t_float					screen_w_rad;
	t_mlx					*mlx;
	t_gc					*gc;
	t_camera				*camera;
	t_ambient				*ambient;
	t_light					*light;
	t_obj					**obj;
	t_vp					*vp;
	t_fc					*fc;
	t_intersect				*intersec;
	t_bvh					*bvh;
	int						n_obj;
	int						obj_count;
	int						fd;
};

/*viewport* note: forward vector == camera vector*/

struct						s_vp
{
	t_ray					*render_ray;
	t_plane					*vp_plane;
	t_float					width;
	t_float					height;
	t_float					distance;
	t_float					pixel_size;
	t_vector				*pixel_v_x;
	t_vector				*pixel_v_y;
	t_vector				*pixel_v_y_negative;
	t_float					pixel_w;
	t_float					pixel_h;

	int						pixel_x;
	int						pixel_y;
	t_vector				*up;
	t_vector				*right;
	t_point					*center;
	t_point					*top_left;
	t_point					*top_right;
	t_point					*bottom_left;
	t_point					*bottom_right;
};

/*frustum culling*/

struct						s_fc
{
	t_vector				*uplane_n;
	t_vector				*dplane_n;
	t_vector				*rplane_n;
	t_vector				*lplane_n;
	t_point					*uplane_p;
	t_point					*dplane_p;
	t_point					*rplane_p;
	t_point					*lplane_p;
	t_float					uplane_d;
	t_float					dplane_d;
	t_float					rplane_d;
	t_float					lplane_d;
};

struct						s_bvh
{
	char					axis;
	int						*sort;
	int						count;
};

/*minilibx graphical library struct*/

struct						s_mlx
{
	void					*connection;
	void					*window;
	void					*img;
	char					*pixel_adress;
	int						x;
	int						y;
	int						width;
	int						height;
	int						bpp;
	int						endian;
	int						line_len;
};

/*objects*/

//	uvp_x1	uvp_y1	dvp_x2	dvp_y2 are the corners of the mask that
// is used to optimize rendering (simplyfied bounding volumes)
struct						s_obj
{
	t_type					type;
	int						visible;
	int						uvp_x1;
	int						uvp_y1;
	int						dvp_x2;
	int						dvp_y2;
	t_point					*center;
	t_vector				*bbox_min;
	t_vector				*bbox_max;
	union
	{
		t_plane				*pl;
		t_sphere			*s;
		t_cylinder			*cyl;
	};
};

struct						s_intersect
{
	t_ray					*ray;
	t_point					*hit_p;
	t_vector				*normal;
	t_float					shadow_t;
};

struct						s_plane
{
	t_color					*c;
	t_vector				*v;
	t_point					*p;
};

struct						s_sphere
{
	t_point					*u_corner;
	t_point					*d_corner;
	t_vector				*v;
	t_point					*p;
	t_float					d;
	t_color					*c;
	t_float					rot_r;
};

struct						s_cylinder
{
	t_point					*u_corner;
	t_point					*d_corner;
	t_color					*c;
	t_vector				*v;
	t_point					*p;
	t_float					rot_r;
	t_float					d;
	t_float					h;
};

/*parameters*/

struct						s_ambient
{
	t_color					*c;
	t_float					ratio;
};

struct						s_camera
{
	t_vector				*v;
	t_point					*p;
	t_float					fov;
};

struct						s_light
{
	t_point					*p;
	t_float					bright;
	t_color					*c;
};

/*variables*/

struct						s_vector
{
	t_float					x;
	t_float					y;
	t_float					z;
};

struct						s_point
{
	t_float					x;
	t_float					y;
	t_float					z;
};

struct						s_color
{
	int						r;
	int						g;
	int						b;
};

struct						s_ray
{
	t_point					*p;
	t_vector				*v;
};

// exit
void						ft_exit(t_rt *rt, int exit_code,
								char *error_message);
void						free_all(t_rt *rt);

// parse
void						init_viewport(t_rt *rt);
void						parse_input(t_rt *rt, char **argv);
int							input_correct(t_rt *rt, int argc, char **argv);
void						check_format(t_rt *rt, char *arg);
void						ft_parse(char *str, t_rt *rt, int count_only);
void						parse_obj(char *str, t_rt *rt);
t_color						*parse_color(t_rt *rt, char *str);
t_point						*parse_point(t_rt *rt, char *str);
t_vector					*parse_vec(t_rt *rt, char *str);
void						parse_ambient(t_rt *rt, char *str);
void						parse_camera(t_rt *rt, char *str);
void						parse_light(t_rt *rt, char *str);
int							check_input(t_rt *rt, int argc, char **argv);
void						read_file(int fd, t_rt *rt);
void						parse_dimensions(t_rt *rt, char *str);
int							skip_spaces(char *str);
int							only_valid_chars(char *str);
void						is_nan(t_rt *rt, t_float f);
void						init(t_rt *rt);
void						init_fc(t_fc *fc);
t_vector					*init_vector(t_gc *gc);
void						init_intersec(t_rt *rt);
void						assign_obj(t_rt *rt, char *str);
void						check_completion(t_rt *rt);

// mlx
void						mlx_create_window(t_rt *rt);
int							keypress(int keycode, t_rt *rt);
int							ft_close_window(t_rt *rt);

// maths
t_float						v_len(t_vector vector);
t_vector					*v_cross_product(t_rt *rt, t_vector *a,
								t_vector *b);
t_point						calc_endpoint_vector_nm(t_vector v, t_point start,
								t_float scalar);
t_vector					*v_normalize(t_vector *v);
t_vector					v_normalize_nm(t_vector v);
t_vector					*v_add(t_rt *rt, t_vector *a, t_vector *b);
t_float						calc_p_distance(t_point a, t_point b);
t_vector					vector_projection(t_vector a, t_vector b);
t_vector					v_mult_scalar_nm(t_vector v, t_float scalar);
t_vector					v_add_nm(t_vector a, t_vector b);
t_vector					v_subtract_nm(t_vector a, t_vector b);
t_vector					v_mult_nm(t_vector a, t_vector b);
t_float						scalar_product_nm(t_vector a, t_vector b);
t_float						cylinder_rot_radius(t_cylinder *c);
t_point						*pv_add(t_rt *rt, t_vector *a, t_point *b);
t_point						vp_add_nm(t_vector a, t_point b);
t_point						pv_subtract_nm(t_point a, t_vector b);
t_point						vp_subtract_nm(t_vector a, t_point b);
t_vector					v_product_nm(t_vector a, t_vector b);
t_point						calc_endpoint_vector(t_vector *v, t_point *start,
								t_float scalar);
t_vector					v_cross_product_nm(t_vector a, t_vector b);
t_vector					*v_between_two_points(t_rt *rt, t_point a,
								t_point b);
t_vector					v_between_two_points_nm(t_point a, t_point b);
t_vector					pp_sub_v_nm(t_point a, t_point b);
t_float						distance_p_to_ray(t_point point, t_ray ray);
t_float						v_dot_product(t_vector *a, t_vector *b);
t_point						p_add(t_vector a, t_point b);

// frustum culling
void						malloc_fc(t_rt *rt);
void						calculate_fplanes(t_rt *rt);
void						calculate_fplane_distances(t_rt *rt);
void						frustum_culling(t_rt *rt);

t_point						plane_ray_intersec(t_plane pl, t_ray ray);
t_float						sphere_intersection(t_sphere *s, t_ray *r);

// render optimisation

void						create_cylinder_mask(t_rt *rt);
void						symplify(t_rt *rt, int *error);
void						create_sphere_mask(t_rt *rt);
void						calc_maskpoint_on_vp(t_rt *rt, t_point *mask_corner,
								char corner, int *error);
void						optimise_pixel_rendering(t_rt *rt);
// plan equations
t_float						plane_ray_calc_t(t_plane pl, t_ray ray);
t_point						plane_ray_intersec(t_plane pl, t_ray ray);
// render
void						render(t_rt *rt);
void						calc_aspect_ratio(t_rt *rt);
void						setup_viewport(t_rt *rt);
t_float						cylinder_intersection(t_cylinder cyl, t_ray ray);
t_point						sphere_intersection_p(t_sphere *s, t_ray *r);
t_float						infinite_plane_a(t_cylinder cyl, t_ray ray);
t_float						infinite_plane_b(t_cylinder cyl, t_ray ray);
int							point_within_circles(t_cylinder cyl,
								t_float intersection, t_ray ray);
int							point_within_planes(t_cylinder cyl,
								t_float intersection, t_ray ray);
t_float						infinite_cylinder(t_cylinder cyl, t_ray ray,
								int flag);
t_float						abc_formula(t_float a, t_float b, t_float c,
								int flag);
int							located_in_endcaps(t_cylinder cyl, t_point point);
void						obj_render_loop(t_rt *rt, t_ray *ray);
void						render_loop(t_rt *rt);
t_point						calc_startpoint_render(t_rt *rt);
void						create_render_ray(t_rt *rt);
t_color						get_color(t_rt *rt, int i);

// init_obj.c
void						init_obj(t_rt *rt);
t_point						*init_point(t_gc *gc);
t_ray						*init_ray(t_gc *gc);
// color
unsigned int				t_float_to_grayscale_color(t_float value);
unsigned int				scale_color_by_value(struct s_color color,
								t_float value);

// lighting
t_color						lighting(t_rt *rt, t_obj obj, t_color color,
								t_float t);
t_ray						calc_shadow_ray(t_rt *rt, t_float t);
t_float						shadow_loop(t_rt *rt, t_ray *ray, t_float len);
t_vector					cal_normal(t_rt *rt, t_obj obj, t_point p);
unsigned int				color_to_hex(t_color c);
t_color						col_mult_scalar(t_color color, t_float scalar);
t_color						col_add(t_color color_a, t_color color_b);
t_color						calc_diffuse_light(t_rt *rt, t_vector normal,
								t_vector v_light);
t_color						calculate_light(t_rt *rt, t_color color,
								t_color diffuse);

// bvh
void						setup_bvh(t_rt *rt);
void						create_obj_bboxes(t_rt *rt);
void						create_cylinder_bbox(t_rt *rt, int i);
void						create_sphere_bbox(t_rt *rt, int i);
void						init_bvh(t_rt *rt);
void						find_division_axis(t_rt *rt);

// debug
void						print_point(t_point p, char *prompt);
void						print_vector(t_vector v, char *prompt);
void						print_sphere(t_sphere *s);
int							calc_point_on_screen(t_rt *rt, t_point point,
								char axis);
void						renderpoint(t_rt *rt, t_point point, char *prompt);

#endif
