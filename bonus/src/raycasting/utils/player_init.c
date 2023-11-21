/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamaarou <hamaarou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 22:17:41 by mel-kabb          #+#    #+#             */
/*   Updated: 2023/11/19 19:12:21 by hamaarou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d.h"

void	player_init(t_cub3d *cub3d)
{
	cub3d->player.raduis = 0;
	cub3d->player.turn_direction = 0;
	cub3d->player.walk_direction = 0;
	cub3d->player.walk_speed = 10.0;
	cub3d->player.turn_speed = 4.0 * (M_PI / 180);
	cub3d->player.step = 0;
	cub3d->player.look = 0;
}
