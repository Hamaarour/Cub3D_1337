#include "../../includes/cub3d.h"



t_image	*new_img(t_mlx *mlx, char *path)
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
	if (!img->img)
		printf("invalid texture path");
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel,
			&img->size_line, &img->endian);
	return (img);
}

void textures_init(t_mlx *mlx)
{
	printf("NO : '%s'\n", mlx->cub3d.parse_direct.north_texture);
	mlx->no_texture = new_img(mlx, mlx->cub3d.parse_direct.north_texture);
	mlx->so_texture = new_img(mlx, mlx->cub3d.parse_direct.south_texture);
	mlx->we_texture = new_img(mlx, mlx->cub3d.parse_direct.west_texture);
	mlx->ea_texture = new_img(mlx, mlx->cub3d.parse_direct.east_texture);
	printf("NO : '%s'\n", mlx->cub3d.parse_direct.north_texture);	
}
