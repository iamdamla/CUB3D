/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: derblang <derblang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 13:23:11 by derblang          #+#    #+#             */
/*   Updated: 2024/01/27 11:38:10 by derblang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

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

void	get_color(char *line, t_cub *cub)
{
	int	i;

	i = 0;
	while (line[i] && ft_isspace(line[i]))
		i++;
	if (line[i] == 'C' || line[i] == 'F')
	{
		convert_rgb(line + i + 1, cub, line[i]);
	}
	else
	{
		printf("Invalid color code\n");
	}
}

static char	*remove_spaces(const char *str)
{
	int		len;
	char	*result;
	int		result_index;
	int		i;

	len = ft_strlen(str);
	result = malloc(len + 1);
	if (result == NULL)
		return (NULL);
	result_index = 0;
	i = 0;
	while (i < len)
	{
		if (!ft_isspace(str[i]))
			result[result_index++] = str[i];
		i++;
	}
	result[result_index] = '\0';
	return (result);
}

void	check_map_color(char **map, t_cub *cub)
{
	char	*color_code;
	int		i;
	int		j;
	int		start;

	i = -1;
	while (map[++i])
	{
		j = 1;
		while (map[i][j] == ' ')
			j++;
		if (map[i][j] == 'C' || map[i][j] == 'F')
		{
			start = j + 1;
			while (map[i][start] == ' ')
				++start;
			color_code = remove_spaces(map[i] + start);
			if (map[i][j] == 'C')
				cub->ceilling_color = color_code;
			else if (map[i][j] == 'F')
				cub->floor_color = color_code;
			get_color(map[i], cub);
			free(color_code);
		}
	}
}