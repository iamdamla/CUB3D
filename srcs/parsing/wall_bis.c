/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_bis.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: derblang <derblang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 20:11:02 by acaplat           #+#    #+#             */
/*   Updated: 2024/01/27 11:38:27 by derblang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../../cub3d.h"

int	check_closed_around_space(char **map)
{
	int		i;
	size_t	j;

	i = 0;
	while (map[i])
	{
		j = 1;
		while (map[i][j] && map[i][j + 1])
		{
			if (map[i][j] == ' ')
				if (check_around(map, i, j) == -1)
					ft_puterror("Error \nInvalid map: map is not closed\n");
			j++;
		}
		i++;
	}
	return (0);
}