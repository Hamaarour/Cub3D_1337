/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamaarou <hamaarou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 17:38:16 by hamaarou          #+#    #+#             */
/*   Updated: 2023/11/15 17:38:23 by hamaarou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "../../includes/cub3d.h"

int	ft_matrice_len(char **matrice)
{
	int	i;

	i = 0;
	while (matrice[i])
		i++;
	return (i);
}

int	check_file_extension(char *file_name)
{
	char	**file;
	int		len;

	file = ft_split(file_name, '.');
	len = ft_matrice_len(file);
	if (ft_strncmp(file[len - 1], "cub", 3) != 0)
		return (clean_map(file), EXIT_FAILURE);
	return (clean_map(file), EXIT_SUCCESS);
}
