/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamaarou <hamaarou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 17:34:09 by hamaarou          #+#    #+#             */
/*   Updated: 2023/11/16 18:49:50 by hamaarou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d.h"

void	draw_square(t_mlx *mlx, int x, int y, int color)
{
	int	i;
	int	j;
	int	size;

	i = y;
	size = 16;
	while (i < y + size)
	{
		j = x;
		while (j < x + size)
		{
			my_mlx_pixel_put(&mlx->data, j, i, color);
			j++;
		}
		i++;
	}
}

void	draw_player(t_mlx *mlx)
{
	int	x;
	int	y;

	x = 128;
	y = x;
	draw_square(mlx, x, y, 0x5a9475);
}

void	get_new_rect(t_mlx *mlx, char pos)
{
	if (pos == '1' || pos == '$')
		draw_square(mlx, mlx->minimap.i, mlx->minimap.j, 0);
	else
		draw_square(mlx, mlx->minimap.i, mlx->minimap.j, 0xbea289);
}

void	minimap_render(t_mlx *mlx)
{
	mlx->minimap.xp = mlx->cub3d.player.x / 64;
	mlx->minimap.yp = mlx->cub3d.player.y / 64;
	mlx->minimap.x_pos = mlx->minimap.xp - 8;
	mlx->minimap.i = 0;
	while (mlx->minimap.x_pos < mlx->minimap.xp + 8)
	{
		mlx->minimap.j = 0;
		mlx->minimap.y_pos = mlx->minimap.yp - 8;
		while (mlx->minimap.y_pos < mlx->minimap.yp + 8)
		{
			if (mlx->minimap.x_pos >= 0 && mlx->minimap.y_pos >= 0
				&& mlx->minimap.y_pos < mlx->cub3d.map.y
				&& mlx->minimap.x_pos < mlx->cub3d.map.x)
				get_new_rect(mlx,
					mlx->cub3d.map_2d[mlx->minimap.y_pos][mlx->minimap.x_pos]);
			else
				draw_square(mlx, mlx->minimap.i, mlx->minimap.j, 0);
			mlx->minimap.y_pos++;
			mlx->minimap.j += 16;
		}
		mlx->minimap.x_pos++;
		mlx->minimap.i += 16;
	}
	draw_player(mlx);
}
