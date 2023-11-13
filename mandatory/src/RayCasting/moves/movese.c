/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movese.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamaarou <hamaarou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 14:49:12 by hamaarou          #+#    #+#             */
/*   Updated: 2023/11/13 14:49:34 by hamaarou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../../includes/cub3d.h"

void look_left_right(t_mlx *mlx)
{
	mlx->cub3d.player.rotation_angle += mlx->cub3d.player.look * mlx->cub3d.player.turn_speed;
}

void move_down_up(t_mlx *mlx)
{
	float moveStep = mlx->cub3d.player.walk_direction * mlx->cub3d.player.walk_speed;
	float newPlayerX = mlx->cub3d.player.x + cos(mlx->cub3d.player.rotation_angle) * moveStep;
	float newPlayerY = mlx->cub3d.player.y + sin(mlx->cub3d.player.rotation_angle) * moveStep;
	if (check_wall(mlx, newPlayerX, newPlayerY) == 0)
	{
		mlx->cub3d.player.x = newPlayerX;
		mlx->cub3d.player.y = newPlayerY;
	}
}
void move_left_right(t_mlx *mlx)
{
	float moveStep = mlx->cub3d.player.walk_speed * mlx->cub3d.player.turn_direction;
	float newPlayerX = mlx->cub3d.player.x + cos(mlx->cub3d.player.rotation_angle + M_PI_2) * moveStep;
	float newPlayerY = mlx->cub3d.player.y + sin(mlx->cub3d.player.rotation_angle + M_PI_2) * moveStep;

	if (check_wall(mlx, newPlayerX, newPlayerY) == 0)
	{
		mlx->cub3d.player.x = newPlayerX;
		mlx->cub3d.player.y = newPlayerY;
	}
}
