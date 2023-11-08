#include "../../includes/cub3d.h"

int	check_texture(t_mlx *mlx, void *ptr)
{
	if ((char *)ptr == NULL)
	{
		ft_putendl_fd("\033[0;31m 📛 Error Invalid Textures \033[0m", 2);
		free_all(&mlx->cub3d);
		exit(EXIT_FAILURE);
	}
	exit(EXIT_SUCCESS);
}
t_image	*new_texture(t_mlx *mlx, char *path)
{
	t_image	*img;

	img = (t_image *)malloc(sizeof(t_image));
	if (!img)
	{
		printf("Error\nmalloc failed\n");
		exit(1);
	}
	img->img = mlx_xpm_file_to_image(mlx->mlx_ptr, path,
			&img->width, &img->height);
	check_texture(mlx, img->img);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel,
			&img->size_line, &img->endian);
	check_texture(mlx, img->addr);
	return (img);
}

void textures_init(t_mlx *mlx)
{
	mlx->no_texture = new_texture(mlx, mlx->cub3d.parse_direct.north_texture);
	mlx->so_texture = new_texture(mlx, mlx->cub3d.parse_direct.south_texture);
	mlx->we_texture = new_texture(mlx, mlx->cub3d.parse_direct.west_texture);
	mlx->ea_texture = new_texture(mlx, mlx->cub3d.parse_direct.east_texture);

}
