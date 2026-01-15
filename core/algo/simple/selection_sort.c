/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selection_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marberge <marberge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 09:11:56 by stmaire           #+#    #+#             */
/*   Updated: 2026/01/15 18:34:47 by marberge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_position(t_stack_node *stack, t_stack_node *target_node)
{
	long	i;

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

void	selection_sort(t_stack_node **a, t_stack_node **b)
{
	long			size;
	t_stack_node	*min_node;
	long			position;

	size = lstsize(*a);
	while (size > 3)
	{
		min_node = find_min(*a);
		position = get_position(*a, min_node);
		if (position <= size / 2)
		{
			while (*a != min_node)
				ra(a);
		}
		else
		{
			while (*a != min_node)
				rra(a);
		}
		pb(a, b);
		size--;
	}
	three_sort(a);
	while (*b)
		pa(a, b);
}
// je calcule la longueur de la pile a
// tant que cette longueur > 3
// 	je determine l index le plus petit
// 	je le cherche 
// 		s il est dans la moitie haute de la pile 
// 			je le fais remonter avec des ra jusqu ce qu il soit tout en haut
// 		s il est dans la moitie basse de la pile
// 			je fais rra jusqu a ce qu il soit en haut de la pile 
// 			je le pushe sur b avec pb
// je trie les 3 qui restent dans a avec three_sort
// je pa toute la stack b 
// c est trié
