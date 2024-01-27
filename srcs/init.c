/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: derblang <derblang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 12:43:08 by derblang          #+#    #+#             */
/*   Updated: 2024/01/27 14:17:02 by derblang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	init(t_cub *cub, t_player *player, t_mlx *mlx)
{
	cub->map = NULL;
	cub->map_cpy = NULL;
	cub->color_code = NULL;
	cub->horizontale = 0;
	cub->verticale = 0;
	player->position.x = 0;
	player->position.y = 0;
	player->pixel_coord.x = 0;
	player->pixel_coord.y = 0;
	cub->floor_color = NULL;
	cub->ceilling_color = NULL;
	cub->path_east = NULL;
	cub->path_north = NULL;
	cub->path_west = NULL;
	cub->path_south = NULL;
	cub->south_tex = NULL;
	cub->north_tex = NULL;
	cub->west_tex = NULL;
	cub->east_tex = NULL;
	mlx->tab = malloc(sizeof(double) * (WIDTH));
	mlx->tab_wall = malloc(sizeof(t_orient) * WIDTH + 10);
}
