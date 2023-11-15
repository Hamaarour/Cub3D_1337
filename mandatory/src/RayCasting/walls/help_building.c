/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_building.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamaarou <hamaarou@1337.student.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 22:15:16 by mel-kabb          #+#    #+#             */
/*   Updated: 2023/11/15 15:04:14 by hamaarou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d.h"

int	rgb_to_int(int red, int green, int blue)
{
    return (red << 16) | (green << 8) | blue;
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

unsigned int	get_color(t_image *texture, int x, int y)
{
	char			*dst;
	unsigned int	color;

	dst = texture->addr + (y * texture->size_line + x * (texture->bits_per_pixel
				/ 8));
	color = *(unsigned int *)dst;
	return (color);
}

double	get_x(t_mlx *mlx)
{
	int	x;

	x = 0;
	if (mlx->is_vertical == 1)
	{
		x = fmod(mlx->ray_y, 64);
		if (x >= 62 || x <= 1)
			x = fmod(mlx->ray_x, 64);
	}
	else
	{
		x = fmod(mlx->ray_x, 64);
		if (x >= 62 || x <= 1)
			x = fmod(mlx->ray_y, 64);
	}
	return (x);
}
