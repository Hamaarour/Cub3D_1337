/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamaarou <hamaarou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 21:32:44 by hamaarou          #+#    #+#             */
/*   Updated: 2023/11/20 16:45:26 by hamaarou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d.h"

int	check_texture_2(void *ptr)
{
	if ((char *)ptr == NULL)
	{
		ft_putendl_fd("\033[0;31m 📛 Error Invalid Textures \033[0m", 2);
		exit (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

t_image	*new_texture(t_mlx *mlx, char *path)
{
	t_image	*img;

	img = (t_image *)malloc(sizeof(t_image));
	if (!img)
	{
		printf("Error\nmalloc failed\n");
		exit(1);
	}
	img->img = mlx_xpm_file_to_image(mlx->mlx_ptr, path, &img->width,
			&img->height);
	if (check_texture_2(img->img) == EXIT_FAILURE)
		return (NULL);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel,
			&img->size_line, &img->endian);
	if (check_texture_2(img->addr) == EXIT_FAILURE)
		return (NULL);
	return (img);
}

void	textures_init(t_mlx *mlx)
{
	mlx->no_texture = new_texture(mlx, mlx->cub3d.parse_direct.north_texture);
	mlx->so_texture = new_texture(mlx, mlx->cub3d.parse_direct.south_texture);
	mlx->we_texture = new_texture(mlx, mlx->cub3d.parse_direct.west_texture);
	mlx->ea_texture = new_texture(mlx, mlx->cub3d.parse_direct.east_texture);
	if (mlx->no_texture == NULL || mlx->so_texture == NULL
		|| mlx->we_texture == NULL || mlx->ea_texture == NULL)
	{
		cleanup(mlx);
		exit(EXIT_FAILURE);
	}
}
