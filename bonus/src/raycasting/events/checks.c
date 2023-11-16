/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamaarou <hamaarou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 17:11:42 by hamaarou          #+#    #+#             */
/*   Updated: 2023/11/16 19:51:25 by hamaarou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d.h"

int	is_player(char c)
{
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
		return (1);
	return (0);
}

int	is_wall(char c)
{
	if (c == '1')
		return (1);
	return (0);
}

int	check_wall(t_mlx *mlx, float x, float y)
{
	if ((int)x < 0 || (int)y < 0 || (int)x >= MAP_W || (int)y >= MAP_H)
		return (1);
	if (mlx->cub3d.map_2d[(int)(y / TILE_SIZE)][(int)(x / TILE_SIZE)] == '1'
		|| mlx->cub3d.map_2d[(int)(y / TILE_SIZE)][(int)(x / TILE_SIZE)] == '$')
		return (1);
	if (mlx->cub3d.map_2d[(int)((y - 2) / TILE_SIZE)][(int)(x
			/ TILE_SIZE)] == '1' || mlx->cub3d.map_2d[(int)((y
			- 2) / TILE_SIZE)][(int)(x / TILE_SIZE)] == '$')
		return (1);
	if (mlx->cub3d.map_2d[(int)((y + 2) / TILE_SIZE)][(int)(x
			/ TILE_SIZE)] == '1' || mlx->cub3d.map_2d[(int)((y
			+ 2) / TILE_SIZE)][(int)(x / TILE_SIZE)] == '$')
		return (1);
	if (mlx->cub3d.map_2d[(int)(y / TILE_SIZE)][(int)((x - 2)
			/ TILE_SIZE)] == '1' || mlx->cub3d.map_2d[(int)(y
			/ TILE_SIZE)][(int)((x - 2) / TILE_SIZE)] == '$')
		return (1);
	if (mlx->cub3d.map_2d[(int)(y / TILE_SIZE)][(int)((x + 2)
			/ TILE_SIZE)] == '1' || mlx->cub3d.map_2d[(int)(y
			/ TILE_SIZE)][(int)((x + 2) / TILE_SIZE)] == '$')
		return (1);
	return (0);
}
