/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stmaire <stmaire@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/31 12:03:57 by stmaire           #+#    #+#             */
/*   Updated: 2026/01/22 16:51:24 by stmaire          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	if (!tab)
		return ;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

void	free_stack(t_stack **stack)
{
	t_stack	*temp;
	t_stack	*current;

	if (!stack || !*stack)
		return ;
	current = *stack;
	while (current != NULL)
	{
		temp = current->next;
		free(current);
		current = temp;
	}
	*stack = NULL;
}

t_stack	*free_if_error(t_stack **stack, char **tab)
{
	ft_printf(2, "Error\n");
	free_tab(tab);
	free_stack(stack);
	return (NULL);
}
