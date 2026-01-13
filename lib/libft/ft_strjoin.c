/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marberge <marberge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 14:52:21 by marberge          #+#    #+#             */
/*   Updated: 2025/11/19 18:21:42 by marberge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// #include <stdio.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;
	int		i;
	int		k;

	i = 0;
	res = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (res == NULL)
		return (NULL);
	while (s1[i] != '\0')
	{
		res[i] = s1[i];
		i++;
	}
	k = 0;
	while (s2[k] != '\0')
	{
		res[i] = s2[k];
		i++;
		k++;
	}
	res[i] = '\0';
	return (res);
}

// int	main(void)
// {
// 	char	*res;

// 	res = ft_strjoin("Hello ", "World Marco");
// 	printf("%s\n", res);
// 	free (res);
// 	return (0);
// }