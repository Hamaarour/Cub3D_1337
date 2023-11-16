/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamaarou <hamaarou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 16:26:03 by mel-kabb          #+#    #+#             */
/*   Updated: 2023/11/16 18:54:51 by hamaarou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d.h"

void	render(t_mlx *mlx)
{
	if(mlx->data.img)
		mlx_destroy_image(mlx->mlx_ptr, mlx->data.img);
	mlx->data.img = mlx_new_image(mlx->mlx_ptr, MAP_W, MAP_H);
	mlx->data.addr = mlx_get_data_addr(mlx->data.img, &mlx->data.bits_per_pixel,
			&mlx->data.line_length, &mlx->data.endian);
	ray(mlx);
	if (MAP_H <= 256 || MAP_W <= 256)
	{
		ft_putendl_fd("Error\nMap is too small to be rendered", 2);
		cleanup(mlx);
		exit(EXIT_FAILURE);
	}
	minimap_render(mlx);
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->mlx_win, mlx->data.img, 0, 0);
	return ;
}

int	game(t_mlx *mlx)
{
	if (mlx->cub3d.player.walk_direction)
		move_down_up(mlx);
	if (mlx->cub3d.player.turn_direction)
		move_left_right(mlx);
	if (mlx->cub3d.player.look)
		look_left_right(mlx);
	// render(mlx);
	return (0);
}
