/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stmaire <stmaire@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 08:55:24 by stmaire           #+#    #+#             */
/*   Updated: 2026/01/22 16:04:03 by stmaire          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push(t_stack **dest, t_stack **src)
{
	t_stack	*node_to_push;

	if (!src || !*src || !dest)
		return ;
	node_to_push = *src;
	*src = node_to_push->next;
	if (*src)
		(*src)->prev = NULL;
	node_to_push->prev = NULL;
	if (!*dest)
	{
		*dest = node_to_push;
		node_to_push->next = NULL;
	}
	else
	{
		node_to_push->next = *dest;
		(*dest)->prev = node_to_push;
		*dest = node_to_push;
	}
	return ;
}

void	pa(t_stack **stack_a, t_stack **stack_b, t_bench *bench)
{
	push(stack_a, stack_b);
	exec_and_count("pa", bench);
	return ;
}

void	pb(t_stack **stack_a, t_stack **stack_b, t_bench *bench)
{
	push(stack_b, stack_a);
	exec_and_count("pb", bench);
	return ;
}
