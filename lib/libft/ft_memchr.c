/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marberge <marberge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 15:53:07 by marberge          #+#    #+#             */
/*   Updated: 2025/11/14 16:33:55 by marberge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// #include <stdio.h>

size_t	ft_strlen(const char *s);

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*str;
	unsigned char	uc;

	i = 0;
	uc = (unsigned char)c;
	str = (unsigned char *)s;
	while (i < n)
	{
		if ((unsigned char)str[i] == uc)
			return (str + i);
		i++;
	}
	return (NULL);
}

// int	main(void)
// {
// 	// char	*test = "abc";
// 	// printf("test = %p et res = %p\n", test, ft_memchr(test, 97, 5));
// 	// printf("test = %p et res = %p\n", test, ft_memchr(test, 0, 5));
// 	// printf("test = %p et res = %p\n", test, ft_memchr(test, 98, 5));
// 	printf("res = %p\n", ft_memchr(0x7fffba4854c0, 512(0): '\0', 44));
// }