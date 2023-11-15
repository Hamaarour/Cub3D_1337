/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamaarou <hamaarou@1337.student.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 12:44:34 by hamaarou          #+#    #+#             */
/*   Updated: 2023/11/15 04:10:55 by hamaarou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	check_newline(char *map_1d)
{
	int	i;

	i = -1;
	while (map_1d[++i])
		if (map_1d[i] == '\n' && map_1d[i + 1] == '\n')
			return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	has_map_conflicts(char **map)
{
	int	i;
	int	j;

	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == '0')
			{
				if ((map[i - 1][j] && map[i - 1][j] == '$')
					|| (map[i][j - 1] && map[i][j - 1] == '$')
					|| (map[i][j + 1] && map[i][j + 1] == '$')
					|| (map[i + 1][j] && map[i + 1][j] == '$'))
					return (EXIT_FAILURE);
			}
		}
	}
	return (EXIT_SUCCESS);
}

int	has_one_player(t_cub3d *cub3d)
{
	int	i;
	int	count;

	i = -1;
	count = 0;
	while (cub3d->map_2d[++i])
	{
		if (ft_strchr(cub3d->map_2d[i], 'N') || ft_strchr(cub3d->map_2d[i], 'S')
			|| ft_strchr(cub3d->map_2d[i], 'E')
			|| ft_strchr(cub3d->map_2d[i], 'W'))
			count++;
	}
	if (count != 1)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	check_map(t_cub3d *cub3d)
{
	cub3d->map_2d = ft_split(cub3d->map_1d, '\n');
	cub3d->map.x = ft_strlen(cub3d->map_2d[0]);
	cub3d->map.y = ft_matrice_len(cub3d->map_2d);
	if (is_surrounded(cub3d) || has_one_player(cub3d))
		return (EXIT_FAILURE);
	rect_map(cub3d);
	if (has_map_conflicts(cub3d->map_2d))
		return (EXIT_FAILURE);
	else
		get_p_position(cub3d);
	return (EXIT_SUCCESS);
}
