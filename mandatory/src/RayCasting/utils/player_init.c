/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-kabb <mel-kabb@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 22:17:41 by mel-kabb          #+#    #+#             */
/*   Updated: 2023/11/14 22:17:47 by mel-kabb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d.h"

void	player_init(t_cub3d *cub3d)
{
	cub3d->player.raduis = 0;
	cub3d->player.turn_direction = 0;
	cub3d->player.walk_direction = 0;
	cub3d->player.walk_speed = 15.0;
	cub3d->player.turn_speed = 7.0 * (M_PI / 180);
	cub3d->player.step = 0;
	cub3d->player.look = 0;
}
