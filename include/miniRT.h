/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoth <afoth@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 18:04:10 by afoth             #+#    #+#             */
/*   Updated: 2024/11/22 17:49:33 by afoth            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

//1920x1080? DEL
#define SCREEN_WIDTH  800
#define SCREEN_HEIGHT 600

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

//Is different Structs a good idea, can there be one structure reused?

typedef struct s_rt
{
	void	*mlx_ptr;
	void	*win_ptr;
	//t_camera	camera;
	//t_ambient	ambient;
	//t_light	light;
	//t_sphere	sphere;
	//t_plane	plane;
	//t_cylinder	cylinder;
}t_rt;

typedef struct s_color
{
	int	r;
	int	g;
	int	b;
}t_color;

#endif