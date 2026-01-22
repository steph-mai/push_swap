/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stmaire <stmaire@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 17:18:40 by marberge          #+#    #+#             */
/*   Updated: 2026/01/22 16:07:50 by stmaire          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0')
	{
		i++;
	}
	return (s1[i] - s2[i]);
}

static int	compare_to_flag(char *str)
{
	if (ft_strcmp("simple", str) == 0)
		return (3);
	if (ft_strcmp("medium", str) == 0)
		return (5);
	if (ft_strcmp("complex", str) == 0)
		return (7);
	if (ft_strcmp("adaptive", str) == 0)
		return (11);
	if (ft_strcmp("bench", str) == 0)
		return (100);
	return (-1);
}

static int	is_flag(char *str, int i, int k)
{
	int			j;
	int			a;
	int			size;
	char		*potential_flag;

	a = 0;
	j = i + 2;
	size = k - j;
	potential_flag = malloc((size + 1) * sizeof(char));
	if (!potential_flag)
		return (-1);
	while (j < k)
	{
		potential_flag[a] = str[j];
		j++;
		a++;
	}
	potential_flag[a] = '\0';
	a = compare_to_flag(potential_flag);
	free(potential_flag);
	return (a);
}

static int	main_loop(char *str, int i, int k, int res)
{
	int	temp;

	temp = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '-' && str[i + 1] == '-')
		{
			k = i + 2;
			while (str[k] != ' ' && str[k] != '\0')
			{
				if (str[k] < 97 || str[k] > 122)
					return (-1);
				k++;
			}
			if (k == 0)
				return (-1);
			temp = is_flag(str, i, k);
			if (temp == -1)
				return (-1);
			res += temp;
			i = k;
		}
		i++;
	}
	return (res);
}

int	flag_selector(char *str)
{
	int	i;
	int	k;
	int	res;

	i = 0;
	k = 0;
	res = 0;
	res = main_loop(str, i, k, res);
	if (res == -1)
		return (-1);
	if (res == 0)
		res = 11;
	return (res);
}
