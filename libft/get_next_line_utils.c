/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: derblang <derblang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 10:16:54 by derblang          #+#    #+#             */
/*   Updated: 2023/11/17 11:01:11 by derblang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	gnl_strlen(const char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

int	gnl_strchr( char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if (s[i] == c)
			return (1);
		i++;
	}
	return (0);
}

/*char    *ft_strjoin(char *s1, char *s2)
{
    char *dest;
    int i;
    int j;

    i = 0;
    j = 0;
    if (!s1)
    {
        s1 = malloc(1 * sizeof(char));
        s1[0] = '\0';
    }
    if (!s1 || !s2)
        return (0);
    dest = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
    if (!dest)
    {
        free(dest);
        return (NULL);
    }
    while (s1[i])
    {
        dest[i] = s1[i];
        i++;
    }
    while (s2[j])
    {
        dest[i] = s2[j];
        i++;
        j++;
    }
    dest[i] = '\0';
    return (dest);
}*/
char	*gnl_strjoin(char *s1, char *s2)
{
	char	*dest;
	int		i;
	int		j;

	i = -1;
	j = 0;
	if (!s1)
	{
		s1 = malloc(1 * sizeof(char));
		s1[0] = '\0';
	}
	if (!s1 || !s2)
		return (NULL);
	dest = (char *)malloc(sizeof(char) * (gnl_strlen(s1) + gnl_strlen(s2) + 1));
	if (!dest)
		return (NULL);
	while (s1[++i])
		dest[i] = s1[i];
	while (s2[j])
		dest[i++] = s2[j++];
	dest[i] = '\0';
	ft_free(&s1);
	return (dest);
}

// void	ft_bzero(void *str, size_t len)
// {
// 	char	*ptr;
// 	size_t	i;

// 	ptr = (char *)str;
// 	i = 0;
// 	while (i < len)
// 	{
// 		*ptr = '\0';
// 		ptr++;
// 		i++;
// 	}
// }

void	*gnl_calloc(size_t count, size_t size)
{
	char	*str;

	str = malloc(count * size);
	if (!str)
		return (NULL);
	ft_bzero(str, count * size);
	return (str);
}
