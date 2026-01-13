/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marberge <marberge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 14:26:12 by marberge          #+#    #+#             */
/*   Updated: 2025/11/20 17:22:12 by marberge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// #include <stdio.h>

static int	ft_count_len(long n)
{
	int	size;

	size = 1;
	if (n == 0)
		return (size);
	if (n < 0)
	{
		n = -n;
		size++;
	}
	if (n < 10)
		return (size);
	while (n / 10 > 0)
	{
		n = n / 10;
		size++;
	}
	return (size);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		len;
	long	ln;

	ln = (long)n;
	len = ft_count_len(ln);
	str = malloc((len + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	if (ln < 0)
	{
		str[0] = '-';
		ln = -ln;
	}
	str[len--] = '\0';
	if (ln == 0)
		str[0] = '0';
	while (ln != 0)
	{
		str[len--] = (ln % 10) + 48;
		ln = ln / 10;
	}
	return (str);
}

// int	main(void)
// {
// 	printf("123456 : %s\n", ft_itoa(123456));
// 	printf("-123456 : %s\n", ft_itoa(-123456));
// 	printf("0 : %s\n", ft_itoa(0));
// 	printf("-0 : %s\n", ft_itoa(-0));
// 	printf("-2147483647 : %s\n", ft_itoa(-2147483647));
// 	printf("2147483647 : %s\n", ft_itoa(2147483647));
// 	return (0);
// }
