/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marberge <marberge@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 12:09:36 by marberge          #+#    #+#             */
/*   Updated: 2025/11/15 13:21:08 by marberge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
// #include <stdlib.h>

int	ft_atoi(const char *nptr)
{
	unsigned char	*str;
	unsigned int	i;
	int				sign;
	int				res;

	str = (unsigned char *)nptr;
	i = 0;
	res = 0;
	sign = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -sign;
		i++;
	}
	while (str[i] >= 48 && str[i] <= 57)
	{
		res = (res * 10) + (str[i] - 48);
		i++;
	}
	return (res * sign);
}

/*
int	main(void)
{
	printf("123456789 : %d\n", ft_atoi("123456789"));
	printf("-123456789 : %d\n", ft_atoi("-123456789"));
	printf("+123456789 : %d\n", ft_atoi("+123456789"));
	printf("-2147483660 : %d\n", ft_atoi("-2147483660"));
	printf("\"     123456789\" : %d\n", ft_atoi("     123456789"));
	printf("\"   -+123456789\" : %d\n", ft_atoi("    -+123456789"));
	printf("\"   +-123456789\" : %d\n", ft_atoi("    +-123456789"));
	printf("\"   ++++-+23456789\" : %d\n", ft_atoi("++++-+123456789"));
	printf("\"   ++++-+--23456789\" : %d\n", ft_atoi("++++-+--123456789"));
	printf("abc : %d\n\n", ft_atoi("abc"));
	
	printf("123456789 : %d\n", atoi("123456789"));
	printf("-123456789 : %d\n", atoi("-123456789"));
	printf("+123456789 : %d\n", atoi("+123456789"));
	printf("-2147483660 : %d\n", atoi("-2147483660"));
	printf("\"     123456789\" : %d\n", atoi("     123456789"));
	printf("\"   -+123456789\" : %d\n", atoi("    -+123456789"));
	printf("\"   +-123456789\" : %d\n", atoi("    +-123456789"));
	printf("\"   ++++-+23456789\" : %d\n", atoi("++++-+123456789"));
	printf("\"   ++++-+--23456789\" : %d\n", atoi("++++-+--123456789"));
	printf("abc : %d\n", atoi("abc"));
}
*/
