/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marberge <marberge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 17:21:04 by marberge          #+#    #+#             */
/*   Updated: 2025/11/14 14:23:48 by marberge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// #include <stdio.h>
// #include <string.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*sr;
	unsigned char	*de;
	size_t			i;

	i = 0;
	sr = (unsigned char *)src;
	de = (unsigned char *)dest;
	if (dest == src)
		return (dest);
	while (i < n)
	{
		de[i] = sr[i];
		i++;
	}
	return (de);
}

// int	main(void)
// {
// 	char	src[] = "ABCDE";
// 	char	dest[10];
// 	printf("Before : %s\n", src);
// 	memcpy(NULL, NULL,  NULL);
// 	printf("After  : %s\n", dest);
// 	printf("\n");
// 	char	src2[] = "ABCDE";
// 	char	dest2[10];
// 	printf("Before : %s\n", src2);
// 	ft_memcpy(NULL, NULL,  NULL);
// 	printf("After  : %s\n", dest2);
// }
