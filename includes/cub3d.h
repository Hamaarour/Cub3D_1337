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
#define CUB3D_H
#include <unistd.h>
#include <stdio.h>
#include <math.h>
#include <mlx.h>
#include "../Library/Libft/libft.h"
#include "../Library/Get_next_line/get_next_line.h"

#define TILE_SIZE 64
#define MAP_NUM_ROWS 13
#define MAP_NUM_COLS 20
#define MAP_H 1080
#define MAP_W 1920

//scale_factor
#define SCALE_FACTOR 0.4

// Keys
#define KEY_UP 13	  // 13 //119
#define KEY_DOWN 1    // 1 //115
#define KEY_RIGHT 2 // 2 //100
#define KEY_LEFT 0	  // 0 //97
#define KEY_ESC 53 // 53 //65307

// view
#define VIEW_RIGHT 124 // 124 //65363
#define VIEW_LEFT 123	 // 123 //65361

#define FOV_ANGLE 60 * (M_PI / 180)
#define WALL_STRIP_WIDTH 1
#define NUM_RAYS (MAP_H / WALL_STRIP_WIDTH)

#define NO 4.72 // N
#define SO 1.57 // S
#define WE 3.14 // W
#define EA 0 // E

typedef struct s_parse_direction
{
	char *north_texture;
	char *south_texture;
	char *east_texture;
	char *west_texture;
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
} t_player;

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
	void	*ptr;
	int		*data;
}	t_image;

typedef struct s_img_data
{
	t_image		g_north;
	t_image		g_south;
	t_image		g_east;
	t_image		g_west;
}	t_img_data;

typedef struct s_cub3d
{
	char				*file_name;
	int					fd;
	char				*map_1d;
	char				**map_2d;
	int					map_height;
	int					map_width;
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

typedef struct s_mlx
{
	void		*mlx_ptr;
	void		*mlx_win;
	int			isVertical;
	int 		isHorizontal;
	double		rayangle;
	double		ray_x;
	double		ray_y;
	double		arr_rays[NUM_RAYS];
	double		distance;
	t_img_data	imgs;
	t_data		data;
	t_cub3d		cub3d;
}	t_mlx;

//! Parsing cardinal Functions +!//

//+initilization structure Functions +//
void	init_textures(t_cub3d *cub3d);
void	init_rgb(t_cub3d *cub3d);
void	init_map(t_cub3d *cub3d);
void	init_player(t_cub3d *cub3d);
void	init_all(t_cub3d *cub3d);

//+ Parsing cardinal Functions +//
int		start_parsing(t_cub3d *cub3d);
int		parse_direction(t_cub3d *cub3d, char *line);
void	free_array(char **array);
int		cardinal_direction(char *line);
int		fill_textures(char **split, t_cub3d *cub3d);
int		check_textures(t_cub3d *cub3d);

//+ Parsing RGB Functions +//
int		comma_check(char *line);
int		parse_floor_color(t_cub3d *cub3d, char *line, char type);
int		result_length(char *line);
int		check_isdigit(char *line);
int		check_rang_rgb(t_cub3d *cub3d, int r, int g, int b, char type);
char	*cut_rgb(char *rgb);
char	*get_rgb(char *line);
int		rgb(t_cub3d cub3d);
int		rgb_is_set(t_cub3d *cub3d);

//+ Parsing Map Functions +//
int		textures_is_fill(t_cub3d *cub3d);
int		floor_ceiling_is_color(t_cub3d *cub3d);
int		is_map_last(t_cub3d *cub3d);
void	map_height(t_cub3d *cub3d);
void	map_width(t_cub3d *cub3d);
int		first_last_lines(char *line);
int		first_last_column(char *line);
int		is_surrounded(t_cub3d *cub3d);
int		map_check(t_cub3d *cub3d);
int		is_map(char *line);
char	**to_rectangle(char **map, size_t line_length);
size_t	tall_line(char **map);
char	*get_line(char *line, size_t max);
int		check_newline(char *map_1d);
void	map_dimension(t_cub3d *cub3d);

//*player*//
int		num_of_player(t_cub3d *cub3d);
void	get_p_position(t_cub3d *cub3d);

//+config file
int		config_file_is_set(t_cub3d cub3d);

//+Free Functions +//
void	free_array(char **array);
void	free_textures(t_cub3d *cub3d);
void	free_rgb(char *rgb, char *tmp);
void	free_all(t_cub3d *cub3d);

//+Ray Casting Functions +//

void	player_init(t_cub3d *cub3d);
int		key_press(int key, t_mlx *mlx);
int		key_release(int key, t_mlx *mlx);

void	render(t_mlx *mlx, t_cub3d cub3d);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
int		game(t_mlx *mlx);
int		close_window(t_mlx *mlx);
void	move_down_up(t_mlx *mlx);
int		check_wall(t_mlx *mlx, float x, float y);
int		is_player(char c);
void	look_left_right(t_mlx *mlx);
void	ray(t_mlx *mlx, int color);
void	cast_ray(double ray_angle, t_mlx *mlx, int color);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
// +line
void	render3dwalls(t_mlx *mlx, int nb);

#endif
