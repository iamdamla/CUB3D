/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moveset.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: derblang <derblang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 10:57:04 by derblang          #+#    #+#             */
/*   Updated: 2024/01/27 11:46:21 by derblang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	move_forward(t_mlx *mlx)
{
	t_moveset	moveset;

	if (mlx_is_key_down(mlx->id, MLX_KEY_W))
	{
		moveset.distance = CELLSIZE / 3;
		moveset.delta_x = moveset.distance * cos(mlx->player->angle);
		moveset.delta_y = moveset.distance * sin(mlx->player->angle);
		moveset.new_x = mlx->player->pixel_coord.x + moveset.delta_x;
		moveset.new_y = mlx->player->pixel_coord.y + moveset.delta_y;
		if (!is_wall(mlx, moveset.new_x, moveset.new_y))
		{
			delete_beam(mlx, mlx->player->pixel_coord.x,
				mlx->player->pixel_coord.y);
			mlx->player->pixel_coord.x = moveset.new_x;
			mlx->player->pixel_coord.y = moveset.new_y;
			draw_character(mlx);
			draw_beam(mlx, mlx->player->pixel_coord.x,
				mlx->player->pixel_coord.y);
		}
	}
}

void	move_backward(t_mlx *mlx)
{
	t_moveset	moveset;

	if (mlx_is_key_down(mlx->id, MLX_KEY_S))
	{
		moveset.distance = CELLSIZE / 3;
		moveset.delta_x = -moveset.distance * cos(mlx->player->angle);
		moveset.delta_y = -moveset.distance * sin(mlx->player->angle);
		moveset.new_x = mlx->player->pixel_coord.x + moveset.delta_x;
		moveset.new_y = mlx->player->pixel_coord.y + moveset.delta_y;
		if (!is_wall(mlx, moveset.new_x, moveset.new_y))
		{
			delete_beam(mlx, mlx->player->pixel_coord.x,
				mlx->player->pixel_coord.y);
			mlx->player->pixel_coord.x = moveset.new_x;
			mlx->player->pixel_coord.y = moveset.new_y;
			draw_character(mlx);
			draw_beam(mlx, mlx->player->pixel_coord.x,
				mlx->player->pixel_coord.y);
		}
	}
}

void	move_right(t_mlx *mlx)
{
	t_moveset	moveset;

	if (mlx_is_key_down(mlx->id, MLX_KEY_D))
	{
		moveset.distance = CELLSIZE / 3;
		moveset.delta_x = -moveset.distance * sin(mlx->player->angle);
		moveset.delta_y = moveset.distance * cos(mlx->player->angle);
		moveset.new_x = mlx->player->pixel_coord.x + moveset.delta_x;
		moveset.new_y = mlx->player->pixel_coord.y + moveset.delta_y;
		if (!is_wall(mlx, moveset.new_x, moveset.new_y))
		{
			delete_beam(mlx, mlx->player->pixel_coord.x,
				mlx->player->pixel_coord.y);
			mlx->player->pixel_coord.x = moveset.new_x;
			mlx->player->pixel_coord.y = moveset.new_y;
			draw_character(mlx);
			draw_beam(mlx, mlx->player->pixel_coord.x,
				mlx->player->pixel_coord.y);
		}
	}
}

void	move_left(t_mlx *mlx)
{
	t_moveset	moveset;

	if (mlx_is_key_down(mlx->id, MLX_KEY_A))
	{
		moveset.distance = CELLSIZE / 3;
		moveset.delta_x = moveset.distance * sin(mlx->player->angle);
		moveset.delta_y = -moveset.distance * cos(mlx->player->angle);
		moveset.new_x = mlx->player->pixel_coord.x + moveset.delta_x;
		moveset.new_y = mlx->player->pixel_coord.y + moveset.delta_y;
		if (!is_wall(mlx, moveset.new_x, moveset.new_y))
		{
			delete_beam(mlx, mlx->player->pixel_coord.x,
				mlx->player->pixel_coord.y);
			mlx->player->pixel_coord.x = moveset.new_x;
			mlx->player->pixel_coord.y = moveset.new_y;
			draw_character(mlx);
			draw_beam(mlx, mlx->player->pixel_coord.x,
				mlx->player->pixel_coord.y);
		}
	}
}
