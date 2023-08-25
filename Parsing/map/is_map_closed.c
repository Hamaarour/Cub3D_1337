/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_map_closed.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamaarou <hamaarou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 13:08:06 by hamaarou          #+#    #+#             */
/*   Updated: 2023/08/25 17:53:31 by hamaarou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int is_surrounded(t_cub3d *cub3d)
{
	int	i;

	i = 0;
	map_height(cub3d);
	while(cub3d->map_2d[i])
	{
		if(!first_last_lines(cub3d->map_2d[0])
			|| !first_last_lines(cub3d->map_2d[cub3d->map_height - 1])
			|| !first_last_column(cub3d->map_2d[i]))
				return (1);
		i++;
	}
	return (0);
}