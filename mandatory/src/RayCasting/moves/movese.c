/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movese.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-kabb <mel-kabb@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 14:49:12 by hamaarou          #+#    #+#             */
/*   Updated: 2023/11/14 22:19:03 by mel-kabb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d.h"

void	look_left_right(t_mlx *mlx)
{
	mlx->cub3d.player.rotation_angle += mlx->cub3d.player.look
		* mlx->cub3d.player.turn_speed;
}

void	move_down_up(t_mlx *mlx)
{
	float	movestep;
	float	newplayerx;
	float	newplayery;

	movestep = mlx->cub3d.player.walk_direction * mlx->cub3d.player.walk_speed;
	newplayerx = mlx->cub3d.player.x + cos(mlx->cub3d.player.rotation_angle)
		* movestep;
	newplayery = mlx->cub3d.player.y + sin(mlx->cub3d.player.rotation_angle)
		* movestep;
	if (check_wall(mlx, newplayerx, newplayery) == 0)
	{
		mlx->cub3d.player.x = newplayerx;
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
