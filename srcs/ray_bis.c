/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_bis.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: derblang <derblang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 16:48:29 by acaplat           #+#    #+#             */
/*   Updated: 2024/01/27 11:46:21 by derblang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void find_orientation_left(t_mlx *mlx,int y)
{
 if(y < mlx->player->pixel_coord.y)
	{
		if(y % CELLSIZE == 31)
			mlx->wall_coord.orient = 'n';
		else
			mlx->wall_coord.orient = 'w';
	}
	else if(y > mlx->player->pixel_coord.y)
	{
		if(y % CELLSIZE == 0)
			mlx->wall_coord.orient = 's';
		else
			mlx->wall_coord.orient = 'w';
	}
}

static void find_orientation_right(t_mlx *mlx,int y)
{
	if(y < mlx->player->pixel_coord.y)
	{
		if(y % CELLSIZE == 31)
			mlx->wall_coord.orient = 'n';
		else
			mlx->wall_coord.orient = 'e';
	}
	if(y > mlx->player->pixel_coord.y)
	{
		if(y % CELLSIZE == 0)
			mlx->wall_coord.orient = 's';
		else
			mlx->wall_coord.orient = 'e';
	}
}

void find_orientation(t_mlx *mlx,int x,int y)
{
	(void) y;
	if(mlx->player->pixel_coord.x > x)
	{
		find_orientation_left(mlx,y);
	}
	else if(mlx->player->pixel_coord.x < x)
	{
		find_orientation_right(mlx,y);
	}
}


int	is_wall(t_mlx *mlx, int x, int y)
{
	int	map_x;
	int	map_y;

	map_x = floor(x / CELLSIZE);
	map_y = floor(y / CELLSIZE);
	if (map_x >= 0 && map_x < WIDTH && map_y >= 0 && map_y < HEIGHT)
	{
		if (mlx->cub->map[map_y][map_x] == '1')
		{
			
			mlx->wall_coord.x = x;
			mlx->wall_coord.y = y;
			mlx->raycast.dist_ray = (sqrt(pow(x - mlx->raycast.x1, 2) + pow(y
							- mlx->raycast.y1, 2)));
			find_orientation(mlx,x,y);
			return (1);
		}
	}
	return (0);
}

