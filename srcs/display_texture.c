/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_texture.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: derblang <derblang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 16:11:58 by acaplat           #+#    #+#             */
/*   Updated: 2024/01/27 14:16:44 by derblang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

t_rgb	init_color(void)
{
	t_rgb	color;

	color.red = 0;
	color.green = 0;
	color.blue = 0;
	return (color);
}

t_rgb	find_color_texture_north(t_mlx *mlx, mlx_texture_t *texture, int x_wall,
		int y_wall)
{
	int		index;
	int		pix_coord_x;
	int		pix_coord_y;
	t_rgb	color;

	y_wall = (y_wall - ((HEIGHT / 2) - (mlx->wall_height / 2)));
	pix_coord_x = (((mlx->tab_wall[x_wall].x % CELLSIZE)) * texture->width)
		/ CELLSIZE;
	pix_coord_y = (texture->height / mlx->wall_height) * (y_wall);
	index = (pix_coord_y * texture->width + pix_coord_x)
		* texture->bytes_per_pixel;
	color.red = texture->pixels[index];
	color.green = texture->pixels[index + 1];
	color.blue = texture->pixels[index + 2];
	return (color);
}

t_rgb	find_color_texture_east(t_mlx *mlx, mlx_texture_t *texture, int x_wall,
		int y_wall)
{
	int		index;
	int		pix_coord_x;
	int		pix_coord_y;
	t_rgb	color;

	y_wall = (y_wall - ((HEIGHT / 2) - (mlx->wall_height / 2)));
	pix_coord_x = (((mlx->tab_wall[x_wall].y % CELLSIZE)) * texture->width)
		/ CELLSIZE;
	pix_coord_y = (texture->height / mlx->wall_height) * (y_wall);
	index = (pix_coord_y * texture->width + pix_coord_x)
		* texture->bytes_per_pixel;
	color.red = texture->pixels[index];
	color.green = texture->pixels[index + 1];
	color.blue = texture->pixels[index + 2];
	return (color);
}

void	find_color_texture(t_mlx *mlx, int x_wall, int y_wall)
{
	t_rgb	color;

	color = init_color();
	if ((mlx->tab_wall[x_wall].orient == 'n'))
		color = find_color_texture_north(mlx, mlx->cub->north_tex, x_wall,
				y_wall);
	if (mlx->tab_wall[x_wall].orient == 'e')
		color = find_color_texture_east(mlx, mlx->cub->east_tex, x_wall,
				y_wall);
	if ((mlx->tab_wall[x_wall].orient == 's'))
		color = find_color_texture_north(mlx, mlx->cub->south_tex, x_wall,
				y_wall);
	if (mlx->tab_wall[x_wall].orient == 'w')
		color = find_color_texture_east(mlx, mlx->cub->west_tex, x_wall,
				y_wall);
	mlx_put_pixel(mlx->screen, x_wall, y_wall, rgb_to_hex(color.red,
			color.green, color.blue, 255));
}
