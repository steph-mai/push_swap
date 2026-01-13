/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marberge <marberge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 17:28:21 by marberge          #+#    #+#             */
/*   Updated: 2025/11/20 18:58:16 by marberge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// #include <stdio.h>

size_t	ft_strlen(const char *s);

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	int		i;

	i = 0;
	if (!s || !f)
		return ;
	while (s[i] != '\0')
	{
		f(i, &s[i]);
		i++;
	}
	return ;
}

// static void	ft_reverse_case(unsigned int i, char *c)
// {
// 	(void)i;
// 	if (*c >= 65 && *c <= 90)
// 		*c = *c + 32;
// 	else if (*c >= 97 && *c <= 122)
// 		*c = *c - 32;
// }

// int	main(void)
// {
// 	char	test[] = "hello WORLD";
// 	printf("avant : %s\n", test);
// 	ft_striteri(test, ft_reverse_case);
// 	printf("apres : %s\n", test);
// 	return (0);
// }