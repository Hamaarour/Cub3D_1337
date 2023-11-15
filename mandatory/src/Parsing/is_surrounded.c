/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_surrounded.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamaarou <hamaarou@1337.student.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 13:08:06 by hamaarou          #+#    #+#             */
/*   Updated: 2023/11/15 02:15:24 by hamaarou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	is_valid_row(char *row)
{
	int		i;
	char	*tmp;

	tmp = ft_strtrim(row, "\t\v\f\r\n ");
	i = -1;
	while (tmp[++i])
	{
		if (tmp[i] != '1' && tmp[i] != ' ')
			return (free(tmp), EXIT_FAILURE);
	}
	free(tmp);
	return (EXIT_SUCCESS);
}

int	is_valid_column(char **col)
{
	int		i;
	char	*tmp;

	i = -1;
	while (col[++i])
	{
		tmp = ft_strtrim(col[i], "\t\v\f\r\n ");
		if (tmp[0] != '1' || tmp[ft_strlen(tmp) - 1] != '1')
			return (free(tmp), EXIT_FAILURE);
		free(tmp);
	}
	return (EXIT_SUCCESS);
}

int	is_surrounded(t_cub3d *cub3d)
{
	int		status;

	status = EXIT_SUCCESS;
	if (is_valid_row(cub3d->map_2d[0]) == EXIT_FAILURE
		|| is_valid_row(cub3d->map_2d[cub3d->map.y - 1]) == EXIT_FAILURE
		|| is_valid_column(cub3d->map_2d) == EXIT_FAILURE)
		status = EXIT_FAILURE;
	return (status);
}
