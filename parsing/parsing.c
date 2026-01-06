/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stmaire <stmaire@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 14:36:44 by stmaire           #+#    #+#             */
/*   Updated: 2026/01/06 11:50:25 by stmaire          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static long	ft_atol(char *s)
{
	long	nb;
	size_t	i;
	int		neg;
	//sert a transformer chaque string de **tab en long
	//(pas en int pour eviter les pb d'overflow)
	//on verifiera les eventuels depassements dans la fonction build_stack
	nb = 0;
	i = 0;
	neg = 0;
	while ((s[i] >= 9 && s[i] <= 13) || s[i] == 32)
		i++;
	if (s[i] == '-' || s[i] == '+')
	{
		if (s[i] == '-')
			neg = 1;
		i++;
	}
	while (s[i] >= '0' && s[i] <= '9')
	{
		nb = nb * 10 + s[i] - '0';
		i++;
	}
	if (neg == 1)
		nb = -nb;
	return (nb);
}

static char	**free_tab_and_return(char **tab, int index)
//en cas de pb de malloc lors de la construction du tableau, 
//on libere tt ce qui existe deja
//(comme dans le split!)
{
	int	i;

	i = 0;
	while (i < index)
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
	//gere les deux types d arguments : un seul entre guillemets qu on split 
	//ou plusieurs arguments separes
	//on met les strings dans un tableau
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
//on construit la liste chainee en transformant chaque chaine en entier 
//apres verif de sa validite
{
	int				i;
	long			nb;
	t_stack_node	*stack;

	i = 0;
	stack = NULL;
	if (check_args_syntax(tab) == 0)
		return (free_if_error(&stack, tab));
	while (tab[i])
	{
		nb = ft_atol (tab[i]);
		if (check_args_overflow(nb) == 0
			|| check_args_doubles(stack, (int)nb) == 0)
			return (free_if_error(&stack, tab));
		append_node(&stack, (int)nb);
		i++;
	}
	free_tab(tab);
	return (stack);
}
