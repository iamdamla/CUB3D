/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: derblang <derblang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 09:56:02 by derblang          #+#    #+#             */
/*   Updated: 2023/11/16 14:09:07 by derblang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_free(char **buffer)
{
	free(*buffer);
	*buffer = 0;
	return (*buffer);
}

char	*ft_next(char *buffer)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
	{
		ft_free(&buffer);
		return (NULL);
	}
	line = ft_calloc(sizeof(char), gnl_strlen(buffer) - i);
	if (!line)
	{
		ft_free(&buffer);
		return (NULL);
	}
	i++;
	j = 0;
	while (buffer[i])
		line[j++] = buffer[i++];
	ft_free(&buffer);
	return (line);
}

char	*ft_line(char *buffer)

{
	char	*line;
	int		i;

	i = 0;
	if (!buffer[i])
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\n')
		line = ft_calloc(sizeof(char), i + 2);
	else
		line = ft_calloc(sizeof(char), i + 1);
	if (!line)
	{
		free(line);
		return (NULL);
	}
	i = -1;
	while (buffer[++i] && buffer[i] != '\n')
		line[i] = buffer[i];
	if (buffer[i] == '\n')
		line[i] = buffer[i];
	return (line);
}

char	*gnl_read_file(int fd, char *buffer_static)
{
	char		*buffer;
	ssize_t		byte_read;

	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buffer)
		return (NULL);
	byte_read = 1;
	while (byte_read > 0 && !gnl_strchr(buffer_static, '\n'))
	{
		byte_read = read(fd, buffer, BUFFER_SIZE);
		if (byte_read == -1)
		{
			free(buffer);
			ft_free(&buffer_static);
			return (NULL);
		}
		buffer[byte_read] = '\0';
		buffer_static = gnl_strjoin(buffer_static, buffer);
	}
	free(buffer);
	return (buffer_static);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = gnl_read_file(fd, buffer);
	if (!buffer)
		return (NULL);
	line = ft_line(buffer);
	buffer = ft_next(buffer);
	return (line);
}
/*int	main(void)
{
	int			fd;

	fd = open("example.txt", O_RDONLY);
	
	printf("fd: %d\n", fd);
	printf("[1] str:%s", get_next_line(fd));
	printf("[2] str:%s", get_next_line(fd));
	printf("[3] str:%s", get_next_line(fd));
	printf("[4] str:%s", get_next_line(fd));
	printf("[5] str:%s", get_next_line(fd));
	printf("[6] str:%s", get_next_line(fd));
	return (0);
}*/
