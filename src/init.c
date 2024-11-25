/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltreser <ltreser@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 16:53:47 by ltreser           #+#    #+#             */
/*   Updated: 2024/11/25 17:36:32 by ltreser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

void	init(t_rt *rt)
{
	rt->mlx_ptr = NULL;
	rt->win_ptr = NULL;
	rt->camera = NULL;
	rt->ambient = NULL;
	rt->light = NULL;
	rt->obj = malloc(sizeof(t_obj);
	rt->obj->count = 0;	
}


