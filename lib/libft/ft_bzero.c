/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marberge <marberge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 16:39:13 by marberge          #+#    #+#             */
/*   Updated: 2025/11/14 14:56:37 by marberge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// #include <stdio.h>
// #include <strings.h>

size_t	ft_strlen(const char *s);

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*str;

	str = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		str[i] = '\0';
		i++;
	}
	return ;
}

/*
int	main(void)
{
	char	str[] = "hello world";
	printf("Before : %s\n", str);
	bzero(str, 5);
	printf("After  : %s\n", str);
	printf("\n");
	char	str2[] = "hello world";
	printf("Before : %s\n", str2);
	ft_bzero(str2, 5);
	printf("After  : %s\n", str2);
}
*/
