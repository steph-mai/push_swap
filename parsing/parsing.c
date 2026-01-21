/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marberge <marberge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 14:36:44 by stmaire           #+#    #+#             */
/*   Updated: 2026/01/20 18:21:40 by marberge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static long	ft_atol(char *s)
{
	long	nb;
	size_t	i;
	int		neg;

	nb = 0;
	i = 0;
	neg = 0;
	while ((s[i] >= 9 && s[i] <= 13) || s[i] == 32)
		i++;
	if (s[i] == '-' || s[i] == '+')
	{
		if (s[i] == '-')
			neg = 1;
		i++;
	}
	while (s[i] >= '0' && s[i] <= '9')
	{
		nb = nb * 10 + s[i] - '0';
		i++;
	}
	if (neg == 1)
		nb = -nb;
	return (nb);
}

char	*from_args_to_big_str(int argc, char **argv)
{
	char	*s;
	char	*temp;
	int		i;

	if (argc < 2)
		return (NULL);
	i = 1;
	s = ft_strdup("");
	if (!s)
		return (NULL);
	while (i < argc)
	{
		temp = ft_strjoin(s, argv[i]);
		free(s);
		s = temp;
		temp = ft_strjoin(s, " ");
		free(s);
		s = temp;
		i++;
	}
	return (s);
}

char	**put_args_in_array(char *big_string)
{
	char	**tab;
	
	tab = ft_split(big_string, ' ');
	if (!tab)
	{
		free(big_string);
		return (NULL);
	}
	free(big_string);
	return (tab);
}

t_stack_node	*build_stack(char **tab)
{
	int				i;
	long			nb;
	t_stack_node	*stack;

	i = 0;
	stack = NULL;
	if (check_args_syntax(tab) == 0)
		return (free_if_error(&stack, tab));
	while (tab[i])
	{
		nb = ft_atol (tab[i]);
		if (check_args_overflow(nb) == 0
			|| check_args_doubles(stack, (int)nb) == 0)
			return (free_if_error(&stack, tab));
		append_node(&stack, (int)nb);
		i++;
	}
	index_stack(stack);
	free_tab(tab);
	return (stack);
}
