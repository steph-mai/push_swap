/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marberge <marberge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 23:33:56 by marberge          #+#    #+#             */
/*   Updated: 2025/11/20 17:22:45 by marberge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// #include <stdio.h>

size_t	ft_strlen(const char *s);

char	*ft_strdup(const char *s)
{
	int		i;
	int		len;
	char	*res;

	i = 0;
	len = ft_strlen(s);
	res = malloc((len + 1) * sizeof(char));
	if (res == NULL)
		return (NULL);
	while (i < len)
	{
		res[i] = s[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

// int	main(void)
// {
// 	char	*test;

// 	test = ft_strdup("hello world");
// 	printf("result = %s\n", test);
//  free(test);
//  return(0;)
// }