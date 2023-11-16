/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderwall.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-kabb <mel-kabb@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 23:25:13 by mel-kabb          #+#    #+#             */
/*   Updated: 2023/11/15 23:41:49 by mel-kabb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d.h"

int	check_wall_2(t_mlx *mlx, float x, float y)
{
	if (mlx->cub3d.map_2d[(int)(y / TILE_SIZE)][(int)(x / TILE_SIZE)] == '1')
		return (0);
	if (mlx->cub3d.map_2d[(int)((y - 2) / TILE_SIZE)][(int)(x
			/ TILE_SIZE)] == '1')
		return (1);
	if (mlx->cub3d.map_2d[(int)((y + 2) / TILE_SIZE)][(int)(x
			/ TILE_SIZE)] == '1')
		return (0);
	if (mlx->cub3d.map_2d[(int)(y / TILE_SIZE)][(int)((x - 2)
			/ TILE_SIZE)] == '1')
		return (1);
	if (mlx->cub3d.map_2d[(int)(y / TILE_SIZE)][(int)((x + 2)
			/ TILE_SIZE)] == '1')
		return (1);
	return (0);
}

void	getdirection(t_mlx *mlx)
{
	if (check_wall_2(mlx, mlx->ray_x - 2, mlx->ray_y) == 0)
		mlx->x_offset = 0;
	if (check_wall_2(mlx, mlx->ray_x, mlx->ray_y - 2) == 1)
		mlx->x_offset = 1;
	if (check_wall_2(mlx, mlx->ray_x, mlx->ray_y + 2) == 0)
		mlx->x_offset = 2;
	if (check_wall_2(mlx, mlx->ray_x - 2, mlx->ray_y) == 1)
		mlx->x_offset = 3;
	if (check_wall_2(mlx, mlx->ray_x - 1, mlx->ray_y - 2) == 1)
		mlx->x_offset = 0;
}
