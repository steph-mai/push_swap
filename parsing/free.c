/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marberge <marberge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/31 12:03:57 by stmaire           #+#    #+#             */
/*   Updated: 2026/01/27 19:16:01 by marberge         ###   ########.fr       */
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

t_error	set_error(t_error id_of_error, t_data data)
{
	if (!id_of_error)
		return (-1);
	data.error_id = id_of_error;
	return (id_of_error);
}

int	check_err(t_error err, t_data *data, t_stack **a, t_stack **b)
{
	if (err == NO_ERROR)
		return (0);
	if (err == NO_ARGS)
		exit(EXIT_SUCCESS);
	ft_printf(2, "Error\n");
	if (err == BIG_STR_FAIL)
		exit(EXIT_FAILURE);
	if (err == FLAG_ERROR || err == TUNCATE_FAIL || err == TAB_FAIL 
		|| err == CREATE_STACK_FAIL || err == ALREADY_SORTED)
		free(data->big_str);
	if (err == TAB_FAIL || err == CREATE_STACK_FAIL || err == ALREADY_SORTED)
		free(data->tab);
	if (err == CREATE_STACK_FAIL || err == ALREADY_SORTED)
	{
		free_stack(a);
		free_stack(b);
	}
	exit(EXIT_FAILURE);
}
