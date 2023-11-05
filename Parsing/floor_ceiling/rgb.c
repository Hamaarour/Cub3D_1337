/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamaarou <hamaarou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 20:42:05 by hamaarou          #+#    #+#             */
/*   Updated: 2023/11/04 17:57:45 by hamaarou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	rgb(t_cub3d cub3d)
{
	if (cub3d.ceiling.r == -1 && cub3d.ceiling.g == -1 && cub3d.ceiling.b == -1 &&
		cub3d.floor.r == -1 && cub3d.floor.g == -1 && cub3d.floor.b == -1)
		return (0);
	return (1);
}
