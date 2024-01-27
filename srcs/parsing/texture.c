/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: derblang <derblang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 13:23:11 by derblang          #+#    #+#             */
/*   Updated: 2024/01/27 14:11:46 by derblang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

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

static void	remove_spaces(char *str)
{
	int	k;
	int	i;

	k = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] != ' ')
			str[k++] = str[i];
		i++;
	}
	str[k] = '\0';
}

static char	*extract_color(char *line, int start)
{
	char	*test;

	test = ft_strdup(line + start + 1);
	return (test);
}

static void	update_color(char type, char *color_code, t_cub *cub)
{
	remove_spaces(color_code);
	if (type == 'C')
	{
		cub->ceilling_color = color_code;
		printf("%s\n", cub->ceilling_color);
	}
	else if (type == 'F')
	{
		cub->floor_color = color_code;
		printf("%s\n", cub->floor_color);
	}
}

void	check_map_color(char **map, t_cub *cub)
{
	int		i;
	char	*color_code;
	int		j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j] == ' ')
			j++;
		while (map[i][j])
		{
			if (map[i][j] == 'C' || map[i][j] == 'F')
			{
				color_code = extract_color(map[i], j);
				update_color(map[i][j], color_code, cub);
				get_color(map[i], cub);
				free(color_code);
			}
			j++;
		}
		i++;
	}
}
