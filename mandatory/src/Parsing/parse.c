/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamaarou <hamaarou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 16:51:52 by hamaarou          #+#    #+#             */
/*   Updated: 2023/11/12 22:27:24 by hamaarou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int is_invalid_line(char *line)
{
	if (line[0] == '\n' && line[0] == '\0'
		&& line[0] == '\t' && line[0] == ' ')
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int handle_map(t_cub3d *cub3d, char *line)
{
	int	status;

	status = EXIT_SUCCESS;
	if (check_graphics(*cub3d) == EXIT_SUCCESS
		&& is_invalid_line(line) == EXIT_SUCCESS)
	{
		while (line)
		{
			cub3d->map_1d = ft_strjoin(cub3d->map_1d, line);
			free(line);
			line = get_next_line(cub3d->fd);
		}
		if (map_check(cub3d) || check_newline(cub3d->map_1d))
			status = EXIT_FAILURE;
	}
	return status;
}

int start_parsing(t_cub3d *cub3d)
{
	char	*line;
	int		status;

	cub3d->map_1d = NULL;
	cub3d->map_2d = NULL;
	status = EXIT_SUCCESS;
	while ((line = get_next_line(cub3d->fd)))
	{
		if (line[0] == '\n')
		{
			free(line);
			continue;
		}
		if (is_cardinal_direction(line))
			status = save_cardinal_directions(cub3d, line);
		else if (line[0] == 'F' || line[0] == 'C')
			status = save_rgbs(cub3d, line);
		else if (is_map(line))
			status = handle_map(cub3d, line);
		else
			status = EXIT_FAILURE;
		free(line);
		if (status == EXIT_FAILURE)
			break;
	}
	return status;
}
