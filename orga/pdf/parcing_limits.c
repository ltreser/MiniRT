struct s_rt
{
	float	ar;
	float	screen_h_rad;
	float	screen_w_rad;
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
