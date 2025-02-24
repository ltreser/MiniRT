/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoth <afoth@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 20:09:28 by afoth             #+#    #+#             */
/*   Updated: 2025/02/24 18:26:08 by afoth            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/miniRT.h"

void	render(t_rt *rt)
{
	printf("START OF RENDER\n");
	setup_viewport(rt);
	//frustum_culling(rt);
	//freddys box calculation
	//renderstuff
}
