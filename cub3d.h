/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: derblang <derblang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 10:47:47 by derblang          #+#    #+#             */
/*   Updated: 2024/01/27 11:54:38 by derblang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "./MLX42/include/MLX42/MLX42.h"
# include "libft/libft.h"
# include <math.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define WIDTH 3000
# define HEIGHT 1800
# define M_PI 3.14159265358979323846
# define CELLSIZE 32
# define FOV 60
# define RAYON 5000

typedef struct s_moveset
{
	int				distance;
	int				delta_x;
	int				delta_y;
	int				new_x;
	int				new_y;
}					t_moveset;

typedef struct s_rgb
{
	int				red;
	int				green;
	int				blue;
}					t_rgb;

typedef struct s_cub
{
	char			**map;
	char			**map_cpy;
	char			*floor_color;
	char			*ceilling_color;
	int				horizontale;
	int				verticale;
	int				floor[3];
	int				ceilling[3];
	char			*path_north;
	char			*path_south;
	char			*path_east;
	char			*path_west;
	mlx_texture_t	*north_tex;
	mlx_texture_t	*south_tex;
	mlx_texture_t	*east_tex;
	mlx_texture_t	*west_tex;
}					t_cub;

typedef struct s_point
{
	int				x;
	int				y;
}					t_point;

typedef struct s_orient
{
	int				x;
	int				y;
	char			orient;
}					t_orient;

typedef struct s_player
{
	double			angle;
	t_point			position;
	t_point			pixel_coord;
}					t_player;

typedef struct s_ray
{
	int				x1;
	int				y1;
	int				x2;
	int				y2;
	int				dx;
	int				dy;
	int				dir_x;
	int				dir_y;
	int				dist_ray;
	int				err;
}					t_ray;

typedef struct s_mlx
{
	mlx_t			*id;
	mlx_image_t		*img;
	mlx_image_t		*img_ray;
	mlx_image_t		*screen;
	t_player		*player;
	t_cub			*cub;
	t_ray			raycast;
	double			*tab;
	t_orient		wall_coord;
	t_orient		*tab_wall;
	double			wall_height;
}					t_mlx;

// init
void				init(t_cub *cub, t_player *player, t_mlx *mlx);

// map
char				**read_map(char *file);
void				find_pos(char **map, t_player *player);
void				check_all_map(char *file, t_cub *cub);

// flood fill

void				flood_fill(char **map, int horizontale, int verticale);

// check
void				check_args(char argc);
int					ft_open_fd(char *filename);
void				check_file_extension(char *file);

// check_map_utils
void				texture_check(char *line, int *count);
char				**get_map_description(char **map);

// check_map
int					invalid_char_check(char **map);
int					check_map_components(char **map);

// wall
int					check_around(char **map, int i, size_t j);
void				check_wall(char **map);

// wall_bis
int					check_closed_around_space(char **map);

// color
void				check_color_arr(char **arr);
void				convert_rgb(char *line, t_cub *cub, char c);
void				get_color(char *line, t_cub *cub);

// mlx
void				draw_cell_bis(t_mlx *mlx, int x, int y);
void				draw_character(t_mlx *mlx);
// void delete_character(t_mlx *mlx);
void				draw_cell(t_mlx *mlx, int x, int y);
void				open_window(t_mlx *mlx);

// event
void				event(mlx_key_data_t keycode, void *content);
void				loop(void *param);

// utils
void				print_arr(char **arr);
int					ft_arrlen(char **map);
void				free_arr(char **map);
int					count_line(char **map);
int					absolute(int nb);

// texture
void				check_map_texture(char **map, t_cub *cub);
void				check_map_color(char **map, t_cub *cub);

// utils2
char				**map_cpy(char **map, int verticale);
char				**ft_arrdup(char **arr);
int					find_bigger_nb(int nb1, int nb2);

// ray
void				delete_beam(t_mlx *mlx, int x1, int y1);
void				draw_beam(t_mlx *mlx, int x1, int y1);

// ray_bis

int					is_wall(t_mlx *mlx, int x, int y);
void				find_orientation(t_mlx *mlx, int x, int y);

// moveset
void				move_left(t_mlx *mlx);
void				move_forward(t_mlx *mlx);
void				move_backward(t_mlx *mlx);
void				move_right(t_mlx *mlx);

// screen
void				draw_screen(t_mlx *mlx);

// display_texture
t_rgb				find_color_texture_north(t_mlx *mlx, mlx_texture_t *texture,
						int x_wall, int y_wall);
t_rgb				find_color_texture_east(t_mlx *mlx, mlx_texture_t *texture,
						int x_wall, int y_wall);
void				find_color_texture(t_mlx *mlx, int x_wall, int y_wall);
t_rgb				init_color(void);
t_rgb				find_k(t_mlx *mlx, int x_wall, int y_wall, t_rgb color);

// load texture
void				load_img(t_cub *cub);
int					rgb_to_hex(int r, int g, int b, int a);
size_t	get_longest_line(char **map);

#endif