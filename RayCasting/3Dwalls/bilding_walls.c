/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bilding_walls.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-kabb <mel-kabb@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 16:25:52 by mel-kabb          #+#    #+#             */
/*   Updated: 2023/11/07 22:02:11 by mel-kabb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

double get_x(t_mlx *mlx)
{
    double x;

    if (mlx->isVertical)
    {
        x = mlx->ray_y - (floor(mlx->ray_y / TILE_SIZE) * TILE_SIZE);    
    }
    else
    {
        x = mlx->ray_x - (floor(mlx->ray_x / TILE_SIZE) * TILE_SIZE);
    }
    x = (x / TILE_SIZE) * mlx->imgs.img_north.width;
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

    mlx->tex_y = 0;
    mlx->tex_x = get_x(mlx);
    raydistance = mlx->distance * cos(mlx->rayangle - mlx->cub3d.player.rotation_angle);
    distancePjPlane = (MAP_W / 2) / tan(FOV_ANGLE / 2); // distance between player and projection plane
    wallStripHeight = (TILE_SIZE / raydistance) * distancePjPlane;
    wallTP = (MAP_H / 2) - (wallStripHeight / 2);
    if(wallTP < 0)
    {
        mlx->tex_y = (((wallStripHeight / 2) - (MAP_H / 2)) / wallStripHeight) * mlx->imgs.img_north.height;        
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
        my_mlx_pixel_put(&mlx->data, nb, j, get_color(&mlx->data, mlx->tex_x, mlx->tex_y));
        mlx->tex_y += (mlx->imgs.img_north.height / wallStripHeight);
        j++;
    }
    
    while (j < MAP_H)
    {
        my_mlx_pixel_put(&mlx->data, nb, j, 0x808080);
        j++;
    }
}