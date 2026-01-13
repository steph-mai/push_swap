/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marberge <marberge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 18:12:01 by marberge          #+#    #+#             */
/*   Updated: 2025/11/19 14:39:15 by marberge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// #include <stdio.h>
// #include <bsd/string.h>

size_t	ft_strlen(const char *s);
int		ft_strncmp(const char *s1, const char *s2, size_t n);

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t		i;
	size_t		little_len;

	i = 0;
	little_len = ft_strlen(little);
	if (little_len == 0)
		return ((char *)big);
	while (big[i] && i + little_len <= len)
	{
		if (ft_strncmp(little, big + i, little_len) == 0)
			return ((char *)big + i);
		i++;
	}
	return (NULL);
}

// int	main(void)
// {
// 		const char *largestring = "FooBarBaz";
//		const char *smallstring = "Bar";

// 	printf("OFFICIELLE : %s\n", strnstr(largestring, smallstring, 60));
// 	printf("MAFONCTION : %s\n", ft_strnstr(largestring, smallstring, 60));
// }