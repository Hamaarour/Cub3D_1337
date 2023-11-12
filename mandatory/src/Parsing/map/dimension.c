/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dimension.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaztaou <bkaztaou@1337.student.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 09:47:45 by hamaarou          #+#    #+#             */
/*   Updated: 2023/11/07 02:43:27 by bkaztaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d.h"

void    map_dimension(t_cub3d *cub3d)
{
    while (cub3d->map_2d[cub3d->map.y])
        cub3d->map.y++;
    while (cub3d->map_2d[0][cub3d->map.x])
        cub3d->map.x++;
}
