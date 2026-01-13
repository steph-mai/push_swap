/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marberge <marberge@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 16:09:17 by marberge          #+#    #+#             */
/*   Updated: 2025/11/12 16:09:28 by marberge         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>
// #include <ctype.h>

int	ft_isalnum(int c)
{
	if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122) || (c >= 48 && c <= 57))
		return (1);
	return (0);
}

/*
int	main(void)
{
	printf("%d\n", ft_isalnum(95)); // = 0
	printf("%d\n", ft_isalnum(50)); // = 1
	printf("%d\n\n", ft_isalnum(72)); // = 1

	printf("%d\n", ft_isalnum(95)); // = 0
	printf("%d\n", isalnum(50)); // = 1+
	printf("%d\n", isalnum(72)); // = 1+
}
*/
