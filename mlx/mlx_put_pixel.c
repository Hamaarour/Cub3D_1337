/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_put_pixel.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-kabb <mel-kabb@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 18:34:00 by hamaarou          #+#    #+#             */
/*   Updated: 2023/11/08 00:20:21 by mel-kabb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char *dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

unsigned int	get_color(t_mlx *mlx, int x, int y)
{
	char			*dst;
	unsigned int	color;

	dst = mlx->no_texture->addr + (y * mlx->no_texture->size_line + x * (mlx->no_texture->bits_per_pixel / 8));	
	color = *(unsigned int *)dst;
	return (color);
}