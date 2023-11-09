/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamaarou <hamaarou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 16:26:03 by mel-kabb          #+#    #+#             */
/*   Updated: 2023/11/09 20:52:07 by hamaarou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void render(t_mlx *mlx)
{
	mlx->data.img = mlx_new_image(mlx->mlx_ptr,MAP_W, MAP_H);
	mlx->data.addr = mlx_get_data_addr(mlx->data.img, &mlx->data.bits_per_pixel, &mlx->data.line_length, &mlx->data.endian);
	ray(mlx, 0x00ff00);
	cast_ray(mlx->cub3d.player.rotation_angle, mlx, 0xff0000);
	//minimap_render(mlx);
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->mlx_win, mlx->data.img, 0, 0);
	return ;
}

int game(t_mlx *mlx)
{
	if (mlx->cub3d.player.walk_direction)
		move_down_up(mlx);
	if (mlx->cub3d.player.turn_direction)
		look_left_right(mlx);
	if (mlx->cub3d.player.look)
		look_left_right(mlx);
	render(mlx);
	return (0);
}
