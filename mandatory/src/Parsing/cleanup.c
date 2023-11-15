/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamaarou <hamaarou@1337.student.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 18:31:08 by hamaarou          #+#    #+#             */
/*   Updated: 2023/11/15 04:26:10 by hamaarou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	clean_textures(t_cub3d *cub3d)
{
	if (cub3d->parse_direct.north_texture)
		free(cub3d->parse_direct.north_texture);
	if (cub3d->parse_direct.south_texture)
		free(cub3d->parse_direct.south_texture);
	if (cub3d->parse_direct.east_texture)
		free(cub3d->parse_direct.east_texture);
	if (cub3d->parse_direct.west_texture)
		free(cub3d->parse_direct.west_texture);
}

void	clean_map(char **matrice)
{
	int	i;

	i = 0;
	if (!matrice)
		return ;
	while (matrice[i])
	{
		free(matrice[i]);
		i++;
	}
	free(matrice);
}

void	clean_rgb(char *rgb, char *tmp)
{
	if (rgb)
		free(rgb);
	if (tmp)
		free(tmp);
}

void	free_t_image(t_mlx *mlx, t_image *img)
{
	if (img)
	{
		mlx_destroy_image(mlx->mlx_ptr, img->img);
		free(img);
	}
}

void	free_textures(t_mlx *mlx)
{
	if (mlx->ea_texture)
		free_t_image(mlx, mlx->ea_texture);
	if (mlx->no_texture)
		free_t_image(mlx, mlx->no_texture);
	if (mlx->so_texture)
		free_t_image(mlx, mlx->so_texture);
	if (mlx->we_texture)
		free_t_image(mlx, mlx->we_texture);
}

void	cleanup(t_mlx *mlx)
{
	clean_textures(&mlx->cub3d);
	clean_map(mlx->cub3d.map_2d);
	free(mlx->cub3d.map_1d);
	free_textures(mlx);
}
