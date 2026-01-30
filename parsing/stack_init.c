/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steph <steph@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 15:55:52 by stmaire           #+#    #+#             */
/*   Updated: 2026/01/28 16:00:52 by steph            ###   ########.fr       */
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

static int	process_one_arg(t_stack **stack, char *arg, t_data *data)
{
	long	nb;

	nb = ft_atol(arg);
	if (check_args_overflow(nb) == 0
		|| check_args_doubles(*stack, (int)nb) == 0)
	{
		set_error(CREATE_STACK_FAIL, data);
		return (1);
	}
	append_node(stack, (int)nb, data);
	if (data->error_id != NO_ERROR)
		return (1);
	return (0);
}

static t_stack	*finalize_stack(t_stack *stack, t_data *data)
{
	index_stack(stack, data);
	if (data->error_id != NO_ERROR)
	{
		free_stack(&stack);
		return (NULL);
	}
	free_tab(data->tab);
	data->tab = NULL;
	return (stack);
}

t_stack	*build_stack(t_data *data)
{
	int		i;
	t_stack	*stack;

	i = 0;
	stack = NULL;
	if (check_args_syntax(data->tab) == 0)
	{
		set_error(CREATE_STACK_FAIL, data);
		return (NULL);
	}
	while (data->tab[i])
	{
		if (process_one_arg(&stack, data->tab[i], data) == 1)
		{
			free_stack(&stack);
			return (NULL);
		}
		i++;
	}
	return (finalize_stack(stack, data));
}
