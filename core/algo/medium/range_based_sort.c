/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   range_based_sort.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stmaire <stmaire@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 09:35:15 by stmaire           #+#    #+#             */
/*   Updated: 2026/01/16 11:31:17 by stmaire          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
//#include <math.h> // TODO à enlever à remplacer par une fonction qui calcule la racine carrée
					// TODO supprimer em meme temps dans le Makefile -lm à la fin de la règle pour construire le $NAME

void	range_based_sort(t_stack_node **a, t_stack_node **b)
{
	long	size;
	long	i;
	long	range;
	int		position;
	
	size = lstsize(*a);
	i = 0;
	position = -1;
	range = sqrt(size);
	while (*a)
	{
		if ((*a)->index >= 0 && (*a)->index < range + i)
		{
			pb(a, b);
			i++;
		}
		else
			ra(a);
	}
	while (*b)
	{
		if ((*b) == find_max(*b) || (*b)->index == ((find_max(*b)->index) - 1))
		{
			pa(a, b);
			if ((*a)->index > (*a)->next->index)
				sa(a);
		}
		else
		{
			min_node = find_min(*a);
		position = get_position(*a, min_node);
		}
			
	}
	
}

// on compte le nombre d elements de la stack a = size
// on determine le range (racine de size)
// on met un incrementateur count a 0
// tant que a n est pas vide
// 	si index est compris dans range + i
// 		on pb 
// 		i++;
// 	sinon on ra	
// NB a la fin les nombres sont pre tries, grands au dessus, petits en dessous, moyens au milieu
// while (b)
// on regarde si head_b = index_max ou index_max - 1
// 	si oui 
// 		pa
// 		on verfie que head_a et head_a->next sont triees (s il y a plus dún element dans a)
// 			si pas triees 
// 				sa
// 	si non
// 		on regarde a quelle position se trouve index_max
// 			si index < size/2 (s il est encore de le haut de la pile) !!! recalculer size a chaque tour
// 				rb
// 			sinon index > size/2 ( s il est dans le bas de la pile)
// 				on le fait remonter avec des rrb
				
	
	