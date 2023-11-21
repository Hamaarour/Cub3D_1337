/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rect_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamaarou <hamaarou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 14:45:38 by hamaarou          #+#    #+#             */
/*   Updated: 2023/11/19 12:33:52 by hamaarou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	is_map(char *line)
{
	int	i;

	i = -1;
	while (line[++i])
		if ((line[i] == '1' || line[i] == '0'))
			return (EXIT_SUCCESS);
	return (EXIT_FAILURE);
}

size_t	tall_line(char **map)
{
	size_t	i;
	size_t	j;
	size_t	max;

	i = -1;
	max = 0;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
			if (max < ft_strlen(map[i]))
				max = ft_strlen(map[i]);
	}
	return (max);
}

char	*get_line(char *line, size_t max)
{
	char	*new_line;
	size_t	i;

	new_line = ft_calloc_char(1, (max + 1), '$');
	i = 0;
	while (i < max)
	{
		if (ft_strlen(line) > i
			&& (line[i] == '1' || line[i] == '0' || line[i] == 'E'
				|| line[i] == 'W' || line[i] == 'N' || line[i] == 'S' ))
			new_line[i] = line[i];
		i++;
	}
	new_line[i] = '\0';
	return (new_line);
}

void	rect_map(t_cub3d *cub3d)
{
	int		i;
	char	*tmp;
	char	*row;
	size_t	max;

	i = -1;
	max = tall_line(cub3d->map_2d);
	while (cub3d->map_2d[++i])
	{
		tmp = ft_strdup(cub3d->map_2d[i]);
		row = get_line(tmp, max);
		free(cub3d->map_2d[i]);
		cub3d->map_2d[i] = row;
		free(tmp);
	}
}
