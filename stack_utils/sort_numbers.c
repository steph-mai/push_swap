/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_numbers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stmaire <stmaire@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 08:41:27 by stmaire           #+#    #+#             */
/*   Updated: 2026/01/12 10:50:28 by stmaire          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	*sort_numbers(int *tab, int size)
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

void	find_index(t_stack_node *stack, int *tab, int size)
{
	t_stack_node	*ptr;
	int				i;

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

void	index_stack(t_stack_node *stack)
{
	int					*tab;
	t_stack_node		*ptr;
	int					size;
	int					i;

	size = lstsize(stack);
	tab = malloc(sizeof(int) * size);
	if (!tab)
		return ;
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
