/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgbs.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamaarou <hamaarou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 11:07:18 by hamaarou          #+#    #+#             */
/*   Updated: 2023/11/21 16:45:50 by hamaarou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	is_valid_rgb(char **rgb)
{
	char	*tmp;
	int		color;
	int		i;
	int		j;

	i = -1;
	if (ft_matrice_len(rgb) != 3)
		return (EXIT_FAILURE);
	while (rgb[++i])
	{
		j = -1;
		tmp = ft_strtrim(rgb[i], " ");
		while (tmp[++j])
			if (!ft_isdigit(tmp[j]) && tmp[j] != '\n')
				return (free(tmp), EXIT_FAILURE);
		color = ft_atoi(tmp);
		if (color < 0 || color > 255)
			return (free(tmp), EXIT_FAILURE);
		free(tmp);
	}
	return (EXIT_SUCCESS);
}

int	convert(char *color)
{
	char	*tmp;
	int		val;

	if (!color)
		check_exit();
	tmp = ft_strtrim(color, " ");
	if (tmp[0] == '\0')
	{
		free(tmp);
		check_exit();
	}
	val = ft_atoi(tmp);
	free(tmp);
	return (val);
}

void	fill_rgbs(t_cub3d *cub3d, char **rgb, char id)
{
	if (is_valid_rgb(rgb) == EXIT_SUCCESS)
	{
		if (id == 'F')
		{
			if (cub3d->floor.r != -1 || cub3d->floor.g != -1
				|| cub3d->floor.b != -1)
				check_exit();
			cub3d->floor.r = convert(rgb[0]);
			cub3d->floor.g = convert(rgb[1]);
			cub3d->floor.b = convert(rgb[2]);
		}
		else
		{
			if (cub3d->ceiling.r != -1 || cub3d->ceiling.g != -1
				|| cub3d->ceiling.b != -1)
				check_exit();
			cub3d->ceiling.r = convert(rgb[0]);
			cub3d->ceiling.g = convert(rgb[1]);
			cub3d->ceiling.b = convert(rgb[2]);
		}
	}
}

int	check_comma(char *line)
{
	int	i;
	int	comma;

	i = 0;
	comma = 0;
	while (line[i])
	{
		if (line[i] == ',')
			comma++;
		i++;
	}
	if (comma != 2)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	save_rgbs(t_cub3d *cub3d, char *line)
{
	int		i;
	char	**rgb;
	char	*tmp;

	i = 1;
	while (line[i] == ' ')
		i++;
	tmp = ft_strtrim(&line[i], " ");
	if (check_comma(tmp) == EXIT_FAILURE)
		return (free(tmp), EXIT_FAILURE);
	rgb = ft_split(tmp, ',');
	if (line[0] == 'F')
		fill_rgbs(cub3d, rgb, 'F');
	else if (line[0] == 'C')
		fill_rgbs(cub3d, rgb, 'C');
	else
		return (clean_map(rgb), free(tmp), EXIT_FAILURE);
	return (clean_map(rgb), free(tmp), EXIT_SUCCESS);
}
