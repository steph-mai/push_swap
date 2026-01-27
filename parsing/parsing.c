/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marberge <marberge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 14:36:44 by stmaire           #+#    #+#             */
/*   Updated: 2026/01/27 19:22:41 by marberge         ###   ########.fr       */
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

t_error	from_args_to_big_str(int argc, char **argv, t_data *data)
{
	char	*s;
	char	*temp;
	int		i;

	if (argc < 2)
		return (set_error(NO_ARGS, *data));
	i = 1;
	s = ft_strdup("");
	if (!s)
		return (set_error(BIG_STR_FAIL, *data));
	while (i < argc)
	{
		temp = ft_strjoin(s, argv[i]);
		free(s);
		if (!temp)
		return (set_error(BIG_STR_FAIL, *data));
		s = temp;
		temp = ft_strjoin(s, " ");
		free(s);
		if (!temp)
			return (set_error(BIG_STR_FAIL, *data));
		s = temp;
		i++;
	}
	data->big_str = s;
	return (NO_ERROR);
}

char	**put_args_in_array(t_data *data)
{
	char	**tab;

	if (!data->big_str)
	{
		set_error(TAB_FAIL, *data);
		return (NULL);
	}
	tab = ft_split(data->big_str, ' ');
	if (!tab)
	{
		set_error(TAB_FAIL, *data);
		return (NULL);
	}
	free(data->big_str);
	return (tab);
}

t_stack	*build_stack(t_data *data)
{
	int				i;
	long			nb;
	t_stack			*stack;

	i = 0;
	stack = NULL;
	if (check_args_syntax(data->tab) == 0)
		return (free_if_error(&stack, data->tab));
	while (data->tab[i])
	{
		nb = ft_atol (data->tab[i]);
		if (check_args_overflow(nb) == 0
			|| check_args_doubles(stack, (int)nb) == 0)
		{
			set_error(CREATE_STACK_FAIL, *data);
			return (NULL);
		}
		append_node(&stack, (int)nb, data);
		if (data->error_id != NO_ERROR)
			return (NULL);
		i++;
	}
	index_stack(stack, data);
	if (data->error_id != NO_ERROR)
			return (NULL);
	free_tab(data->tab);
	return (stack);
}
