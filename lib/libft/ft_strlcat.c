/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marberge <marberge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 17:42:04 by marberge          #+#    #+#             */
/*   Updated: 2025/11/21 16:26:29 by marberge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <bsd/string.h>
//#include <stdio.h>

size_t	ft_strlen(const char *s);

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	k;
	size_t	len_dst;
	size_t	len_src;

	len_dst = ft_strlen((const char *)dst);
	len_src = ft_strlen(src);
	if (size <= len_dst)
		return (size + len_src);
	i = len_dst;
	k = 0;
	while (i + 1 < size && src[k] != '\0')
	{
		dst[i] = src[k];
		i++;
		k++;
	}
	dst[i] = '\0';
	return (len_dst + len_src);
}

/*
int	main(void)
{
	printf("ma fonction :\n");
    char dest[10] = "Hi";
    const char *src = " there!";
    size_t ret = ft_strlcat(dest, src, sizeof(dest));
    printf("dest = \"%s\"\n", dest);
    printf("return = %zu\n", ret);

	printf("\nla fonction officielle :\n");
    char dest2[10] = "Hi";
    const char *src2 = " there!";
    size_t ret2 = strlcat(dest2, src2, sizeof(dest2));
    printf("dest = \"%s\"\n", dest2);
    printf("return = %zu\n", ret2);
    return 0;
}
*/
