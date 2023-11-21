/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-kabb <mel-kabb@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 16:51:52 by hamaarou          #+#    #+#             */
/*   Updated: 2023/11/21 15:12:17 by mel-kabb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	is_invalid_element(char *line)
{
	if (line[0] == '\n' && line[0] == '\0'
		&& line[0] == '\t')
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	save_map_matrice(t_cub3d *cub3d, char *line)
{
	char	*copy;
	char	*tmp;

	copy = ft_strdup(line);
	if (is_invalid_element(line) == EXIT_SUCCESS)
	{
		while (copy)
		{
			tmp = ft_strjoin(cub3d->map_1d, copy);
			cub3d->map_1d = tmp;
			free(copy);
			copy = get_next_line(cub3d->fd);
		}
		if (check_map(cub3d) || check_newline(cub3d->map_1d))
			return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

int	parse_elements(t_cub3d *cub3d, char *line)
{
	int	status;

	status = EXIT_FAILURE;
	if (!is_cardinal_direction(line))
	{
		status = save_cardinal_directions(cub3d, line);
		if (status == EXIT_FAILURE)
			return (EXIT_FAILURE);
	}
	else if (line[0] == 'F' || line[0] == 'C')
	{
		status = save_rgbs(cub3d, line);
		if (status == EXIT_FAILURE)
			return (EXIT_FAILURE);
	}
	else if (!is_map(line) && !check_graphics(*cub3d))
		status = save_map_matrice(cub3d, line);
	return (status);
}

int	start_parsing(t_cub3d *cub3d)
{
	char	*line;
	int		status;

	status = EXIT_FAILURE;
	while (1)
	{
		line = get_next_line(cub3d->fd);
		if (!line)
			break ;
		if (line[0] == '\n')
		{
			free(line);
			continue ;
		}
		if (parse_elements(cub3d, line) == EXIT_SUCCESS)
			status = EXIT_SUCCESS;
		else
			status = EXIT_FAILURE;
		free(line);
	}
	return (status);
}
