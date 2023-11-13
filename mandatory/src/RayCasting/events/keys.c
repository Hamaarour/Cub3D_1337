/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamaarou <hamaarou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 14:50:03 by hamaarou          #+#    #+#             */
/*   Updated: 2023/11/13 14:50:05 by hamaarou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d.h"

int key_release(int key, t_mlx *mlx)
{
	(void)mlx;
	if (key == KEY_UP)
		mlx->cub3d.player.walk_direction = 0;
	if (key == KEY_DOWN)
		mlx->cub3d.player.walk_direction = 0;
	if (key == KEY_RIGHT)
		mlx->cub3d.player.turn_direction = 0;
	if (key == KEY_LEFT)
		mlx->cub3d.player.turn_direction = 0;
	if (key == VIEW_RIGHT || key == VIEW_LEFT
		|| key == VIEW_RIGHT_MOUSE || key == VIEW_LEFT_MOUSE)
		mlx->cub3d.player.look = 0;
	return (0);
}
int mouse(int key, int x, int y, t_mlx *mlx)
{
	(void)x;
	(void)y;
	if (key == VIEW_RIGHT_MOUSE)
		mlx->cub3d.player.look = 1;
	if (key == VIEW_LEFT_MOUSE)
		mlx->cub3d.player.look = -1;
	return (0);
}

int key_press(int key, t_mlx *mlx)
{
	if (key == KEY_UP)
		mlx->cub3d.player.walk_direction = 1;
	if (key == KEY_DOWN)
		mlx->cub3d.player.walk_direction = -1;
	if (key == KEY_RIGHT)
		mlx->cub3d.player.turn_direction = 1;
	if (key == KEY_LEFT)
		mlx->cub3d.player.turn_direction = -1;
	if (key == VIEW_RIGHT ||  key == VIEW_RIGHT_MOUSE)
		mlx->cub3d.player.look = 1;
	if (key == VIEW_LEFT || key == VIEW_LEFT_MOUSE)
		mlx->cub3d.player.look = -1;
	if (key == KEY_ESC)
	{
		mlx_destroy_window(mlx->mlx_ptr, mlx->mlx_win);
		printf("[ESC] close window]\n");
		exit(0);
	}
	return (0);
}

int close_window(t_mlx *mlx)
{
	mlx_destroy_window(mlx->mlx_ptr, mlx->mlx_win);
	printf("close window\n");
	exit(0);
}



