/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: derblang <derblang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 14:18:47 by derblang          #+#    #+#             */
/*   Updated: 2024/01/27 14:13:05 by derblang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	load_img(t_cub *cub)
{
	cub->north_tex = mlx_load_png(cub->path_north);
	cub->south_tex = mlx_load_png(cub->path_south);
	cub->east_tex = mlx_load_png(cub->path_east);
	cub->west_tex = mlx_load_png(cub->path_west);
	if (!cub->north_tex || !cub->south_tex || !cub->east_tex || !cub->west_tex)
	{
		printf("Error loading textures!\n");
		exit(1);
	}
}

int	rgb_to_hex(int r, int g, int b, int a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

static void	texture_helper(char **map, t_cub *cub, int i, int j)
{
	int	start;

	if (map[i][j] == 'W' && map[i][j + 1] == 'E')
	{
		start = j + 2;
		while (map[i][start] == ' ')
			++start;
		cub->path_west = map[i] + start;
	}
	else if (map[i][j] == 'E' && map[i][j + 1] == 'A')
	{
		start = j + 2;
		while (map[i][start] == ' ')
			++start;
		cub->path_east = map[i] + start;
	}
	else if (map[i][j] == 'S' && map[i][j + 1] == 'O')
	{
		start = j + 2;
		while (map[i][start] == ' ')
			++start;
		cub->path_south = map[i] + start;
	}
}

void	check_map_texture(char **map, t_cub *cub)
{
	int	i;
	int	j;
	int	start;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j] == ' ')
			++j;
		if (map[i][j] == 'N' && map[i][j + 1] == 'O')
		{
			start = j + 2;
			while (map[i][start] == ' ')
				++start;
			cub->path_north = map[i] + start;
		}
		texture_helper(map, cub, i, j);
		i++;
	}
}
