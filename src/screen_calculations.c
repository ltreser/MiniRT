/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen_calculations.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoth <afoth@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 16:00:16 by afoth             #+#    #+#             */
/*   Updated: 2025/02/24 18:44:39 by afoth            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/miniRT.h"


//do we want to have different windows sizes?
void calc_aspect_ratio(t_rt *rt)
{
	if(SCREEN_HEIGHT > 0 && SCREEN_WIDTH > 0)
		rt->aspect_r = (float)SCREEN_HEIGHT / (float)SCREEN_WIDTH;
	else
		ft_exit(rt, 4, "Screen size zero or negative");
}


