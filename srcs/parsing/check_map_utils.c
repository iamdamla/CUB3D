/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: derblang <derblang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 13:29:43 by derblang          #+#    #+#             */
/*   Updated: 2024/01/27 11:36:33 by derblang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	texture_check(char *line, int *count)
{
	size_t	i;

	i = 0;
	while (line[i] == ' ')
		i++;
	if (line[i] == 'N' && line[i + 1] == 'O')
		(*count)++;
	else if (line[i] == 'S' && line[i + 1] == 'O')
		(*count)++;
	else if (line[i] == 'W' && line[i + 1] == 'E')
		(*count)++;
	else if (line[i] == 'E' && line[i + 1] == 'A')
		(*count)++;
	else if (line[i] == 'F')
		(*count)++;
	else if (line[i] == 'C')
		(*count)++;
}

char	**get_map_description(char **map)
{
	size_t	i;
	int		count;

	i = -1;
	count = 0;
	while (map[++i])
	{
		texture_check(map[i], &count);
		if (count == 6)
		{
			while (map[++i])
			{
				if (map[i][0] == '\n')
					continue ;
				if (ft_strstr(map[i], "1\0"))
					return (ft_arrdup(map + i));
				else
					return (NULL);
			}
		}
	}
	return (NULL);
}