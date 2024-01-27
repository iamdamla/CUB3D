/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: derblang <derblang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 09:57:29 by derblang          #+#    #+#             */
/*   Updated: 2024/01/27 11:38:43 by derblang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

static void	check_wall_n(char **map)
{
	int	j;

	j = 0;
	while (map[0][j] == ' ')
		j++;
	while (map[0][j])
	{
		if (map[0][j] != '1' && map[0][j] != ' ')
			ft_puterror("Error: North wall not closed\n");
		j++;
	}
}

static void	check_wall_s(char **map)
{
	int	last_wall;
	int	j;

	last_wall = 0;
	j = 0;
	while (map[last_wall + 1])
		last_wall++;
	while (map[last_wall][j])
	{
		if (map[last_wall][j] != '1' && map[last_wall][j] != ' ')
			ft_puterror("Error: South wall not closed\n");
		j++;
	}
}

static void	check_wall_sides(char **map)
{
	int	i;

	i = 1;
	while (map[i])
	{
		if ((map[i][0] != '1' && map[i][0] != ' ') || (map[i][ft_strlen(map[i])
				- 1] != '1' && map[i][ft_strlen(map[i]) - 1] != ' '))
		{
			ft_puterror("Error: Side wall not closed\n");
		}
		i++;
	}
}

int	check_around(char **map, int i, size_t j)
{
	if (j > 0 && map[i][j - 1] && map[i][j - 1] != '1' && map[i][j - 1] != ' '
		&& map[i][j - 1] != '\n')
		return (-1);
	else if (map[i][j + 1] && map[i][j + 1] != '1' && map[i][j + 1] != ' '
		&& map[i][j + 1] != '\n')
		return (-1);
	else if (map[i + 1] && j < ft_strlen(map[i + 1]) && map[i + 1][j] != '1'
		&& map[i + 1][j] != ' ' && map[i + 1][j] != '\n')
		return (-1);
	else if (i > 0 && map[i - 1] && j < ft_strlen(map[i - 1]) && map[i
			- 1][j] != '1' && map[i - 1][j] != ' ' && map[i - 1][j] != '\n')
		return (-1);
	else if (map[i + 1] && j < ft_strlen(map[i + 1]) && map[i + 1][j] == '1'
		&& map[i - 1] && j < ft_strlen(map[i - 1]) && map[i - 1][j] != '1'
		&& map[i][j - 1] && map[i][j - 1] != '1' && map[i][j - 1] != ' '
		&& map[i][j - 1] != '\n')
		return (-1);
	return (0);
}

void	check_wall(char **map)
{
	if (check_closed_around_space(map))
		ft_puterror("Error\nSpaces are not closed!\n");
	check_wall_n(map);
	check_wall_s(map);
	check_wall_sides(map);
}