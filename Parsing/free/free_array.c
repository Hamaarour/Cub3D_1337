/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_array.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamaarou <hamaarou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 17:21:01 by hamaarou          #+#    #+#             */
/*   Updated: 2023/11/04 17:58:19 by hamaarou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

//free double pointer
void	free_array(char **array)
{
	int	i;

	i = 0;
	if (!array)
		return;
	while (array[i]) {
		free(array[i]);
		i++;
	}
	free(array);
}
