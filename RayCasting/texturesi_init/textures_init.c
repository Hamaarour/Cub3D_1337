#include "../../includes/cub3d.h"

void    textures_data(t_mlx *mlx)
{
	mlx->imgs.img_north.ptr= mlx_xpm_file_to_image(mlx->mlx_ptr, mlx->cub3d.parse_direct.north_texture,
			&mlx->imgs.img_north.width, &mlx->imgs.img_north.height);
	mlx->imgs.img_south.ptr = mlx_xpm_file_to_image(mlx->mlx_ptr, mlx->cub3d.parse_direct.south_texture,
			&mlx->imgs.img_south.width, &mlx->imgs.img_south.height);
	mlx->imgs.img_east.ptr = mlx_xpm_file_to_image(mlx->mlx_ptr, mlx->cub3d.parse_direct.east_texture,
			&mlx->imgs.img_east.width, &mlx->imgs.img_east.height);
	mlx->imgs.img_west.ptr = mlx_xpm_file_to_image(mlx->mlx_ptr, mlx->cub3d.parse_direct.west_texture,
			&mlx->imgs.img_west.width, &mlx->imgs.img_west.height);
}

void textures_init(t_mlx *mlx)
{
	textures_data(mlx);
	if(!mlx->imgs.img_north.ptr || !mlx->imgs.img_south.ptr || !mlx->imgs.img_east.ptr || !mlx->imgs.img_west.ptr)
	{
		ft_putendl_fd("\033[0;31m 📛Error Invalid Texture📛 \033[0m", 2);
		free_all(&mlx->cub3d);
		exit(1);
	}
	mlx->imgs.img_north.data = (int *)mlx_get_data_addr(mlx->imgs.img_north.ptr,
			&mlx->imgs.img_north.bits_per_pixel, &mlx->imgs.img_north.size_line, &mlx->imgs.img_north.endian);
	mlx->imgs.img_south.data = (int *)mlx_get_data_addr(mlx->imgs.img_south.ptr,
			&mlx->imgs.img_south.bits_per_pixel, &mlx->imgs.img_south.size_line, &mlx->imgs.img_south.endian);
	mlx->imgs.img_east.data = (int *)mlx_get_data_addr(mlx->imgs.img_east.ptr,
			&mlx->imgs.img_east.bits_per_pixel, &mlx->imgs.img_east.size_line, &mlx->imgs.img_east.endian);
	mlx->imgs.img_west.data = (int *)mlx_get_data_addr(mlx->imgs.img_west.ptr,
			&mlx->imgs.img_west.bits_per_pixel, &mlx->imgs.img_west.size_line, &mlx->imgs.img_west.endian);
}
