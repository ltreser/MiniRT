/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoth <afoth@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 16:32:16 by afoth             #+#    #+#             */
/*   Updated: 2025/04/19 21:22:43 by ltreser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/miniRT.h"

unsigned int	color_to_hex(t_color c)
{
	unsigned int	r;
	unsigned int	g;
	unsigned int	b;

	r = c.r;
	g = c.g;
	b = c.b;
	return ((r << 16) | (g << 8) | b);
}

t_color	col_mult_scalar(t_color color, t_float scalar)
{
	t_color	result;

	result.r = color.r * scalar;
	result.g = color.g * scalar;
	result.b = color.b * scalar;
	return (result);
}

t_color	col_add(t_color color_a, t_color color_b)
{
	t_color	result;

	result.r = color_a.r + color_b.r;
	result.g = color_a.g + color_b.g;
	result.b = color_a.b + color_b.b;
	return (result);
}
