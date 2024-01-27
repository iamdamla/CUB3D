/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: derblang <derblang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 10:58:01 by derblang          #+#    #+#             */
/*   Updated: 2024/01/27 11:56:13 by derblang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"


void	draw_screen(t_mlx *mlx)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	while (x < WIDTH)
	{
		mlx->wall_height = (HEIGHT * CELLSIZE) / (mlx->tab[x]);
		while (y < HEIGHT)
		{
			if (y < (HEIGHT / 2) + (mlx->wall_height / 2))
				mlx_put_pixel(mlx->screen, x, y,
					rgb_to_hex(mlx->cub->ceilling[0], mlx->cub->ceilling[1],
						mlx->cub->ceilling[2], 255));
			if (y > (HEIGHT / 2) - (mlx->wall_height / 2))
				mlx_put_pixel(mlx->screen, x, y, rgb_to_hex(mlx->cub->floor[0],
						mlx->cub->floor[1], mlx->cub->floor[2], 255));
			if (y > (HEIGHT / 2) - (mlx->wall_height / 2) && y < (HEIGHT / 2)
				+ (mlx->wall_height / 2))
				find_color_texture(mlx, x, y);
			y++;
		}
		x++;
		y = 0;
	}
}

