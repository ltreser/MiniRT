/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen_calculations.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoth <afoth@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 16:00:16 by afoth             #+#    #+#             */
/*   Updated: 2024/12/17 15:50:29 by afoth            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/miniRT.h"


//do we want to have different windows sizes?
void calc_aspect_ratio(t_rt *rt)
{
	rt->aspect_r = SCREEN_HEIGHT / SCREEN_WIDTH;
}


