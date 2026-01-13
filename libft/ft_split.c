/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marberge <marberge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 19:06:14 by marberge          #+#    #+#             */
/*   Updated: 2025/11/22 18:43:53 by marberge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// #include <stdio.h>

size_t	ft_strlen(const char *s);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strdup(const char *s);

static int	ft_count_word(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	if (s[0] != c && s[0] != '\0')
		count++;
	while (s[i] != '\0')
	{
		if (s[i] == c && s[i + 1] != c && s[i + 1] != '\0')
			count++;
		i++;
	}
	return (count);
}

static int	ft_index_charset(char const *s, char c)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			return (i);
		i++;
	}
	return (i);
}

static void	ft_free_array(char **array, int row)
{
	int	i;

	i = 0;
	while (i < row)
	{
		free(array[i]);
		i++;
	}
	free(array);
}

static char	**ft_sep_words(char const *s, char **array, char c)
{
	int	row;
	int	i;
	int	k;

	i = 0;
	k = 0;
	row = 0;
	while (row < ft_count_word(s, c))
	{
		k = ft_index_charset(s + i, c);
		if (k == 0)
		{
			i += 1;
			continue ;
		}
		array[row] = ft_substr(s, i, k);
		if (!array[row])
			return (ft_free_array(array, row), NULL);
		i += k + 1;
		row++;
	}
	return (array);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	int		max_row;

	if (s == NULL)
		return (NULL);
	max_row = ft_count_word(s, c);
	res = malloc((1 + max_row) * sizeof(char *));
	if (res == NULL)
		return (NULL);
	res = ft_sep_words(s, res, c);
	if (!res)
		return (NULL);
	res[max_row] = NULL;
	return (res);
}

// int	main(void)
// {
// 	char	**result;
// 	int	i;

// 	i = 0;
// 	result = ft_split("      split       this for   me  !       ", ' ');
// 	// result = ft_split("marco-toto-titi", '-');
// 	while (result[i] != NULL)
// 	{
// 		printf("%s\n", result[i]);
// 		free(result[i++]);
// 	}
// 	free(result);
// 	return (0);
// }