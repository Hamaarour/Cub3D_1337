/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_keys.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamaarou <hamaarou@1337.student.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 22:08:26 by mel-kabb          #+#    #+#             */
/*   Updated: 2023/11/15 01:11:16 by hamaarou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d.h"

void	move_down_up(t_mlx *mlx)
{
	float	movestep;
	float	newylayerx;
	float	newplayery;

	movestep = mlx->cub3d.player.walk_direction * mlx->cub3d.player.walk_speed;
	newylayerx = mlx->cub3d.player.x + cos(mlx->cub3d.player.rotation_angle)
		* movestep;
	newplayery = mlx->cub3d.player.y + sin(mlx->cub3d.player.rotation_angle)
		* movestep;
	if (check_wall(mlx, newylayerx, newplayery) == 0)
	{
		mlx->cub3d.player.x = newylayerx;
		mlx->cub3d.player.y = newplayery;
	}
}

void	move_left_right(t_mlx *mlx)
{
	float	movestep;
	float	newplayerx;
	float	newplayery;

	movestep = mlx->cub3d.player.walk_speed * mlx->cub3d.player.turn_direction;
	newplayerx = mlx->cub3d.player.x + cos(mlx->cub3d.player.rotation_angle
			+ M_PI_2) * movestep;
	newplayery = mlx->cub3d.player.y + sin(mlx->cub3d.player.rotation_angle
			+ M_PI_2) * movestep;
	if (check_wall(mlx, newplayerx, newplayery) == 0)
	{
		mlx->cub3d.player.x = newplayerx;
		mlx->cub3d.player.y = newplayery;
	}
}
