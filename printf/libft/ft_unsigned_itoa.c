/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned_itoa.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marberge <marberge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 16:55:39 by marberge          #+#    #+#             */
/*   Updated: 2025/11/28 18:55:51 by marberge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	ft_count_len(unsigned long n)
{
	int	size;

	size = 1;
	if (n < 10)
		return (size);
	while (n / 10 > 0)
	{
		n = n / 10;
		size++;
	}
	return (size);
}

char	*ft_unsigned_itoa(unsigned int n)
{
	char	*str;
	int		len;
	long	ln;

	ln = (unsigned long)n;
	len = ft_count_len(ln);
	str = malloc((len + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
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
