/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoth <afoth@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 16:32:16 by afoth             #+#    #+#             */
/*   Updated: 2025/04/07 21:18:09 by afoth            ###   ########.fr       */
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
	max = 1;
	if (value < min)
		value = min;
	if (value > max)
		value = max;
	norm = (value - min) / (max - min);
	intensity = (int)(norm * 255.0f);
	unsigned int color = (intensity << 16) | (intensity << 8) | intensity;
printf("Color: 0x%06X\n", color);

	return (intensity << 16) | (intensity << 8) | intensity;
}
