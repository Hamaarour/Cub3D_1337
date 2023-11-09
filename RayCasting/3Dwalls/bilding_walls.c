/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bilding_walls.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-kabb <mel-kabb@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 16:25:52 by mel-kabb          #+#    #+#             */
/*   Updated: 2023/11/09 03:40:41 by mel-kabb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char *dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

unsigned int get_color(t_image *texture, int x, int y)
{
    char *dst;
    unsigned int color;

    dst = texture->addr + (y * texture->size_line + x * (texture->bits_per_pixel / 8));
    color = *(unsigned int *)dst;
    return color;
}

double get_x(t_mlx *mlx)
{
    double x = 0.0;

    if (mlx->isVertical == 1)
    {
        x = fmod(mlx->ray_y,64); // Calculate the relative Y-coordinate on the wall
        if (x >= 63)
        {
            x = fmod(mlx->ray_x,63); // Calculate the relative X-coordinate on the wall
        }
    }
    else
    {
        x = fmod(mlx->ray_x,64); // Calculate the relative Y-coordinate on the wall
        if (x >= 62)
        {
            x = fmod(mlx->ray_y,63); // Calculate the relative X-coordinate on the wall
        }
    }

    // Normalize the x coordinate to the texture width (64)
    // x = (x / TILE_SIZE) * 64;

    return x;
}


void render3dwalls(t_mlx *mlx, int nb)
{
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
    if (wallTP <= 0)
    {
        wallTP = 0;
    }
    wallboP = (MAP_H / 2) + (wallStripHeight / 2);
    if (wallboP > MAP_H)
    {
        wallboP = MAP_H;
    }
    j = 0;

    // Calculate the initial texture coordinate
    double textureCoord = 0;

    while (j < wallTP)
    {
        my_mlx_pixel_put(&mlx->data, nb, j, 0xffffff);
        j++;
    }
    while (j < wallboP)
    {
        // Use the texture coordinate for this row
        int distanceFromtop = j + (wallStripHeight / 2) - (MAP_H / 2);
        int texY = distanceFromtop * (mlx->no_texture->height / wallStripHeight);
        unsigned int color = 0;

        if (mlx->x_offset == 0)
        {
            color = get_color(mlx->so_texture, (int)mlx->tex_x, texY);
            //textureCoord += mlx->so_texture->height / wallStripHeight;
        }
        else if(mlx->x_offset == 1)
        {
            color = get_color(mlx->no_texture, (int)mlx->tex_x, texY);
            //textureCoord += mlx->no_texture->height / wallStripHeight;
        }
        else if(mlx->x_offset == 2)
        {
            color = get_color(mlx->ea_texture, (int)mlx->tex_x, texY);
            //textureCoord += mlx->ea_texture->height / wallStripHeight;
        }
        else if (mlx->x_offset == 3)    
        {
            color = get_color(mlx->we_texture, (int)mlx->tex_x, texY);
            //textureCoord += mlx->we_texture->height / wallStripHeight;
        }
        my_mlx_pixel_put(&mlx->data, nb, j, color);
        j++;
        // Adjust the texture coordinate for the next row
        textureCoord += mlx->no_texture->height / wallStripHeight;
    }
    while (j < MAP_H)
    {
        my_mlx_pixel_put(&mlx->data, nb, j, 0x808080);
        j++;
    }
}



