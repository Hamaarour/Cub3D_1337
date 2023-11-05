/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_textures.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamaarou <hamaarou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 17:48:06 by hamaarou          #+#    #+#             */
/*   Updated: 2023/11/04 17:50:58 by hamaarou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	fill_textures(char **split, t_cub3d *cub3d)
{
	int		i;
	char	*tmp;

	i = 0;
	while (split[i])
		i++;
	tmp = ft_strtrim(split[1], " ");
	if (i == 2)
	{
		if (tmp[0] == '.' && tmp[1] == '/')
		{
			if (split[0][0] == 'N' && split[0][1] == 'O' && cub3d->parse_direct.north_texture == NULL)
				cub3d->parse_direct.north_texture = ft_strtrim(tmp, "\n");
			else if (split[0][0] == 'S' && split[0][1] == 'O' && cub3d->parse_direct.south_texture == NULL)
				cub3d->parse_direct.south_texture = ft_strtrim(tmp, "\n");
			else if (split[0][0] == 'E' && split[0][1] == 'A' && cub3d->parse_direct.east_texture == NULL)
				cub3d->parse_direct.east_texture = ft_strtrim(tmp, "\n");
			else if (split[0][0] == 'W' && split[0][1] == 'E' && cub3d->parse_direct.west_texture == NULL)
				cub3d->parse_direct.west_texture = ft_strtrim(tmp, "\n");
			else
				return (free(tmp), EXIT_FAILURE);
		}
		else
			return (free(tmp), EXIT_FAILURE);
	}
	return(free(tmp), EXIT_SUCCESS);
}

void	freeing_arr(char **array , char *line)
{
	if (line)
		free(line);
	if (!array)
		return ;
	int i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

int	parse_direction(t_cub3d *cub3d, char *line)
{
	int		i;
	char	**split;

	i = 0;
	line = ft_strtrim(line, " ");
	split = ft_split(line, ' ');
	while (split[i])
		i++;
	if (i == 2)
	{
		if (fill_textures(split, cub3d) == EXIT_FAILURE)
			return (freeing_arr(split, line), EXIT_FAILURE);
		else
			return (freeing_arr(split, line), EXIT_SUCCESS);
	}
	else
	{
		freeing_arr(split, line);
		ft_putendl_fd("\033[0;31m Error Invalid line\033[0m", 2);
		return (free(line), 1);
	}
	return (free(line), 0);
}
