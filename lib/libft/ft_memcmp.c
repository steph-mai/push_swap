/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marberge <marberge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 16:36:00 by marberge          #+#    #+#             */
/*   Updated: 2025/11/14 18:08:05 by marberge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// #include <stdio.h>
// #include <string.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*us1;
	unsigned char	*us2;

	us1 = (unsigned char *)s1;
	us2 = (unsigned char *)s2;
	i = 0;
	if (n == 0)
		return (0);
	while (i < n - 1 && us1[i] == us2[i])
		i++;
	return (us1[i] - us2[i]);
}

// int		main(void)
// {
// 	char	*s1 = "abca";
// 	char	*s2 = "abcd";
// 	int		nb = 4;

// 	printf("officiel : %d\n", memcmp(s1, s2, nb));
// 	printf("ma fonct : %d\n", ft_memcmp(s1, s2, nb));
// }