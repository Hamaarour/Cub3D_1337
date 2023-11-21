/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamaarou <hamaarou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 00:44:30 by mel-kabb          #+#    #+#             */
/*   Updated: 2023/11/21 16:23:13 by hamaarou         ###   ########.fr       */
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

int	is_rgb_fill(int r, int g, int b)
{
	if (r >= 0 && r <= 255 && g >= 0 && g <= 255 && b >= 0 && b <= 255)
	{
		return (EXIT_SUCCESS);
	}
	return (EXIT_FAILURE);
}

int	check_exit(void)
{
	ft_putendl_fd("\033[0;31m 📛 Error Invalid File 📛 \033[0m", 2);
	exit(EXIT_FAILURE);
}
