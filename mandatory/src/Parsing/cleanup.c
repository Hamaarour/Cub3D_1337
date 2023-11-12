/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamaarou <hamaarou@1337.student.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 18:31:08 by hamaarou          #+#    #+#             */
/*   Updated: 2023/11/08 20:03:15 by hamaarou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void clean_textures(t_cub3d *cub3d)
{
	if (cub3d->parse_direct.north_texture)
		free(cub3d->parse_direct.north_texture);
	if (cub3d->parse_direct.south_texture)
		free(cub3d->parse_direct.south_texture);
	if (cub3d->parse_direct.east_texture)
		free(cub3d->parse_direct.east_texture);
	if (cub3d->parse_direct.west_texture)
		free(cub3d->parse_direct.west_texture);
}

void clean_map(char **matrice)
{
	int i;

	i = 0;
	if (!matrice)
		return;
	while (matrice[i])
	{
		free(matrice[i]);
		i++;
	}
	free(matrice);
}

void clean_rgb(char *rgb, char *tmp)
{
	if (rgb)
		free(rgb);
	if (tmp)
		free(tmp);
}

void cleanup(t_cub3d *cub3d)
{
	clean_textures(cub3d);
	clean_map(cub3d->map_2d);
	free(cub3d->map_1d);
}
