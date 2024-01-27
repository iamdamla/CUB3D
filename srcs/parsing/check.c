/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaplat <acaplat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 09:51:16 by derblang          #+#    #+#             */
/*   Updated: 2024/01/24 17:10:48 by acaplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	check_args(char argc)
{
	if (argc != 2)
		ft_puterror("Put only 2 arguments!");
}

void	check_file_extension(char *file)
{
	while (*file)
	{
		if (*file == '.')
		{
			if (ft_strstr(file, ".cub"))
				return ;
		}
		file++;
	}
	ft_puterror("Map extension is wrong!");
	exit(1);
}

int	ft_open_fd(char *filename)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		ft_puterror("File doesn't exist!");
	}
	return (fd);
}
