/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoth <afoth@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 20:09:28 by afoth             #+#    #+#             */
/*   Updated: 2025/02/17 19:26:05 by ltreser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/miniRT.h"

void	render(t_rt *rt)
{
	setup_viewport(rt);
	frustum_culling(rt);
	//freddys box calculation
	//renderstuff
}
