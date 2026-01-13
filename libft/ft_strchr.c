/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marberge <marberge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 23:23:20 by marberge          #+#    #+#             */
/*   Updated: 2025/11/14 12:07:09 by marberge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s);

char	*ft_strchr(const char *s, int c)
{
	unsigned int	i;
	char			*str;
	unsigned char	uc;

	uc = (unsigned char)c;
	str = (char *)s;
	i = 0;
	if (uc == 0)
		return (str + ft_strlen(s));
	while (s[i] != '\0')
	{
		if ((unsigned char)str[i] == uc)
			return (str + i);
		i++;
	}
	return (NULL);
}
