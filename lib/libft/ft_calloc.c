/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marberge <marberge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 23:12:06 by marberge          #+#    #+#             */
/*   Updated: 2025/11/21 17:24:56 by marberge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// #include <stdio.h>

void	ft_bzero(void *s, size_t n);

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;

	if (size != 0 && nmemb > SIZE_MAX / size)
		return (malloc(0));
	ptr = malloc(nmemb * size);
	if (ptr == NULL)
		return (NULL);
	if (nmemb * size != 0)
		ft_bzero(ptr, nmemb * size);
	return (ptr);
}

// int	main(void)
// {
// 	int		i;
// 	// int		*pointer = (int *)ft_calloc(10, sizeof(int));
// 	char		*pointer2 = (char *)ft_calloc(11, sizeof(char));

// 	if (pointer2 == NULL)
// 		return (-1);
// 	i = 0;
// 	// while (i < 10)
// 	// {
// 	// 	pointer[i] = i;
// 	// 	i++;
// 	// }
// 	ft_strlcpy(pointer2, "hello world", 12);
// 	printf("%s\n", pointer2);
// 	// i = 0;
// 	// while (i < 10)
// 	// {
// 	// 	printf("%d ", pointer[i]);
// 	// 	i++;
// 	// }
// 	printf("\n");
// 	free(pointer2);
// 	return (0);
// }
