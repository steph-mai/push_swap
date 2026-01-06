/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stmaire <stmaire@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/31 12:03:57 by stmaire           #+#    #+#             */
/*   Updated: 2026/01/06 11:56:32 by stmaire          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_tab(char **tab)
// pour liberer tab quand la liste chaînee est construite
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

void	free_stack(t_stack_node **stack)
//pour liberer la liste chainee en cas d erreur dans les arguments
{
	t_stack_node	*temp;
	t_stack_node	*current;

	if (!stack || !*stack)
	//si l'etiquette avec l adresse n 'existe pas ou si cette adresse est nulle
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

t_stack_node	*free_if_error(t_stack_node **stack, char **tab)
{
	//en cas d'erreur, s'ils existent, 
	//libere stack et tab et ecrit un message d'erreur
	write(2, "Error\n", 6);
	free_tab(tab);
	free_stack(stack);
	return (NULL);
}
