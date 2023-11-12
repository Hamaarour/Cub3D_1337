/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamaarou <hamaarou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 16:30:58 by hamaarou          #+#    #+#             */
/*   Updated: 2023/11/12 18:19:06 by hamaarou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "./includes/cub3d.h"

void printf_test(t_cub3d cub3d)
{
	printf("NORTH : '%s'\n", cub3d.parse_direct.north_texture);
	printf("SOUTH : '%s'\n", cub3d.parse_direct.south_texture);
	printf("EAST : '%s'\n", cub3d.parse_direct.east_texture);
	printf("WEST : '%s'\n", cub3d.parse_direct.west_texture);
	printf("FLOOR : '%d,%d,%d'\n", cub3d.floor.r, cub3d.floor.g, cub3d.floor.b);
	printf("CEILING : '%d,%d,%d'\n", cub3d.ceiling.r, cub3d.ceiling.g, cub3d.ceiling.b);
	int i = 0;
	while (cub3d.map_2d[i])
	{
		printf("MAP : {%s}\n", cub3d.map_2d[i]);
		i++;
	}
}

int main(int ac, char *av[])
{
	t_mlx mlx;

	init_all(&mlx.cub3d);
	if (ac == 2)
	{
		mlx.cub3d.file_name = av[1];
		mlx.cub3d.fd = open(mlx.cub3d.file_name, O_RDONLY);
		if (mlx.cub3d.fd == -1)
			return (1);
		if (start_parsing(&mlx.cub3d) == EXIT_FAILURE || config_file_is_set(mlx.cub3d) == EXIT_FAILURE)
		{
			ft_putendl_fd("\033[0;31m 📛Error Invalid Map📛 \033[0m", 2);
			return (free_all(&mlx.cub3d), 1);
		}
		else
		{
			mlx.mlx_ptr = mlx_init();
			mlx.mlx_win = mlx_new_window(mlx.mlx_ptr, MAP_W, MAP_H, "cub3d");
			player_init(&mlx.cub3d);
			textures_init(&mlx);
			render(&mlx);
			mlx_hook(mlx.mlx_win, 2, 1L << 0, key_press, &mlx);
			mlx_hook(mlx.mlx_win, 3, 1L << 1, key_release, &mlx);
			mlx_hook(mlx.mlx_win, 6, 1L << 6, mouse, &mlx);
			mlx_hook(mlx.mlx_win, 17, 1L << 2, close_window, &mlx);
			mlx_loop_hook(mlx.mlx_ptr, game, &mlx);
			mlx_loop(mlx.mlx_ptr);
			free_all(&mlx.cub3d);
		}
		close(mlx.cub3d.fd);
		return (0);
	}
	return (1);
}