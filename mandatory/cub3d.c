/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamaarou <hamaarou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 16:30:58 by hamaarou          #+#    #+#             */
/*   Updated: 2023/11/12 22:28:38 by hamaarou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/cub3d.h"

void gameloop(t_mlx *mlx)
{
	mlx->mlx_ptr = mlx_init();
	mlx->mlx_win = mlx_new_window(mlx->mlx_ptr, MAP_W, MAP_H, "cub3d");
	player_init(&mlx->cub3d);
	textures_init(mlx);
	render(mlx);
	mlx_hook(mlx->mlx_win, 2, 1L << 0, key_press, mlx);
	mlx_hook(mlx->mlx_win, 3, 1L << 1, key_release, mlx);
	mlx_hook(mlx->mlx_win, 6, 1L << 6, mouse, &mlx);
	mlx_hook(mlx->mlx_win, 17, 1L << 2, close_window, mlx);
	mlx_loop_hook(mlx->mlx_ptr, game, mlx);
	mlx_loop(mlx->mlx_ptr);
	cleanup(&mlx->cub3d);
}

int ready(t_mlx *mlx, char **av)
{
	mlx->cub3d.file_name = av[1];
	mlx->cub3d.fd = open(mlx->cub3d.file_name, O_RDONLY);
	if (mlx->cub3d.fd == -1)
		return (0);
	if (start_parsing(&mlx->cub3d) == EXIT_FAILURE
		|| check_graphics(mlx->cub3d) == EXIT_FAILURE)
	{
		ft_putendl_fd("\033[0;31m 📛 Error Invalid Map 📛 \033[0m", 2);
		return (cleanup(&mlx->cub3d), 0);
	}
	return (1);
}

int main(int ac, char *av[])
{
	t_mlx mlx;

	if (ac == 2)
	{
		initialize(&mlx.cub3d);
		if (ready(&mlx, av))
			gameloop(&mlx);
		close(mlx.cub3d.fd);
		return (0);
	}
	return (1);
}

