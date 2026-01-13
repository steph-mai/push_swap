/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marberge <marberge@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 16:10:33 by marberge          #+#    #+#             */
/*   Updated: 2025/11/12 16:10:37 by marberge         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>
// #include <ctype.h>

int	ft_isprint(int c)
{
	if ((c >= 32 && c <= 126))
		return (1);
	return (0);
}

/*
int	main(void)
{
	printf("%d\n", ft_isprint(25)); // = 0
	printf("%d\n", ft_isprint(98)); // = 1
	
	printf("%d\n", isprint(25)); // = 0
	printf("%d\n", isprint(98)); // = 1
}
*/
