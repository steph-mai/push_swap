/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marberge <marberge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 11:21:59 by marberge          #+#    #+#             */
/*   Updated: 2025/11/28 18:55:51 by marberge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	ft_count_len(unsigned long n)
{
	int	size;

	size = 1;
	if (n < 16)
		return (size);
	while (n / 16 > 0)
	{
		n = n / 16;
		size++;
	}
	return (size);
}

char	*ft_itoa_base(unsigned long n, int is_lowercase)
{
	char	*str;
	int		len;
	char	*base;	

	if (is_lowercase == 1)
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	len = ft_count_len(n);
	str = malloc((len + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	str[len--] = '\0';
	if (n == 0)
		str[0] = '0';
	while (n != 0)
	{
		str[len--] = base[n % 16];
		n = n / 16;
	}
	return (str);
}
