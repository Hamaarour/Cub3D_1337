/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamaarou <hamaarou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 18:31:08 by hamaarou          #+#    #+#             */
/*   Updated: 2023/08/27 17:22:40 by hamaarou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	free_all(t_cub3d *cub3d)
{
	free_textures(cub3d);
	if (cub3d->map_2d)
		free_array(cub3d->map_2d);
	free(cub3d->map_1d);
}