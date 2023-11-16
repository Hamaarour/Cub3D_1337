/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bilding_walls.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamaarou <hamaarou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 16:25:52 by mel-kabb          #+#    #+#             */
/*   Updated: 2023/11/16 19:09:20 by hamaarou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d.h"

int	check_wall_2(t_mlx *mlx, float x, float y)
{
	if (x < 0 || y < 0 || x >= MAP_W || y >= MAP_H)
		return (0);
	if (mlx->cub3d.map_2d[(int)(y / TILE_SIZE)][(int)(x / TILE_SIZE)] == '1')
		return (0);
	if (mlx->cub3d.map_2d[(int)((y - 2) / TILE_SIZE)][(int)(x
			/ TILE_SIZE)] == '1')
		return (1);
	if (mlx->cub3d.map_2d[(int)((y + 2) / TILE_SIZE)][(int)(x
			/ TILE_SIZE)] == '1')
		return (0);
	if (mlx->cub3d.map_2d[(int)(y / TILE_SIZE)][(int)((x - 2)
			/ TILE_SIZE)] == '1')
		return (1);
	if (mlx->cub3d.map_2d[(int)(y / TILE_SIZE)][(int)((x + 2)
			/ TILE_SIZE)] == '1')
		return (1);
	return (0);
}

void	getdirection(t_mlx *mlx)
{
	if (check_wall_2(mlx, mlx->ray_x - 2, mlx->ray_y) == 0)
		mlx->x_offset = 0;
	if (check_wall_2(mlx, mlx->ray_x, mlx->ray_y - 2) == 1)
		mlx->x_offset = 1;
	if (check_wall_2(mlx, mlx->ray_x, mlx->ray_y + 2) == 0)
		mlx->x_offset = 2;
	if (check_wall_2(mlx, mlx->ray_x - 2, mlx->ray_y) == 1)
		mlx->x_offset = 3;
	if (check_wall_2(mlx, mlx->ray_x - 1, mlx->ray_y - 2) == 1)
		mlx->x_offset = 0;
}

void	render3dwalls(t_mlx *mlx, int nb)
{
	unsigned int	color;
	int				j;

	mlx->tex_y = 0;
	mlx->tex_x = get_x(mlx);
	mlx->wall.ray_distance = mlx->distance * cos(mlx->rayangle
			- mlx->cub3d.player.rotation_angle);
	mlx->wall.distance_pjplane = (MAP_W / 2) / tan(FOV_ANGLE / 2);
	mlx->wall.wall_strip_height = (TILE_SIZE / mlx->wall.ray_distance) * mlx->wall.distance_pjplane;
	mlx->wall.walltp = (MAP_H / 2) - (mlx->wall.wall_strip_height / 2);
	if (mlx->wall.walltp <= 0)
		mlx->wall.walltp = 0;
	mlx->wall.wallbop = (MAP_H / 2) + (mlx->wall.wall_strip_height / 2);
	if (mlx->wall.wallbop > MAP_H)
		mlx->wall.wallbop = MAP_H;
	j = 0;
	while (j < mlx->wall.walltp)
	{
		my_mlx_pixel_put(&mlx->data, nb, j, rgb_to_int(mlx->cub3d.ceiling.r,
					mlx->cub3d.ceiling.g, mlx->cub3d.ceiling.b));
		j++;
	}
	while (j < mlx->wall.wallbop)
	{
		// my_mlx_pixel_put(&mlx->data, 64, 64, 0x000000);
		mlx->wall.distance_fromtop = j + (mlx->wall.wall_strip_height / 2) - (MAP_H / 2);
		mlx->tex_y = mlx->wall.distance_fromtop * (mlx->no_texture->height
				/ mlx->wall.wall_strip_height);
		color = 0;
		getdirection(mlx);
		if (mlx->x_offset == 0)
		{
			mlx->tex_y = mlx->wall.distance_fromtop * (mlx->so_texture->height
					/ mlx->wall.wall_strip_height);
			color = get_color(mlx->so_texture, mlx->tex_x, mlx->tex_y);
		}
		else if (mlx->x_offset == 1)
		{
			mlx->tex_y = mlx->wall.distance_fromtop * (mlx->no_texture->height
					/ mlx->wall.wall_strip_height);
			color = get_color(mlx->no_texture, mlx->tex_x, mlx->tex_y);
		}
		else if (mlx->x_offset == 2)
		{
			mlx->tex_y = mlx->wall.distance_fromtop * (mlx->ea_texture->height
					/ mlx->wall.wall_strip_height);
			color = get_color(mlx->ea_texture, mlx->tex_x, mlx->tex_y);
		}
		else if (mlx->x_offset == 3)
		{
			mlx->tex_y = mlx->wall.distance_fromtop * (mlx->we_texture->height
					/ mlx->wall.wall_strip_height);
			color = get_color(mlx->we_texture, mlx->tex_x, mlx->tex_y);
		}
		if (mlx->is_vertical == 0 && mlx->is_horizontal == 0)
			my_mlx_pixel_put(&mlx->data, nb, j, 0);
		my_mlx_pixel_put(&mlx->data, nb, j, color);
		j++;
	}
	while (j < MAP_H)
	{
		my_mlx_pixel_put(&mlx->data, nb, j, rgb_to_int(mlx->cub3d.floor.r,
					mlx->cub3d.floor.g, mlx->cub3d.floor.b));
		j++;
	}
}
