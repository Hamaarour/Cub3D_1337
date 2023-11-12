/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamaarou <hamaarou@1337.student.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 11:07:18 by hamaarou          #+#    #+#             */
/*   Updated: 2023/11/12 15:10:47 by hamaarou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d.h"

int	is_valid_rgb(char **rgb)
{
	int		color;
	int		i;
	int		j;

	i = -1;
	if (ft_matrice_len(rgb) != 3)
		return (0);
	while (rgb[++i])
	{
		j = -1;
		while (rgb[i][++j])
		{
			if (!ft_isdigit(rgb[i][j]))
				return (0);
		}
		color = ft_atoi(rgb[i]);
		if (color < 0 || color > 255)
			return (0);
	}
	return (1);
}

void	fill_rgbs(t_cub3d *cub3d, char **rgb, char id)
{
	if (is_valid_rgb(rgb))
	{
		if (id == 'F')
		{
			cub3d->floor.r = ft_atoi(rgb[0]);
			cub3d->floor.g = ft_atoi(rgb[1]);
			cub3d->floor.b = ft_atoi(rgb[2]);
		}
		else
		{
			cub3d->ceiling.r = ft_atoi(rgb[0]);
			cub3d->ceiling.g = ft_atoi(rgb[1]);
			cub3d->ceiling.b = ft_atoi(rgb[2]);
		}
	}
}

int save_rgbs(t_cub3d *cub3d, char *line)
{
	char	**pattern;
	char	**rgb;

	pattern = ft_split(ft_strtrim(line, " "), ' ');
	if (ft_matrice_len(pattern) != 2)
		return (clean_map(pattern), EXIT_FAILURE);
	rgb = ft_split(ft_strtrim(pattern[1], "\n"), ',');
	if (ft_strncmp(pattern[0], "F", 1) == 0)
		fill_rgbs(cub3d, rgb, 'F');
	else if (ft_strncmp(pattern[0], "C", 1) == 0)
		fill_rgbs(cub3d, rgb, 'C');
	else
		return (free(pattern), clean_map(rgb), EXIT_FAILURE);
	return (free(pattern), clean_map(rgb), EXIT_SUCCESS);
}
