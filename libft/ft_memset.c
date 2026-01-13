/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marberge <marberge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 16:08:55 by marberge          #+#    #+#             */
/*   Updated: 2025/11/14 14:49:24 by marberge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// #include <string.h>
// #include <stdio.h>

size_t	ft_strlen(const char *s);

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*str;

	str = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		str[i] = (unsigned char)c;
		i++;
	}
	return (s);
}

// int	main(void)
// {
// 	char	str[] = "";
// 	printf("Before : %s\n", str);
// 	memset(str, 65, 1);
// 	printf("After  : %s\n", str);
// 	printf("\n");
// 	char	str2[] = "";
// 	printf("Before : %s\n", str2);
// 	ft_memset(str2, 65, 1);
// 	printf("After  : %s\n", str2);
// }
