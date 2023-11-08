/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bilding_walls.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-kabb <mel-kabb@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 16:25:52 by mel-kabb          #+#    #+#             */
/*   Updated: 2023/11/08 01:10:28 by mel-kabb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"


double get_x(t_mlx *mlx)
{
    double x  = 0.0;

    // if(roundf(fmod(mlx->ray_y,64) == 0))
    // {
    //     printf("sdfjdfvbfgdj-++++++++++++++++++++++++++++++++++++++++++++++++\n");
    //     x = fmod(mlx->ray_y, TILE_SIZE) * 64 / 64;
    //     mlx->isHorizontal = 1;
    //     mlx->isVertical = 0;  // Reset the vertical flag
    // }

    // else if (roundf(fmod(mlx->ray_x,64) == 0))
    // {
    //     printf("sdfjdfvbfgdj---------------------------------------------\n");
    //     x = fmod(mlx->ray_x, TILE_SIZE) * 64 / 64;
    //     mlx->isVertical = 1;
    //     mlx->isHorizontal = 0;  // Reset the horizontal flag
    // // }
    if (mlx->isVertical == 1)
    {
        x = roundf(fmod(mlx->ray_x, TILE_SIZE));
        // x = mlx->ray_y - (floor(mlx->ray_y / TILE_SIZE) * TILE_SIZE);
        // if(x >= 62)
        //     x = roundf(fmod(mlx->ray_y, TILE_SIZE)); 
        printf("x1 = %f\n", x);

    }
    else if(mlx->isVertical == 0)
    {
        // x = mlx->ray_x - (floor(mlx->ray_x / TILE_SIZE) * TILE_SIZE);
        x = roundf(fmod(mlx->ray_y, TILE_SIZE));
        // if(x >= 62)
        //     x = roundf(fmod(mlx->ray_x, TILE_SIZE)); 
        printf("x = %f\n", x);
    }
    // x = (x / TILE_SIZE) * mlx->imgs.img_north.width;
    return (x);
}

void render3dwalls(t_mlx *mlx , int nb)
{
    //double ray[NUM_RAYS];
    double raydistance;
    double distancePjPlane;
    double wallStripHeight;
    double wallTP;
    double wallboP;
    double j;

    mlx->tex_y = 0.0;
    mlx->tex_x = get_x(mlx);
    raydistance = mlx->distance * cos(mlx->rayangle - mlx->cub3d.player.rotation_angle);
    distancePjPlane = (MAP_W / 2) / tan(FOV_ANGLE / 2); // distance between player and projection plane
    wallStripHeight = (TILE_SIZE / raydistance) * distancePjPlane;
    wallTP = (MAP_H / 2) - (wallStripHeight / 2);
    if(wallTP <= 0)
    {

        //mlx->tex_y = (((wallStripHeight / 2) - (MAP_H / 2)) / wallStripHeight) * 64;        
        wallTP = 0;
    }
    wallboP = (MAP_H / 2) + (wallStripHeight / 2);
    if(wallboP > MAP_H)
        wallboP = MAP_H;
    j = 0;
    while (j < wallTP)
    {
        my_mlx_pixel_put(&mlx->data, nb, j, 0xffffff);
        j++;
    }
    while (j < wallboP)
    {
        mlx->ray_y = fmod(j - (wallStripHeight / 2) * 64 / wallStripHeight, TILE_SIZE);
        my_mlx_pixel_put(&mlx->data, nb, j, get_color(mlx, mlx->tex_x, mlx->tex_y));
        //mlx->tex_y += (mlx->imgs.img_north.height / wallStripHeight);
        j++;
    }
    
    while (j < MAP_H)
    {
        my_mlx_pixel_put(&mlx->data, nb, j, 0x808080);
        j++;
    }
}

// void render3dwalls(t_mlx *mlx, int nb)
// {
//     double raydistance;
//     double distancePjPlane;
//     double wallStripHeight;
//     double wallTP;
//     double wallboP;
//     double j;

//     mlx->tex_y = 0;
//     mlx->tex_x = get_x(mlx);
//     raydistance = mlx->distance * cos(mlx->rayangle - mlx->cub3d.player.rotation_angle);
//     distancePjPlane = (MAP_W / 2) / tan(FOV_ANGLE / 2); // Distance between player and projection plane
//     wallStripHeight = (TILE_SIZE / raydistance) * distancePjPlane;
//     wallTP = (MAP_H / 2) - (wallStripHeight / 2);

//     if (wallTP < 0) {
//         mlx->tex_y = 0; // Adjust for top edge of the texture
//         wallTP = 0;
//     }

//     wallboP = (MAP_H / 2) + (wallStripHeight / 2);

//     if (wallboP > MAP_H) {
//         wallboP = MAP_H; // Ensure it doesn't go beyond the screen
//     }

//     j = 0;
//     while (j < wallTP) {
//         my_mlx_pixel_put(&mlx->data, nb, j, 0xffffff); // Draw ceiling color
//         j++;
//     }

//     while (j < wallboP) {
//         // Calculate the texture y-coordinate based on the wall height
//         int textureY = (mlx->tex_y / wallStripHeight) * 64;

//         my_mlx_pixel_put(&mlx->data, nb, j, get_color(mlx, mlx->tex_x, textureY));
//         mlx->tex_y += (mlx->imgs.img_north.height / wallStripHeight);
//         j++;
//     }

//     while (j < MAP_H) {
//         my_mlx_pixel_put(&mlx->data, nb, j, 0x808080); // Draw floor color
//         j++;
//     }
// }

