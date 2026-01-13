/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marberge <marberge@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 16:10:05 by marberge          #+#    #+#             */
/*   Updated: 2025/11/12 16:10:07 by marberge         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>
// #include <ctype.h>

int	ft_isascii(int c)
{
	if ((c >= 0 && c <= 127))
		return (1);
	return (0);
}

/*
int	main(void)
{
	printf("%d\n", ft_isascii(72)); // = 1
	printf("%d\n", ft_isascii(150)); // = 0
	
	printf("%d\n", isascii(75)); // = 1024
	printf("%d\n", isascii(150)); // = 0
}
*/
