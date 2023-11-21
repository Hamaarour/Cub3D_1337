/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamaarou <hamaarou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 17:05:01 by hamaarou          #+#    #+#             */
/*   Updated: 2023/11/20 19:07:03 by hamaarou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	check_rgb(t_cub3d cube3d)
{
	if (cube3d.ceiling.r > 255 || cube3d.ceiling.r < 0)
		return (EXIT_FAILURE);
	if (cube3d.ceiling.g > 255 || cube3d.ceiling.g < 0)
		return (EXIT_FAILURE);
	if (cube3d.ceiling.b > 255 || cube3d.ceiling.b < 0)
		return (EXIT_FAILURE);
	if (cube3d.floor.r > 255 || cube3d.floor.r < 0)
		return (EXIT_FAILURE);
	if (cube3d.floor.g > 255 || cube3d.floor.g < 0)
		return (EXIT_FAILURE);
	if (cube3d.floor.b > 255 || cube3d.floor.b < 0)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	check_texture(t_cub3d cube3d)
{
	if (!cube3d.parse_direct.north_texture)
		return (EXIT_FAILURE);
	if (!cube3d.parse_direct.south_texture)
		return (EXIT_FAILURE);
	if (!cube3d.parse_direct.east_texture)
		return (EXIT_FAILURE);
	if (!cube3d.parse_direct.west_texture)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	is_rgb(t_cub3d cub)
{
	if (cub.ceiling.r == -1 || cub.ceiling.g == -1 || cub.ceiling.b == -1)
		return (EXIT_FAILURE);
	if (cub.floor.r == -1 || cub.floor.g == -1 || cub.floor.b == -1)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	is_map_last_element(t_cub3d cub)
{
	if (check_texture(cub) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (is_rgb(cub) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	check_graphics(t_cub3d cub3d)
{
	if (is_map_last_element(cub3d) == EXIT_FAILURE)
	{
		ft_putendl_fd("\033[0;31m  📛 Error Invalid Map 📛\033[0m", 2);
		exit (EXIT_FAILURE);
	}
	if (check_rgb(cub3d) == EXIT_FAILURE)
	{
		ft_putendl_fd("\033[0;31m  📛 Error Invalid Map 📛\033[0m", 2);
		exit (EXIT_FAILURE);
	}
	if (check_texture(cub3d) == EXIT_FAILURE)
	{
		ft_putendl_fd("\033[0;31m  📛 Error Invalid Map 📛\033[0m", 2);
		exit (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
