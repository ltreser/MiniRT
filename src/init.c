/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoth <afoth@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 16:53:47 by ltreser           #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2024/12/06 21:00:21 by afoth            ###   ########.fr       */
=======
/*   Updated: 2024/12/06 20:52:14 by ltreser          ###   ########.fr       */
>>>>>>> 3a65c87c7f21e203d6dc7f1fef24346735277110
/*                                                                            */
/* ************************************************************************** */

#include "../include/miniRT.h"

void	init(t_rt *rt)
{
	rt->gc = malloc(sizeof(t_gc));
	ft_gc_init(rt->gc);
	rt->mlx = NULL;
	rt->camera = NULL;
	rt->ambient = NULL;
	rt->light = NULL;
	rt->obj = gc_malloc(rt->gc, sizeof(t_obj));
	rt->n_obj = 0;
}


