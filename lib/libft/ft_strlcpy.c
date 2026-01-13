/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marberge <marberge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 15:47:19 by marberge          #+#    #+#             */
/*   Updated: 2025/11/21 16:28:43 by marberge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// #include <bsd/string.h>
// #include <stdio.h>

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (src[count] != '\0')
	{
		if (i < size - 1 && size != 0)
		{
			dst[i] = src[i];
			i++;
		}
		count++;
	}
	if (size != 0)
		dst[i] = '\0';
	return (count);
}

// int	main(void)
// {
// 	char	*src = "Hello World";
// 	char	dest[6];
// 	size_t	res = ft_strlcpy(dest, src, 40);
// 	printf("ma fonction :\n");
// 	printf("dest : %s\n", dest);
// 	printf("result : %ld\n", res);

// 	printf("\nla fonction officielle :\n");
// 	char	*src2 = "Hello World";
// 	char	dest2[6];
// 	size_t	res2 = strlcpy(dest2, src2, 40);
// 	printf("dest : %s\n", dest2);
// 	printf("result : %ld\n", res2);
// }
