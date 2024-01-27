/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaplat <acaplat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 13:49:47 by derblang          #+#    #+#             */
/*   Updated: 2024/01/24 17:56:08 by acaplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *str, int c)
{
	int		i;
	char	*str2;

	i = 0;
	while (str[i] != '\0')
		i++;
	str2 = (char *)str;
	while (i >= 0)
	{
		if (str2[i] == (unsigned char)c)
			return (&str2[i]);
		i--;
	}
	return (0);
}
