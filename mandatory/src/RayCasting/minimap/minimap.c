/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamaarou <hamaarou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 17:34:09 by hamaarou          #+#    #+#             */
/*   Updated: 2023/11/12 21:31:51 by hamaarou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d.h"

void	draw_square(t_mlx *mlx, int x, int y, int size, int color)
{
	int i;
	int j;

	i = y;
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
	y = x; //(8 * 17) - 8
	draw_square(mlx, x, y, 16, 0x5a9475);
}

void	get_new_rect(t_mlx *mlx, int i, int j, char pos)
{
	if(pos == '1')
		draw_square(mlx, i, j, 16, 0);
	else
		draw_square(mlx, i, j, 16, 0xbea289);
}

void	minimap_render(t_mlx *mlx)
{
	int	i;
	int	j;
	int xp;
	int yp;

	xp = mlx->cub3d.player.x / 64;
	yp = mlx->cub3d.player.y / 64;
	mlx->minimap.x_pos = xp - 8;
	i = 0;
	while (mlx->minimap.x_pos < xp + 8)
	{
		j = 0;
		mlx->minimap.y_pos = yp - 8;
		while (mlx->minimap.y_pos < yp + 8)
		{
			if (mlx->minimap.x_pos >= 0 && mlx->minimap.y_pos >= 0
				&& mlx->minimap.y_pos < mlx->cub3d.map.y
				&& mlx->minimap.x_pos < mlx->cub3d.map.x)
				get_new_rect(mlx,i, j, mlx->cub3d.map_2d[mlx->minimap.y_pos][mlx->minimap.x_pos]);
			else
				draw_square(mlx, i , j , 16, 0);
			mlx->minimap.y_pos++;
			j += 16;
		}
		mlx->minimap.x_pos++;
		i += 16;
	}
	draw_player(mlx);
}
