/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hazefury <hazefury@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 17:15:51 by hazefury          #+#    #+#             */
/*   Updated: 2026/01/16 18:08:34 by hazefury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int get_max_bits(int max_num)
{
	int max_bits;

	max_bits = 0;
	// Tant que max_num n'est pas réduit à 0
	while ((max_num >> max_bits) != 0)
	{
		max_bits++;
	}
	return (max_bits);
}

void radix_sort(t_stack_node **a, t_stack_node **b)
{
	int bit_max;
	int stack_len;
	int i;
	int k;
	t_stack_node *current_node;

	current_node = find_max(*a);
	stack_len = lstsize(*a);
	bit_max = get_max_bits(current_node->index);
	i = 0;
	k = 0;
	while (i < bit_max)
	{
		while (k < stack_len)
		{
			current_node = *a;
			if (((current_node->index >> i) & 1) == 1)
				ra(a);
			else
				pb(a, b);
			k++;
		}
		while (*b)
			pa(a, b);
		i++;
		k = 0;
	}
}

/*
PSEUDO CODE :

int LONGEUR_BIT_MAX = TROUVER_BIT_MAX(TROUVER_INDEX_MAX(PILE A))
int i = 0
MA_PILE_TYPE *NOEUD_COURANT;

TANT QUE (désorde de la pile A != 0.00)
{
	NOEUD_COURANT = *PILE A

}

*/