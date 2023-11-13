/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_draw.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamaarou <hamaarou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 18:38:47 by hamaarou          #+#    #+#             */
/*   Updated: 2023/11/13 13:51:53 by hamaarou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d.h"

void cast_ray(double ray_angle, t_mlx *mlx)
{
    double player_x = mlx->cub3d.player.x;
    double player_y = mlx->cub3d.player.y;
    mlx->ray_x = player_x;
    mlx->ray_y = player_y;

    double distance = 0.0;
    double angle_diff = mlx->cub3d.player.rotation_angle - ray_angle;

    while (1)
    {
        mlx->ray_x += cos(ray_angle);
        mlx->ray_y += sin(ray_angle);
        if (check_wall(mlx, mlx->ray_x, mlx->ray_y))
        {
            distance = sqrt((mlx->ray_x - player_x) * (mlx->ray_x - player_x) + (mlx->ray_y - player_y) * (mlx->ray_y - player_y));
            distance = distance * cos(angle_diff);
            mlx->distance = distance;
            break;
        }
    }
}

void ray(t_mlx *mlx)
{
    double ray_angle;
    double ray_increment;
    int i;

    ray_angle = mlx->cub3d.player.rotation_angle - (FOV_ANGLE / 2);
    mlx->rayangle = ray_angle;
    ray_increment = FOV_ANGLE / MAP_W;
    i = 0;

    // Initialize the flags to 0
    mlx->is_vertical = 0;
    mlx->is_horizontal = 0;

    while (i < MAP_W)
    {
        cast_ray(ray_angle, mlx);
        if(roundf(fmod(mlx->ray_x,64)) == 0)
        {
            mlx->is_horizontal = 1;
            mlx->is_vertical = 0;  // Reset the vertical flag
        }

        else if (roundf(fmod(mlx->ray_y,64)) == 0)
        {
            mlx->is_vertical = 1;
            mlx->is_horizontal = 0;  // Reset the horizontal flag
        }
        render3dwalls(mlx, i);
        ray_angle += ray_increment;
        i++;
    }
}
