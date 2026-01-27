/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_numbers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marberge <marberge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 08:41:27 by stmaire           #+#    #+#             */
/*   Updated: 2026/01/27 19:22:26 by marberge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	*sort_numbers(int *tab, int size)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	temp = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (tab[j] < tab[i])
			{
				temp = tab[i];
				tab[i] = tab[j];
				tab[j] = temp;
			}
			j++;
		}
		i++;
	}
	return (tab);
}

static void	find_index(t_stack *stack, int *tab, int size)
{
	t_stack	*ptr;
	int		i;

	ptr = stack;
	while (ptr)
	{
		i = 0;
		while (i < size)
		{
			if (ptr->number == tab[i])
			{
				ptr->index = i;
				break ;
			}
			i++;
		}
		ptr = ptr->next;
	}
}

void	index_stack(t_stack *stack, t_data *data)
{
	int		*tab;
	t_stack	*ptr;
	int		size;
	int		i;

	size = lstsize(stack);
	tab = malloc(sizeof(int) * size);
	if (!tab)
	{
		set_error(CREATE_STACK_FAIL, *data);
		return ;
	}
	ptr = stack;
	i = 0;
	while (ptr)
	{
		tab[i++] = ptr->number;
		ptr = ptr->next;
	}
	sort_numbers(tab, size);
	ptr = stack;
	find_index(stack, tab, size);
	free(tab);
}

int	get_position(t_stack *stack, t_stack *target_node)
{
	int	i;

	i = 0;
	while (stack)
	{
		if (stack == target_node)
			return (i);
		stack = stack->next;
		i++;
	}
	return (0);
}
