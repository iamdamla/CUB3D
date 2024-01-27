/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: derblang <derblang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 10:42:31 by derblang          #+#    #+#             */
/*   Updated: 2024/01/27 11:37:21 by derblang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	check_color_arr(char **arr)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (arr[i][j] == ' ')
		j++;
	while (arr[i])
	{
		j = 0;
		while (arr[i][j])
		{
			if (ft_isalpha(arr[i][j]))
			{
				ft_puterror("Error\nWrong character in the color\n");
				exit(0);
			}
			j++;
		}
		i++;
	}
	if (i < 3)
		ft_puterror("Wrong color syntax \n");
}

static int	is_color_in_range(int value)
{
	return (value >= 0 && value <= 255);
}

static void	rgb_helper(t_cub *cub, char c, char **colors)
{
	int	i;

	if (c == 'F')
	{
		i = 0;
		while (i < 3)
		{
			cub->floor[i] = ft_atoi(colors[i]);
			if (!is_color_in_range(cub->floor[i]))
				ft_puterror("Error\nFloor color is out of range\n");
			i++;
		}
	}
}

static void	count_comma(char *line, int comma)
{
	while (*line)
	{
		if (*line == ',')
			comma++;
		line++;
	}
	if (comma != 2)
		ft_puterror("Error\nWrong color syntax\n");
}

void	convert_rgb(char *line, t_cub *cub, char c)
{
	char	**colors;
	int		i;
	int		comma;

	comma = 0;
	while (!ft_isdigit(*line))
		line++;
	count_comma(line, comma);
	colors = ft_split(line, ',');
	check_color_arr(colors);
	rgb_helper(cub, c, colors);
	if (c == 'C')
	{
		i = 0;
		while (i < 3)
		{
			cub->ceilling[i] = ft_atoi(colors[i]);
			if (!is_color_in_range(cub->ceilling[i]))
				ft_puterror("Error\nCeilling color is out of range\n");
			i++;
		}
	}
	free_arr(colors);
}