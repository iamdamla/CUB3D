/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: derblang <derblang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 12:59:11 by derblang          #+#    #+#             */
/*   Updated: 2024/01/27 14:15:22 by derblang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	draw_map(t_mlx *mlx)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (mlx->cub->map[y])
	{
		while (mlx->cub->map[y][x])
		{
			if (mlx->cub->map[y][x] == '1')
				draw_cell(mlx, x * CELLSIZE, y * CELLSIZE);
			if (mlx->cub->map[y][x] == '0' || mlx->cub->map[y][x] == 'N'
				|| mlx->cub->map[y][x] == 'S' || mlx->cub->map[y][x] == 'E'
				|| mlx->cub->map[y][x] == 'W' || mlx->cub->map[y][x] == ' ')
				draw_cell_bis(mlx, x * CELLSIZE, y * CELLSIZE);
			x++;
		}
		y++;
		x = 0;
	}
}

static void	update_pos_player(t_mlx *mlx)
{
	draw_character(mlx);
	draw_beam(mlx, mlx->player->pixel_coord.x, mlx->player->pixel_coord.y);
	move_forward(mlx);
	move_backward(mlx);
	move_right(mlx);
	move_left(mlx);
}

static void	rotate(t_mlx *mlx)
{
	if (mlx_is_key_down(mlx->id, MLX_KEY_LEFT))
	{
		delete_beam(mlx, mlx->player->pixel_coord.x,
			mlx->player->pixel_coord.y);
		mlx->player->angle -= (10 * M_PI) / 180;
		if (mlx->player->angle > 2 * M_PI)
			mlx->player->angle -= 2 * M_PI;
	}
	if (mlx_is_key_down(mlx->id, MLX_KEY_RIGHT))
	{
		delete_beam(mlx, mlx->player->pixel_coord.x,
			mlx->player->pixel_coord.y);
		mlx->player->angle += (10 * M_PI) / 180;
		if (mlx->player->angle < 0)
			mlx->player->angle += 2 * M_PI;
	}
}

void	event(mlx_key_data_t event, void *content)
{
	t_mlx	*mlx;

	(void)event;
	mlx = content;
	if (mlx_is_key_down(mlx->id, MLX_KEY_ESCAPE))
		mlx_close_window(mlx->id);
}

void	loop(void *param)
{
	t_mlx	*mlx;

	mlx = param;
	draw_map(mlx);
	rotate(mlx);
	update_pos_player(mlx);
	draw_screen(mlx);
}
