/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stmaire <stmaire@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/31 12:03:57 by stmaire           #+#    #+#             */
/*   Updated: 2026/02/02 10:23:09 by stmaire          ###   ########.fr       */
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

t_error	set_error(t_error id_of_error, t_data *data)
{
	if (!id_of_error)
		return (-1);
	data->error_id = id_of_error;
	return (id_of_error);
}

static void	clean_and_exit(t_data *data, t_stack **a, t_stack **b, int code)
{
	if (data && data->big_str)
		free(data->big_str);
	if (data && data->tab)
		free_tab(data->tab);
	if (a && *a)
		free_stack(a);
	if (b && *b)
		free_stack(b);
	exit(code);
}

int	check_err(t_error err, t_data *data, t_stack **a, t_stack **b)
{
	if (err == NO_ERROR)
		return (0);
	if (err == NO_ARGS)
		exit(EXIT_SUCCESS);
	if (err == ALREADY_SORTED)
		clean_and_exit(data, a, b, EXIT_SUCCESS);
	write(2, "Error\n", 6);
	clean_and_exit(data, a, b, EXIT_FAILURE);
	return (1);
}
