/* ************************************************************************** */
/*                                                                           */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamaarou <hamaarou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 11:49:02 by hamaarou          #+#    #+#             */
/*   Updated: 2023/08/22 17:45:51 by hamaarou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include <unistd.h>
# include <stdio.h>
# include <math.h>
# include <mlx.h>
# include "../../library/libft/libft.h"
# include "../../library/get_next_line/get_next_line.h"

# define TILE_SIZE 64
# define MAP_NUM_ROWS 13
# define MAP_NUM_COLS 20
# define MAP_H 1080
# define MAP_W 1920

//scale_factor
# define SCALE_FACTOR 0.4

// Keys
# define KEY_UP 13
# define KEY_DOWN 1
# define KEY_RIGHT 2
# define KEY_LEFT 0
# define KEY_ESC 53

// view
# define VIEW_RIGHT 124
# define VIEW_LEFT 123

# define FOV_ANGLE (60 * (M_PI / 180))
# define WALL_STRIP_WIDTH 1
//# define NUM_RAYS (MAP_H / WALL_STRIP_WIDTH)

# define NO 4.72
# define SO 1.57
# define WE 3.14
# define EA 0

//* STRUCTS
typedef struct s_parse_direction
{
	char	*north_texture;
	char	*south_texture;
	char	*east_texture;
	char	*west_texture;
}	t_parse_direction;

typedef struct s_rgb
{
	int		r;
	int		g;
	int		b;
}	t_rgb;

typedef struct s_player
{
	float	x;
	float	y;
	float	raduis;
	float	turn_direction;
	float	walk_direction;
	float	rotation_angle;
	float	walk_speed;
	float	turn_speed;
	float	look;
	int		step;
}	t_player;

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

typedef struct s_map
{
	int		x;
	int		y;
}	t_map;

typedef struct s_image
{
	int		width;
	int		height;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
	int		*data;
	char	*addr;
	void	*img;
}	t_image;

typedef struct s_img_data
{
	t_image		img_north;
	t_image		img_south;
	t_image		img_east;
	t_image		img_west;
}	t_img_data;

typedef struct s_cub3d
{
	char				*file_name;
	int					fd;
	char				*map_1d;
	char				**map_2d;
	t_parse_direction	parse_direct;
	t_rgb				floor;
	t_rgb				ceiling;
	t_player			player;
	t_map				map;
}	t_cub3d;

typedef struct s_line
{
	float	x0;
	float	y0;
	float	x1;
	float	y1;
	int		dx;
	int		dy;
	int		steps;
	float	xinc;
	float	yinc;
	float	x;
	float	y;
}	t_line;

typedef struct s_minimap
{
	int		x_pos;
	int		y_pos;
}				t_minimap;

typedef struct s_mlx
{
	int			x_offset;
	void		*mlx_ptr;
	void		*mlx_win;
	int			is_vertical;
	int			is_horizontal;
	double		rayangle;
	double		ray_x;
	double		ray_y;
	int			tex_x;
	int			tex_y;
	double		distance;
	t_image		img;
	t_image		*no_texture;
	t_image		*so_texture;
	t_image		*we_texture;
	t_image		*ea_texture;
	t_img_data	imgs;
	t_data		data;
	t_cub3d		cub3d;
	t_minimap	minimap;
}	t_mlx;

//* FUNCTIONS PROTOTYPE
void			initialize(t_cub3d *cub3d);
int				check_file_extension(char *file_name);

//+ Parsing cardinal Functions +//
int				start_parsing(t_cub3d *cub3d);
int				save_cardinal_directions(t_cub3d *cub3d, char *line);
int				is_cardinal_direction(char *line);
int				ft_matrice_len(char **matrice);
int				save_textures(char **matrice, t_cub3d *cub3d);

//+ Parsing RGB Functions +//
int				save_rgbs(t_cub3d *cub3d, char *line);
//+ Parsing Map Functions +//
int				is_surrounded(t_cub3d *cub3d);
int				check_map(t_cub3d *cub3d);
int				is_map(char *line);
void			rect_map(t_cub3d *cub3d);
size_t			tall_line(char **map);
char			*get_line(char *line, size_t max);
int				check_newline(char *map_1d);

//*player*//
int				has_one_player(t_cub3d *cub3d);
void			get_p_position(t_cub3d *cub3d);

//+config file
int				check_rgb(t_cub3d cube3d);
int				check_texture(t_cub3d cube3d);
int				check_graphics(t_cub3d cub3d);

//+ Cleanup Functions +//
void			clean_rgb(char *rgb, char *tmp);
void			clean_map(char **matrice);
void			cleanup(t_mlx *mlx);

//+Ray Casting Functions +//
void			player_init(t_cub3d *cub3d);
int				key_press(int key, t_mlx *mlx);
int				key_release(int key, t_mlx *mlx);
int				mouse(int x, int y, t_mlx *ml);

void			render(t_mlx *mlx);
void			my_mlx_pixel_put(t_data *data, int x, int y, int color);
int				game(t_mlx *mlx);
int				close_window(t_mlx *mlx);
void			move_down_up(t_mlx *mlx);
void			move_left_right(t_mlx *mlx);
int				check_wall(t_mlx *mlx, float x, float y);
int				is_player(char c);
void			look_left_right(t_mlx *mlx);
void			ray(t_mlx *mlx);
void			cast_ray(double ray_angle, t_mlx *mlx);
void			my_mlx_pixel_put(t_data *data, int x, int y, int color);
// +line
void			render3dwalls(t_mlx *mlx, int nb);
void			textures_init(t_mlx *mlx);
unsigned int	get_color(t_image *tex, int x, int y);
void			my_mlx_pixel_put2(t_image *textures, int x, int y, int color);
void			minimap_render(t_mlx *mlx);
void			getdirection(t_mlx *mlx);
double			get_x(t_mlx *mlx);
void			free_textures(t_mlx *mlx);
int				rgb_to_int(int red, int green, int blue);
#endif
