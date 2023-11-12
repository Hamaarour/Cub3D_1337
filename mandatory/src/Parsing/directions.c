/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   directions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamaarou <hamaarou@1337.student.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 17:48:06 by hamaarou          #+#    #+#             */
/*   Updated: 2023/11/08 20:06:21 by hamaarou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	is_cardinal_direction(char *line)
{
	line = ft_strtrim(line, " ");
	if (line && ((line[0] == 'N' && line[1] == 'O')
		|| (line[0] == 'S' && line[1] == 'O')
		|| (line[0] == 'E' && line[1] == 'A')
		|| (line[0] == 'W' && line[1] == 'E')))
			return (free(line), 1);
	return (free(line), 0);
}

int save_textures(char **matrice, t_cub3d *cub3d)
{
	char	*tmp;

	tmp = ft_strtrim(matrice[1], " ");
	if (ft_matrice_len(matrice) == 2)
	{
		if (tmp[0] == '.' && tmp[1] == '/')
		{
			if (matrice[0][0] == 'N' && matrice[0][1] == 'O' && !cub3d->parse_direct.north_texture)
				cub3d->parse_direct.north_texture = ft_strtrim(tmp, "\n");
			else if (matrice[0][0] == 'S' && matrice[0][1] == 'O' && !cub3d->parse_direct.south_texture)
				cub3d->parse_direct.south_texture = ft_strtrim(tmp, "\n");
			else if (matrice[0][0] == 'E' && matrice[0][1] == 'A' && !cub3d->parse_direct.east_texture)
				cub3d->parse_direct.east_texture = ft_strtrim(tmp, "\n");
			else if (matrice[0][0] == 'W' && matrice[0][1] == 'E' && !cub3d->parse_direct.west_texture)
				cub3d->parse_direct.west_texture = ft_strtrim(tmp, "\n");
			else
				return (free(tmp), EXIT_FAILURE);
		}
		else
			return (free(tmp), EXIT_FAILURE);
	}
	return (free(tmp), EXIT_SUCCESS);
}

int save_cardinal_directions(t_cub3d *cub3d, char *line)
{
	int		status;
	char	**split;

	status = EXIT_FAILURE;
	split = ft_split(ft_strtrim(line, " "), ' ');
	if (ft_matrice_len(split) == 2)
	{
		status = save_textures(split, cub3d);
		return (clean_map(split), status);
	}
	else
	{
		ft_putendl_fd("\033[0;31m Error Invalid line\033[0m", 2);
		return (clean_map(split), status);
	}
	return (0);
}
