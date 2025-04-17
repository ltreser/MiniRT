/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoth <afoth@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 16:32:16 by afoth             #+#    #+#             */
/*   Updated: 2025/04/17 18:10:15 by afoth            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/miniRT.h"

//not in use, for differnt coloration
/* unsigned int t_float_to_grayscale_color(t_float value)
{
	t_float	min;
	t_float	max;
	t_float	norm;
	int		intensity;

	min = 15;
	max = 100;
	if (value < min)
		value = min;
	if (value > max)
		value = max;
	norm = 1.0f - ((value - min) / (max - min));

	// norm = (value - min) / (max - min);
	intensity = (int)(norm * 255.0f);
	// unsigned int color = (intensity << 16) | (intensity << 8) | intensity;
	// printf("Color: 0x%06X\n", color);

	return (intensity << 16) | (intensity << 8) | intensity;
} */
//not in use, for differnt coloration
/* unsigned int scale_color_by_value(struct s_color color, t_float value)
{
    // Choose your min/max or pass them as parameters if needed
    t_float min = 0.0f;
    t_float max = 100.0f;

    // Clamp value to [min, max]
    if (value < min)
        value = min;
    if (value > max)
        value = max;

    // Convert [min, max] to a normalized [0, 1]
    t_float norm = (value - min) / (max - min);

    // Scale each component
    int r = (int)(color.r * norm);
    int g = (int)(color.g * norm);
    int b = (int)(color.b * norm);

    // Pack into 0xRRGGBB
    return (r << 16) | (g << 8) | b;
} */

unsigned int color_to_hex(t_color c)
{
	unsigned int	r;
	unsigned int	g;
	unsigned int	b;

	r = c.r;
	g = c.g;
	b = c.b;
	return ((r << 16) | (g << 8) | b);
}
