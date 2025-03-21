/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoth <afoth@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 12:18:33 by afoth             #+#    #+#             */
/*   Updated: 2025/03/21 16:51:35 by afoth            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/miniRT.h"

void	print_vector(t_vector v)
{
	printf("vector x:%f y:%f z:%f\n", v.x, v.y, v.z);
}

void	print_point(t_point p)
{
	printf("point x:%f y:%f z:%f\n", p.x, p.y, p.z);
}

