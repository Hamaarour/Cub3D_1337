/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_draw.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-kabb <mel-kabb@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 18:38:47 by hamaarou          #+#    #+#             */
/*   Updated: 2023/11/10 15:06:04 by mel-kabb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

// double player_x = mlx->cub3d.player.x;
// double player_y = mlx->cub3d.player.y;
// double ray_x = mlx->ray_x;
// double ray_y = mlx->ray_y;

// double dx = ray_x - player_x;
// double dy = ray_y - player_y;

// double angle = mlx->cub3d.player.rotation_angle; // Assuming you have the player's rotation angle

// // Calculate the distance using cos
// mlx->distance = (dx * cos(angle) + dy * sin(angle));

void cast_ray(double ray_angle, t_mlx *mlx, int color)
{
    double player_x = mlx->cub3d.player.x;
    double player_y = mlx->cub3d.player.y;
    mlx->ray_x = player_x;
    mlx->ray_y = player_y;
    (void)color;

    double distance = 0.0;
    double angle_diff = mlx->cub3d.player.rotation_angle - ray_angle;

    while (1)
    {
        mlx->ray_x += cos(ray_angle);
        mlx->ray_y += sin(ray_angle);

        // Update mlx->tex_x and mlx->x_offset based on the ray angle

        if (check_wall(mlx, mlx->ray_x, mlx->ray_y))
        {
            distance = sqrt((mlx->ray_x - player_x) * (mlx->ray_x - player_x) + (mlx->ray_y - player_y) * (mlx->ray_y - player_y));

            // Apply fish-eye effect correction
            distance = distance * cos(angle_diff);

            mlx->distance = distance;

            break;
        }
    }
    if (ray_angle >= 0 && ray_angle < M_PI) {
        // Horizontal ray
        mlx->x_offset = (cos(ray_angle) > 0) ? 0 : 1; // Adjust as needed
        //mlx->tex_x = fmod(mlx->ray_y, TILE_SIZE) * 64 / TILE_SIZE;
    } else {
        // Vertical ray
        mlx->x_offset = (sin(ray_angle) > 0) ? 2 : 3; // Adjust as needed
        //mlx->tex_x = fmod(mlx->ray_x, TILE_SIZE) * 64 / TILE_SIZE;
    }
}


// Define the constants for horizontal and vertical angles (adjust as needed)
// Define the constants for horizontal and vertical angles (adjust as needed)
// #define HORIZONTAL_ANGLE_THRESHOLD (M_PI / 4.0)  // 45 degrees
// #define VERTICAL_ANGLE_THRESHOLD (M_PI - HORIZONTAL_ANGLE_THRESHOLD)

void ray(t_mlx *mlx, int color)
{
    double ray_angle;
    double ray_increment;
    int i;

    ray_angle = mlx->cub3d.player.rotation_angle - (FOV_ANGLE / 2);
    mlx->rayangle = ray_angle;
    ray_increment = FOV_ANGLE / MAP_W;
    i = 0;

    // Initialize the flags to 0
    mlx->isVertical = 0;
    mlx->isHorizontal = 0;

    while (i < MAP_W)
    {
        // Check if the current ray angle is horizontal or vertical
        //if (ray_angle <= HORIZONTAL_ANGLE_THRESHOLD || ray_angle >= (2 * M_PI - HORIZONTAL_ANGLE_THRESHOLD))
        cast_ray(ray_angle, mlx, color);
        if(roundf(fmod(mlx->ray_x,64)) == 0)
        {
            // if (sin(mlx->rayangle) > 0)
            //     mlx->x_offset = 0; // lta7t
            // else
            //     mlx->x_offset = 1; // lfog
            if (mlx->rayangle >= EA && mlx->rayangle < WE)
                mlx->x_offset = 0; // lta7t
            else
                mlx->x_offset = 1; // lfog
            mlx->isHorizontal = 1;
            mlx->isVertical = 0;  // Reset the vertical flag
        }

        else if (roundf(fmod(mlx->ray_y,64)) == 0)
        {
             if (mlx->rayangle >= SO && mlx->rayangle < NO)
                mlx->x_offset = 2; // lta7t
            else
                mlx->x_offset = 3;// lisar
            mlx->isVertical = 1;
            mlx->isHorizontal = 0;  // Reset the horizontal flag
        }
        render3dwalls(mlx, i);
        // mlx->arr_rays[i] = ray_angle;
        ray_angle += ray_increment;
        i++;
    }
}
// Define the constants for horizontal and vertical angles (adjust as needed)

// function to  calcul ray distance
// void ray(t_mlx *mlx, int color)
// {
// 	double	ray_angle;
// 	double	ray_increment;
// 	int		i;
// 	(void)color;
// 	ray_angle = mlx->cub3d.player.rotation_angle - (FOV_ANGLE / 2);
// 	mlx->rayangle = ray_angle;
// 	ray_increment = FOV_ANGLE / MAP_W;
// 	i = 0;
// 	while (i < MAP_W)
// 	{
// 		//mlx->arr_rays[i] = ray_angle;
// 		cast_ray(ray_angle, mlx, color);
// 		render3dwalls(mlx , i);
// 		ray_angle += ray_increment;
// 		i++;
// 	}
// }
