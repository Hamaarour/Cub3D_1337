/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   directions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-kabb <mel-kabb@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 17:48:06 by hamaarou          #+#    #+#             */
/*   Updated: 2023/11/21 15:10:27 by mel-kabb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	is_cardinal_direction(char *line)
{
	char	*tmp;

	tmp = ft_strtrim(line, " ");
	if (tmp && ((tmp[0] == 'N' && tmp[1] == 'O')
			|| (tmp[0] == 'S' && tmp[1] == 'O')
			|| (tmp[0] == 'E' && tmp[1] == 'A')
			|| (tmp[0] == 'W' && tmp[1] == 'E')))
		return (free(tmp), EXIT_SUCCESS);
	return (free(tmp), EXIT_FAILURE);
}

int	check_xpm_extension(char *path)
{
	int	len;

	len = ft_strlen(path);
	if (!ft_strncmp(path + (len - 4), ".xpm", 4))
		return (EXIT_SUCCESS);
	return (EXIT_FAILURE);
}

int	fill_textures(char **matrice, t_cub3d *cub3d, char *tmp)
{
	if (matrice[1][0] != '.' && matrice[1][1] != '/')
		return (EXIT_FAILURE);
	if (matrice[0][0] == 'N' && matrice[0][1] == 'O'
		&& cub3d->parse_direct.north_texture == NULL)
			cub3d->parse_direct.north_texture = ft_strtrim(tmp, "\n");
	else if (matrice[0][0] == 'S' && matrice[0][1] == 'O'
		&& cub3d->parse_direct.south_texture == NULL)
		cub3d->parse_direct.south_texture = ft_strtrim(tmp, "\n");
	else if (matrice[0][0] == 'E' && matrice[0][1] == 'A'
		&& cub3d->parse_direct.east_texture == NULL)
			cub3d->parse_direct.east_texture = ft_strtrim(tmp, "\n");
	else if (matrice[0][0] == 'W' && matrice[0][1] == 'E'
		&& cub3d->parse_direct.west_texture == NULL)
			cub3d->parse_direct.west_texture = ft_strtrim(tmp, "\n");
	else
	{
		ft_putendl_fd("\033[0;31m Error Invalid line\033[0m", 2);
		exit (EXIT_FAILURE);
	}
	if (!check_xpm_extension(tmp))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	save_textures(char **matrice, t_cub3d *cub3d)
{
	char	*tmp;

	tmp = ft_strtrim(matrice[1], " ");
	if (ft_matrice_len(matrice) == 2)
		if (fill_textures(matrice, cub3d, tmp) == EXIT_FAILURE)
			return (free(tmp), EXIT_FAILURE);
	return (free(tmp), EXIT_SUCCESS);
}

int	save_cardinal_directions(t_cub3d *cub3d, char *line)
{
	int		status;
	char	**split;
	char	*tmp;

	status = EXIT_FAILURE;
	tmp = ft_strtrim(line, " ");
	split = ft_split(tmp, ' ');
	free(tmp);
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
