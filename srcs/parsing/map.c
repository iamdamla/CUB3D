/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: derblang <derblang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 11:27:28 by derblang          #+#    #+#             */
/*   Updated: 2024/01/27 11:46:21 by derblang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

static char	*read_file_lines(int fd)
{
	char	*buf;
	char	*temp;
	char	*newbuf;

	buf = malloc(sizeof(char));
	if (!buf)
		return (NULL);
	buf[0] = '\0';
	while (1)
	{
		temp = get_next_line(fd);
		if (temp == NULL)
			break ;
		newbuf = ft_strjoin(buf, temp);
		free(temp);
		free(buf);
		buf = newbuf;
	}
	return (buf);
}

char	**read_map(char *file)
{
	int		fd;
	char	**arr;
	char	*buf;

	fd = ft_open_fd(file);
	if (fd < 0)
		return (NULL);
	buf = read_file_lines(fd);
	arr = ft_split(buf, '\n');
	free(buf);
	close(fd);
	return (arr);
}

void	find_pos(char **map, t_player *player)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[i])
	{
		while (map[i][j])
		{
			if (map[i][j] == 'N' || map[i][j] == 'S' || map[i][j] == 'E'
				|| map[i][j] == 'W')
			{
				player->position.x = j;
				player->position.y = i;
				player->pixel_coord.x = (j * CELLSIZE) + CELLSIZE / 2;
				player->pixel_coord.y = (i * CELLSIZE) + CELLSIZE / 2;
			}
			j++;
		}
		i++;
		j = 0;
	}
}

void	check_all_map(char *file, t_cub *cub)
{
	cub->map_cpy = read_map(file);
	if (cub->map_cpy == NULL)
	{
		ft_puterror("Error reading the map\n");
	}
	cub->map = get_map_description(cub->map_cpy);
	if (cub->map == NULL)
	{
		ft_puterror("Error\nInvalid map texture\n");
		free_arr(cub->map_cpy);
	}
	if (check_map_components(cub->map) == -1)
	{
		free_arr(cub->map_cpy);
		ft_puterror("Error\nInvalid map!\n");
	}
	check_map_color(cub->map_cpy, cub);
	check_map_texture(cub->map_cpy, cub);
}
