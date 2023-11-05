/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bilding_walls.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-kabb <mel-kabb@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 16:25:52 by mel-kabb          #+#    #+#             */
/*   Updated: 2023/11/05 14:49:25 by mel-kabb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void render3dwalls(t_mlx *mlx , int nb)
{
    //double ray[NUM_RAYS];
    double raydistance;
    double distancePjPlane;
    double wallStripHeight;
    double wallTP;
    double wallboP;
    double j;

    raydistance = mlx->distance * cos(mlx->rayangle - mlx->cub3d.player.rotation_angle);
    distancePjPlane = (MAP_W / 2) / tan(FOV_ANGLE / 2); // distance between player and projection plane
    wallStripHeight = (TILE_SIZE / raydistance) * distancePjPlane;
    
    wallTP = (MAP_H / 2) - (wallStripHeight / 2);
    if(wallTP < 0)
        wallTP = 0;
    
    wallboP = (MAP_H / 2) + (wallStripHeight / 2);
    if(wallboP > MAP_H)
        wallboP = MAP_H;
    j = 0;
    while (j < wallTP)
    {
        my_mlx_pixel_put(&mlx->data, nb, j, 0x00FF00);
        j++;
    }
    while (j < wallboP)
    {
        my_mlx_pixel_put(&mlx->data, nb, j, 0xf000f0);
        j++;
    }
    
    while (j < MAP_H)
    {
        my_mlx_pixel_put(&mlx->data, nb, j, 0x00FFFF);
        j++;
    }
}