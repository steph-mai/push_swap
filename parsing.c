/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stmaire <stmaire@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 14:36:44 by stmaire           #+#    #+#             */
/*   Updated: 2025/12/30 17:39:26 by stmaire          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char **free_and_return(char **tab, int	index)
{
	int	i;
	
	i = 0;
	while(i < index)
	{
		free (tab[i]);
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
			return (free_and_return(tab, i - 1));
		i++;
	}
	tab[i - 1] = NULL;
	return (tab);		
}
int	check_args_syntax(char **tab)
{
	int	i;
	int	j;

	j = 0;
	while(tab[j])
	{
		i = 0;
		if (tab[j][i] == '+' || tab[j][i] == '-')
			i++;
		if (tab[j][i] == '\0')
			return (0);
		while(tab[j][i] != '\0')
		{
			if (tab[j][i] < '0' || tab[j][i] > '9')
				return (0);
			i++;
		}
		j++;		
	}
	return (1);
}	
int check_args_overflow(long i)
//verifie si < INT_MIN || > INT_MAX)
//renvoie 0 si erreur / 1 si correct

int	check_args_doubles(t_stack_node *head, int nb_to_check)
//verifie la presence de doublons une fois les chaines tab[i] transformees en entiers et integrees aux noeuds
//si doublons (return 0);
//1 si correct

t_stack_node	*build_stack(char **tab)
{
	//si check_args_syntax == 0 > ecris un message d'erreur
	//while (tab[i]) :
		//tansforme tab[i] en long (atol : ascii to long)
		//verifie check_args_averflow et check_args_doubles
		//ecris un message d'erreur sur fd = 2 si besoin et free tous les noeuds deja crees
		//cree un noeud en castant le long en int
	//renvoyer un pointeur sur le premier noeud de la liste
}


