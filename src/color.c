/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoth <afoth@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 16:32:16 by afoth             #+#    #+#             */
/*   Updated: 2025/04/09 16:04:17 by afoth            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/miniRT.h"

unsigned int float_to_grayscale_color(float value)
{
	float	min;
	float	max;
	float	norm;
	int		intensity;

	min = 0;
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
}

unsigned int scale_color_by_value(struct s_color color, float value)
{
    // Choose your min/max or pass them as parameters if needed
    float min = 0.0f;
    float max = 100.0f;

    // Clamp value to [min, max]
    if (value < min)
        value = min;
    if (value > max)
        value = max;

    // Convert [min, max] to a normalized [0, 1]
    float norm = (value - min) / (max - min);

    // Scale each component
    int r = (int)(color.r * norm);
    int g = (int)(color.g * norm);
    int b = (int)(color.b * norm);

    // Pack into 0xRRGGBB
    return (r << 16) | (g << 8) | b;
}
