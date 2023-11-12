/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb_is_set.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaztaou <bkaztaou@1337.student.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 21:41:07 by hamaarou          #+#    #+#             */
/*   Updated: 2023/11/07 02:43:27 by bkaztaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d.h"

int rgb_is_set(t_cub3d *cub3d)
{
    if (cub3d->floor.r != -1 || cub3d->floor.g != -1 || cub3d->floor.b != -1)
        return (EXIT_SUCCESS);
    if (cub3d->ceiling.r != -1 || cub3d->ceiling.g != -1 || cub3d->ceiling.b != -1)
        return (EXIT_SUCCESS);
    return (EXIT_FAILURE);
}
