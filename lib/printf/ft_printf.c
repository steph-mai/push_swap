/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marberge <marberge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 12:33:56 by marberge          #+#    #+#             */
/*   Updated: 2026/01/21 14:26:08 by marberge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int	ft_printf(int fd, const char *str, ...)
{
	va_list	args;
	int		count;
	char	buffer[BUFFER_SIZE];
	int		buf_index;

	count = 0;
	buf_index = 0;
	if (!str)
		return (-1);
	va_start(args, str);
	ft_bzero(buffer, BUFFER_SIZE);
	count = ft_parsing(str, buffer, &buf_index, args);
	va_end(args);
	if (count == -1)
		return (-1);
	if (ft_flush_buffer(buffer, &buf_index, fd) == -1)
		return (-1);
	return (count);
}

// #include <stdio.h>

// int	main(void)
// {
// 	void	*ptr;

// 	ptr = NULL;
// 	printf(" => %d\n", ft_printf("char : %c", 'H'));
// 	printf(" => %d\n\n", printf("char : %c", 'H'));
// 	printf(" => %d\n", ft_printf("string : %s", "Hello world"));
// 	printf(" => %d\n\n", printf("string : %s", "Hello world"));
// 	printf(" => %d\n", ft_printf("number %%d : %d", 3));
// 	printf(" => %d\n\n", printf("number %%d : %d", 3));
// 	printf(" => %d\n", ft_printf("number2 : %%i : %i | %%u : %u", 6, 9));
// 	printf(" => %d\n\n", printf("number2 : %%i : %i | %%u : %u", 6, 9));
// 	printf(" => %d\n", ft_printf("hexa : %%x : %x | %%X : %X", 756389, 756389));
// 	printf(" => %d\n\n", printf("hexa : %%x : %x | %%X : %X", 756389, 756389));
// 	printf(" => %d\n", ft_printf("pointer : %p | %p ", &ptr, (void *)0));
// 	printf(" => %d\n", printf("pointer : %p | %p ", &ptr, (void *)0));
// 	return (0);
// }
