/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_nodes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stmaire <stmaire@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 17:47:02 by stmaire           #+#    #+#             */
/*   Updated: 2026/01/06 11:58:43 by stmaire          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
//a remplacer apres par "push_swap.h" en modifiant le makefile(-I)

t_stack_node	*lstlast(t_stack_node *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
//fonction adaptee a la structure t_stack_node, 
//sinon c est la meme que ft_lstlast de la libft
}

void	append_node(t_stack_node **stack, int nb)
{
	t_stack_node	*node;
	t_stack_node	*last_node;

	if (!stack)
		return ;
	node = malloc(sizeof(t_stack_node));
	if (!node)
		return ;
	node->number = nb;
	node->next = NULL;
	//autres champs de la structure a initialiser!!!
	if (*stack == NULL) // cas 1 = la liste est vide
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
	//fonction qui malloc un nouveau noeud, 
	//met number->nb et initialise à 0 
	//tous les autres éléments de la structure, 
	//ce dernier point est a completer.
}
