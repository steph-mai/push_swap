/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marberge <marberge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 22:04:04 by marberge          #+#    #+#             */
/*   Updated: 2025/11/20 17:22:25 by marberge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// #include <string.h>
// #include <stdio.h>

void	*ft_memcpy(void *dest, const void *src, size_t n);

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*sr;
	unsigned char	*de;

	sr = (unsigned char *)src;
	de = (unsigned char *)dest;
	if (de > sr)
	{
		while (n > 0)
		{
			n--;
			de[n] = sr[n];
		}
	}
	if (de <= sr)
		ft_memcpy(de, sr, n);
	return (de);
}

// int	main(void)
// {
// 	printf("==> si dest < src :\n");
// 	char	src[] = "ABCDE";
// 	printf("Before : %s\n", src);
// 	memmove(src, src + 1,  5);
// 	printf("After  : %s\n", src);
// 	printf("\n");
// 	char	src2[] = "ABCDE";
// 	printf("Before : %s\n", src2);
// 	ft_memmove(src2, src2 + 1,  5);
// 	printf("After  : %s\n", src2);

// 	printf("\n==> si dest > src :\n");
// 	char	src3[] = "ABCDE";
// 	printf("Before : %s\n", src3);
// 	memmove(src3 + 1, src3,  5);
// 	printf("After  : %s\n", src3);
// 	printf("\n");
// 	char	src4[] = "ABCDE";
// 	printf("Before : %s\n", src4);
// 	ft_memmove(src4 + 1, src4,  5);
// 	printf("After  : %s\n", src4);
// }
