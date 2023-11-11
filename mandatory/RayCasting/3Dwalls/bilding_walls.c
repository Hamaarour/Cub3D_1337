/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bilding_walls.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamaarou <hamaarou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 16:25:52 by mel-kabb          #+#    #+#             */
/*   Updated: 2023/11/11 19:27:20 by hamaarou         ###   ########.fr       */
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
    return (color);
}

double get_x(t_mlx *mlx)
{
    int x = 0;

    if (mlx->isVertical == 1)
    {
        x = fmod(mlx->ray_y, 64); // Calculate the relative Y-coordinate on the wall
        if (x >= 62 || x <= 1)
            x = fmod(mlx->ray_x, 64); // Calculate the relative X-coordinate on the wall
    }
    else
    {
        x = fmod(mlx->ray_x, 64);
        if (x >= 62 || x <= 1)
            x = fmod(mlx->ray_y, 64); // Calculate the relative X-coordinate on the wall
    }
    return x;
}

void getdirection(t_mlx *mlx)
{
    int rx;
    int ry;

    rx = (int)(mlx->ray_x / TILE_SIZE);
    ry = (int)(mlx->ray_y / TILE_SIZE);


    if (check_wall(mlx, mlx->ray_x - 2, mlx->ray_y))
    {
        mlx->x_offset = 0;
    }
    if (check_wall(mlx, mlx->ray_x, mlx->ray_y - 2))
    {

        mlx->x_offset = 1;
    }
    if (check_wall(mlx, mlx->ray_x, mlx->ray_y + 2))
    {

        mlx->x_offset = 2;
    }

    if (check_wall(mlx, mlx->ray_x - 2, mlx->ray_y))
    {

        mlx->x_offset = 3;
    }
}

void render3dwalls(t_mlx *mlx, int nb)
{
    float raydistance;
    float distancePjPlane;
    float wallStripHeight;
    float wallTP;
    float wallboP;
    int j;

    mlx->tex_y = 0;
    mlx->tex_x = get_x(mlx);
    raydistance = mlx->distance * cos(mlx->rayangle - mlx->cub3d.player.rotation_angle);

    distancePjPlane = (MAP_W / 2) / tan(FOV_ANGLE / 2); // distance between player and projection plane
    wallStripHeight = (TILE_SIZE / raydistance) * distancePjPlane;
    wallTP = (MAP_H / 2) - (wallStripHeight / 2);
    if (wallTP <= 0)
        wallTP = 0;
    wallboP = (MAP_H / 2) + (wallStripHeight / 2);
    if (wallboP > MAP_H)
        wallboP = MAP_H;
    j = 0;
    while (j < wallTP)
    {
        my_mlx_pixel_put(&mlx->data, nb, j, 0x6489ac);
        j++;
    }

    while (j < wallboP)
    {
        int distanceFromtop = j + (wallStripHeight / 2) - (MAP_H / 2);
        mlx->tex_y = distanceFromtop * (mlx->no_texture->height / wallStripHeight);
        unsigned int color = 0;
    getdirection(mlx);
        if (mlx->x_offset == 0)
            color = get_color(mlx->so_texture, (int)mlx->tex_x, (int)mlx->tex_y);
        if(mlx->x_offset == 1)
            color = get_color(mlx->no_texture, (int)mlx->tex_x, (int)mlx->tex_y);
        if(mlx->x_offset == 2)
            color = get_color(mlx->ea_texture, (int)mlx->tex_x, (int)mlx->tex_y);
        if (mlx->x_offset == 3)
            color = get_color(mlx->we_texture, (int)mlx->tex_x, (int)mlx->tex_y);
        my_mlx_pixel_put(&mlx->data, nb, j, color);
        j++;
    }
    while (j < MAP_H)
    {
        my_mlx_pixel_put(&mlx->data, nb, j, 0xa4764a);
        j++;
    }
}



