/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: derblang <derblang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 14:14:49 by derblang          #+#    #+#             */
/*   Updated: 2024/01/27 14:13:21 by derblang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

char	**map_cpy(char **map, int verticale)
{
	char	**new_map;
	int		i;

	i = -1;
	new_map = malloc(sizeof(char *) * (verticale + 1));
	if (new_map == NULL)
	{
		ft_puterror("failed allocation new_map");
		return (NULL);
	}
	while (++i < verticale)
	{
		new_map[i] = malloc(sizeof(char) * (ft_strlen(map[i]) + 1));
		if (!new_map[i])
		{
			free_arr(new_map);
			ft_puterror("failed allocation new_map[i]");
			return (NULL);
		}
		ft_strcpy(new_map[i], map[i]);
	}
	new_map[i] = NULL;
	return (new_map);
}

char	**ft_arrdup(char **arr)
{
	char	**dup;
	int		arr_len;

	dup = NULL;
	if (!arr)
		return (NULL);
	arr_len = ft_arrlen(arr);
	if (!arr_len)
		return (NULL);
	dup = (char **)malloc(sizeof(char *) * (arr_len + 1));
	if (!dup)
		return (NULL);
	dup[arr_len] = NULL;
	while (arr_len--)
	{
		dup[arr_len] = ft_strdup(arr[arr_len]);
		if (!dup[arr_len])
		{
			free_arr(dup);
			return (NULL);
		}
	}
	return (dup);
}

int	find_bigger_nb(int nb1, int nb2)
{
	if (nb1 - nb2 > 0)
		return (nb1);
	else
		return (nb2);
}
