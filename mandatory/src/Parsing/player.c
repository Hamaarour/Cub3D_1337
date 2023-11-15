/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamaarou <hamaarou@1337.student.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 09:38:46 by hamaarou          #+#    #+#             */
/*   Updated: 2023/11/14 19:37:37 by hamaarou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

float	alpha(char c)
{
	if (c == 'N')
		return (NO);
	else if (c == 'S')
		return (SO);
	else if (c == 'E')
		return (EA);
	else
		return (WE);
}

void	get_p_position(t_cub3d *cub3d)
{
	int	px;
	int	py;

	px = (int)cub3d->player.x;
	py = (int)cub3d->player.y;
	cub3d->player.y = 0;
	while (cub3d->map_2d[py])
	{
		px = 0;
		while (cub3d->map_2d[py][px])
		{
			if (cub3d->map_2d[py][px] == 'S' || cub3d->map_2d[py][px] == 'N'
				|| cub3d->map_2d[py][px] == 'E' || cub3d->map_2d[py][px] == 'W')
			{
				cub3d->player.rotation_angle = alpha(cub3d->map_2d[py][px]);
				cub3d->player.x = (float)(px * TILE_SIZE + 16);
				cub3d->player.y = (float)(py * TILE_SIZE + 16);
				return ;
			}
			px++;
		}
		py++;
	}
}
