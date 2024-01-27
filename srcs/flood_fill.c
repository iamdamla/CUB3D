/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: derblang <derblang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 10:07:05 by derblang          #+#    #+#             */
/*   Updated: 2024/01/27 14:14:27 by derblang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void	fill(char **map, t_point cur, int horizontale, int verticale)
{
	t_point	size;

	size.x = verticale;
	size.y = horizontale;
	if (cur.y < 0 || cur.y >= size.y || cur.x < 0 || cur.x >= size.x)
		return ;
	if (map[cur.x][cur.y] != ' ' || map[cur.x][cur.y] == '1'
		|| map[cur.x][cur.y] == 'F')
		return ;
	map[cur.x][cur.y] = 'F';
	fill(map, (t_point){cur.x - 1, cur.y}, horizontale, verticale);
	fill(map, (t_point){cur.x + 1, cur.y}, horizontale, verticale);
	fill(map, (t_point){cur.x, cur.y - 1}, horizontale, verticale);
	fill(map, (t_point){cur.x, cur.y + 1}, horizontale, verticale);
}

void	flood_fill(char **map, int horizontale, int verticale)
{
	int		i;
	int		j;
	t_point	begin;
	char	**map_ter;

	i = 0;
	j = 0;
	map_ter = map_cpy(map, verticale);
	while (map_ter[i])
	{
		while (map_ter[i][j])
		{
			if (map_ter[i][j] == ' ')
			{
				begin.x = i;
				begin.y = j;
				fill(map_ter, begin, horizontale, verticale);
			}
			j++;
		}
		i++;
		j = 0;
	}
	free_arr(map_ter);
}
