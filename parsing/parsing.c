/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stmaire <stmaire@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 14:36:44 by stmaire           #+#    #+#             */
/*   Updated: 2025/12/31 13:00:20 by stmaire          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static long	ft_atol(char *s)
{
	//fonction qui transforme +/- nombre en long avant verification overflow
}

static void append_node(t_stack_node **stack, (int)nb)
{
	//fonction qui malloc un nouveau noeud, met number->nb et initialise à 0 
	//tous les autres éléments de la structure
}


static char **free_tab_and_return(char **tab, int index)
{
	int	i;
	
	i = 0;
	while(i < index)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return (NULL);
}

char	**put_args_in_array(int argc, char **argv)
{
	char	**tab;
	int		i;
	
	if (argc < 2)
		return (NULL);
	if (argc == 2)
		return (ft_split(argv[1], ' '));
	tab = malloc(sizeof(char *) * argc);
	if (!tab)
		return (NULL);
	i = 1;
	while (i < argc)
	{
		tab[i - 1] = ft_strdup(argv[i]);
		if (!tab[i - 1])
			return (free_tab_and_return(tab, i - 1));
		i++;
	}
	tab[i - 1] = NULL;
	return (tab);		
}

t_stack_node	*build_stack(char **tab)
{
	int				i;
	long			nb;
	t_stack_node	*stack;
		
	i = 0;
	stack = NULL;
	if (check_args_syntax(tab) == 0)
		return(free_if_error(&stack, tab));
	while (tab[i])
	{
		nb = ft_atol(tab[i]);
		if (check_args_overflow(nb) == 0 || check_args_doubles(stack, (int)nb) == 0)
			return(free_if_error(&stack, tab));
		append_node(&stack, (int)nb);
		i++;
	}
		free_tab(tab);
		return (stack);
}

