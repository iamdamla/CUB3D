/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: derblang <derblang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 13:40:50 by derblang          #+#    #+#             */
/*   Updated: 2023/11/16 11:12:06 by derblang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *str, size_t len)
{
	ft_memset(str, 0, len);
}

/*int main(void)
{
    char b[10] = "hello";
    ft_bzero(b, sizeof(char) * 3);
    
    for(int i = 0; i < 6; i++)
    printf("%c", b[i]);
    printf("\n");
}*/
