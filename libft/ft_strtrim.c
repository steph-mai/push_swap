/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marberge <marberge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 15:50:57 by marberge          #+#    #+#             */
/*   Updated: 2025/11/20 17:23:40 by marberge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// #include <stdio.h>

size_t	ft_strlen(const char *s);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strdup(const char *s);

static int	ft_is_charset(char const c, char const *charset)
{
	int	i;

	i = 0;
	while (charset[i] != '\0')
	{
		if (charset[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int	start;
	int	end;
	int	len;

	len = ft_strlen(s1);
	if (len == 0)
		return (ft_strdup(""));
	start = 0;
	end = len - 1;
	while (ft_is_charset(s1[start], set) == 1)
		start++;
	while (ft_is_charset(s1[end], set) == 1)
		end--;
	if (start > end)
		return (ft_strdup(""));
	return (ft_substr(s1, start, end - start + 1));
}

/*
int	main(void)
{
	printf("s1 = abcde // set = bcd // res = %s\n", ft_strtrim("abcde", "bcd"));
	printf("\n--------------------------------\n");
	printf("s1 = abcde // set = ae // res = %s\n", ft_strtrim("abcde", "ae"));
	printf("\n--------------------------------\n");
	printf
	("s1 = abcde // set = aebd // res = %s\n", ft_strtrim("abcde", "aebd"));
	printf("\n--------------------------------\n");
	printf("s1 = abcde // set = \"\" // res = %s\n", ft_strtrim("abcde", ""));
	printf("\n--------------------------------\n");
	printf("s1 = \"\" // set = \"\" // res = \"%s\"\n", ft_strtrim("", ""));
	printf("\n--------------------------------\n");
	printf
	("s1 = \"aaa\" // set = \"a\" // res = \"%s\"\n", ft_strtrim("aaa", "a"));
}
*/