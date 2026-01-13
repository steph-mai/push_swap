/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marberge <marberge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 17:04:17 by marberge          #+#    #+#             */
/*   Updated: 2025/11/20 17:24:44 by marberge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// #include <stdio.h>

size_t	ft_strlen(const char *s);

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*res;
	int		s_len;
	int		i;

	i = 0;
	s_len = ft_strlen(s);
	res = malloc((s_len + 1) * sizeof(char));
	if (res == NULL)
		return (NULL);
	while (i < s_len)
	{
		res[i] = f(i, s[i]);
		i++;
	}
	res[i] = '\0';
	return (res);
}

// static char	ft_reverse_case(unsigned int i, char c)
// {
// 	(void)i;
// 	if (c >= 65 && c <= 90)
// 		return (c + 32);
// 	else if (c >= 97 && c <= 122)
// 		return (c - 32);
// 	else
// 		return (c);
// }

// int	main(void)
// {
// 	printf("hello WORLD : %s\n", ft_strmapi("hello WORLD", ft_reverse_case));
// 	return (0);
// }