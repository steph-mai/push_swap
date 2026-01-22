/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marberge <marberge@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 17:18:40 by marberge          #+#    #+#             */
/*   Updated: 2026/01/22 23:50:54 by marberge         ###   ########.fr       */
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
	if (ft_strcmp("--simple", str) == 0)
		return (3);
	if (ft_strcmp("--medium", str) == 0)
		return (5);
	if (ft_strcmp("--complex", str) == 0)
		return (7);
	if (ft_strcmp("--adaptive", str) == 0)
		return (11);
	if (ft_strcmp("--bench", str) == 0)
		return (100);
	return (-1);
}

int	is_flag(char *str, int start, int end)
{
	int		i;
	int		a;
	char	*potential_flag;
	int		res;

	potential_flag = malloc((end - start + 1) * sizeof(char));
	if (!potential_flag)
		return (-1);
	i = start;
	a = 0;
	while (i < end)
	{
		potential_flag[a] = str[i];
		i++;
		a++;
	}
	potential_flag[a] = '\0';
	res = compare_to_flag(potential_flag);
	free(potential_flag);
	return (res);
}

static int	main_loop(char *str, int res)
{
	int	i;
	int	tmp;	

	i = 0;
	while (str[i])
	{
		while (str[i] == ' ')
			i++;
		if (!str[i])
			break ;
		if (is_digit(str[i]) || (str[i] == '-' && is_digit(str[i + 1])))
		{
			if (!skip_valid_number(str, &i))
				return (-1);
		}
		else
		{
			tmp = process_flag_token(str, &i);
			if (tmp == -1)
				return (-1);
			res += tmp;
		}
	}
	return (res);
}

int	flag_selector(char *str)
{
	int	res;

	res = 0;
	if (!str || !str[0])
		return (-1);
	res = main_loop(str, res);
	if (res == -1)
		return (-1);
	if (res == 0)
		res = 11;
	return (res);
}
