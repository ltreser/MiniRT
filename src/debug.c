/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoth <afoth@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 12:18:33 by afoth             #+#    #+#             */
/*   Updated: 2025/02/26 12:22:22 by afoth            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/miniRT.h"

void	print_vector(t_vector v)
{
	printf("vector x:%f y:%f z:%f", v.x, v.y, v.z);
}

void	print_point(t_point p)
{
	printf("point x:%f y:%f z:%f", p.x, p.y, p.z);
}
