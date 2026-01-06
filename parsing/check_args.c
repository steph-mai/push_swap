/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stmaire <stmaire@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/31 11:57:33 by stmaire           #+#    #+#             */
/*   Updated: 2026/01/06 11:53:05 by stmaire          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_args_syntax(char **tab)
{
	int	i;
	int	j;

	j = 0;
	while (tab[j])
	{
		i = 0;
		if (tab[j][i] == '+' || tab[j][i] == '-')
			i++;
		if (tab[j][i] == '\0')
			return (0);
		while (tab[j][i] != '\0')
		{
			if (tab[j][i] < '0' || tab[j][i] > '9')
				return (0);
			i++;
		}
		j++;
	}
	return (1);
}

int	check_args_overflow(long i)
{
	if (i < INT_MIN || i > INT_MAX)
		return (0);
	return (1);
}

int	check_args_doubles(t_stack_node *node, int nb_to_check)
{
	if (!node)
		return (1);
	while (node != NULL)
	{
		if (nb_to_check == node->number)
			return (0);
		node = node->next;
	}
	return (1);
}
