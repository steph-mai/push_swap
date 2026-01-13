/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marberge <marberge@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 16:11:02 by marberge          #+#    #+#             */
/*   Updated: 2025/11/12 16:11:08 by marberge         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" 
//#include <stdio.h>
//#include <string.h>

size_t	ft_strlen(const char *s)
{
	unsigned int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

/*
int	main(void)
{
	printf("%ld\n", ft_strlen("hello world"));
	printf("%ld\n", strlen("hello world"));
}
*/
