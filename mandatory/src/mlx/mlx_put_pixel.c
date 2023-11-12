/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_put_pixel.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamaarou <hamaarou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 18:34:00 by hamaarou          #+#    #+#             */
/*   Updated: 2023/11/12 21:20:02 by hamaarou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void my_mlx_pixel_put2(t_image *textures, int x, int y, int color)
{
	char *dst;

	dst = textures->addr + (y * textures->size_line + x * (textures->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

