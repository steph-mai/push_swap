/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marberge <marberge@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 16:10:14 by marberge          #+#    #+#             */
/*   Updated: 2025/11/12 16:10:24 by marberge         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>
// #include <ctype.h>

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}

/*
// main pour tester (a retirer pour le rendu)
int	main(void)
{
	printf("%d\n", ft_isdigit(72)); // = 0
	printf("%d\n", ft_isdigit(50)); // = 1

	printf("%d\n", isdigit(75)); // = 0
	printf("%d\n", isdigit(50)); // = 1024
}
*/
