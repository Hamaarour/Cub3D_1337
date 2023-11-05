/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_draw.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-kabb <mel-kabb@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 18:38:47 by hamaarou          #+#    #+#             */
/*   Updated: 2023/11/05 14:37:47 by mel-kabb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void cast_ray(double ray_angle, t_mlx *mlx, int color)
{
	double player_x = mlx->cub3d.player.x;
	double player_y = mlx->cub3d.player.y;
	mlx->ray_x = player_x;
	mlx->ray_y = player_y;
	(void)color;

	while (1)
	{
		mlx->ray_x += cos(ray_angle);
		mlx->ray_y += sin(ray_angle);
		if (check_wall(mlx, mlx->ray_x, mlx->ray_y))
			break;
		mlx->distance = sqrt(pow(mlx->ray_x - player_x, 2) + pow(mlx->ray_y - player_y, 2));
		// my_mlx_pixel_put(&mlx->data, SCALE_FACTOR * (double)mlx->ray_x, SCALE_FACTOR * (double)mlx->ray_y, color);
	}
}

// function to  calcul ray distance
void ray(t_mlx *mlx, int color)
{
	double	ray_angle;
	double	ray_increment;
	int		i;
	(void)color;
	ray_angle = mlx->cub3d.player.rotation_angle - (FOV_ANGLE / 2);
	mlx->rayangle = ray_angle;
	ray_increment = FOV_ANGLE / MAP_W;
	i = 0;
	while (i < MAP_W)
	{
		//mlx->arr_rays[i] = ray_angle;
		cast_ray(ray_angle, mlx, color);
		render3dwalls(mlx , i);
		ray_angle += ray_increment;
		i++;
	}
}
