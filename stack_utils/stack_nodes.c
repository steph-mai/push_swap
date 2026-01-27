/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_nodes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marberge <marberge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 17:47:02 by stmaire           #+#    #+#             */
/*   Updated: 2026/01/27 18:25:28 by marberge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*lstlast(t_stack *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

int	lstsize(t_stack *lst)
{
	int		count;

	count = 0;
	while (lst)
	{
		count ++;
		lst = lst->next;
	}
	return (count);
}

void	append_node(t_stack **stack, int nb, t_data *data)
{
	t_stack	*node;
	t_stack	*last_node;

	if (!stack)
		return ;
	node = malloc(sizeof(t_stack));
	if (!node)
	{
		set_error(CREATE_STACK_FAIL, *data);
		return ;
	}
	node->number = nb;
	node->index = -1;
	node->next = NULL;
	if (*stack == NULL)
	{
		*stack = node;
		node->prev = NULL;
	}
	else
	{
		last_node = lstlast(*stack);
		last_node->next = node;
		node->prev = last_node;
	}
}

t_stack	*find_max(t_stack *stack)
{
	t_stack	*max_node;
	int		max_index;

	if (!stack)
		return (NULL);
	max_index = -1;
	while (stack)
	{
		if (stack->index > max_index)
		{
			max_index = stack->index;
			max_node = stack;
		}
		stack = stack->next;
	}
	return (max_node);
}

t_stack	*find_min(t_stack *stack)
{
	t_stack	*min_node;
	int		min_index;

	if (!stack)
		return (NULL);
	min_index = INT_MAX;
	while (stack)
	{
		if (stack->index < min_index)
		{
			min_index = stack->index;
			min_node = stack;
		}
		stack = stack->next;
	}
	return (min_node);
}
