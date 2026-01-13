/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marberge <marberge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 11:07:49 by marberge          #+#    #+#             */
/*   Updated: 2025/11/14 12:05:04 by marberge         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// #include <stdio.h>

size_t	ft_strlen(const char *s);

char	*ft_strrchr(const char *s, int c)
{
	char			*str;
	int				i;
	unsigned char	uc;

	uc = (unsigned char)c;
	str = (char *)s;
	i = ft_strlen(s);
	if (uc == 0)
		return (str + ft_strlen(s));
	while (i >= 0)
	{
		if ((unsigned char)str[i] == uc)
			return (str + i);
		i--;
	}
	return (NULL);
}

// int	main(void)
// {
// 	printf("%s\n", ft_strrchr("", 'a'));
// 	printf("%s\n", ft_strrchr("abc", '\0'));
// 	printf("%s\n", ft_strrchr("abc", 'b'));
// }
