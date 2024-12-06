/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoth <afoth@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 16:53:47 by ltreser           #+#    #+#             */
/*   Updated: 2024/12/06 20:45:37 by afoth            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/miniRT.h"

void	init(t_rt *rt)
{
	rt->gc = malloc(sizeof(t_gc));
	ft_gc_init(rt->gc);
	rt->mlx_ptr = NULL;
	rt->win_ptr = NULL;
	rt->camera = NULL;
	rt->ambient = NULL;
	rt->light = NULL;
	rt->obj = gc_malloc(sizeof(t_obj);
	rt->obj->count = 0;
}


