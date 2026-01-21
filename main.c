/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stmaire <stmaire@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 10:19:30 by stmaire           #+#    #+#             */
/*   Updated: 2026/01/21 14:57:27 by stmaire          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h> 

static void	choose_method(int score,t_stack_node **a, t_stack_node **b, t_bench *bench)
{
	// printf("le score calculé est de : %d\n\n", score); // adaptive
	if (score == 100 || score == 103 || score == 105 || score == 107 || score == 111)
		bench->active = 1;
	if (score == 11 || score == 111 || score == 100)
	{
		select_algo(a, b, bench);
		
	}
	else if (score == 3 || score == 103)
	{
		selection_sort(a, b, bench);
		bench->strategy = "simple";
	}
	else if (score == 5 || score == 105)
	{
		range_based_sort(a, b, bench);
		bench->strategy = "medium";
	}
	else if (score == 7 || score == 107)
	{
		radix_sort(a, b, bench);
		bench->strategy = "complex";
	}
	else
		printf("Error\n");
	if (bench->active == 1)
		printf("Benchmark visible\n");
}

static	char *ft_truncate(char *str)
{
	char	*str_without_flags;
	int		i;
	int		score;

	if (!str)
		return (NULL);
	score = flag_selector(str);
	if (score == -1)
		return (str);
	else
	{
		i = ft_strlen(str) - 1;
		while (i > 1)
		{
			if (str[i] == ' ' && (str[i -1] >= 97 && str[i - 1] <= 122))
			{
				str_without_flags = ft_strdup(str + i + 1);
				free(str);
				return (str_without_flags);
			}
			i--;
		}
		return (str);
	}
}

int	main(int argc, char **argv)
{
	t_stack_node	*stack_a;
	t_stack_node	*stack_b;
	char			**tab;
	char			*big_str;
	// int				score;
	t_bench			bench;
	
	ft_bzero(&bench, sizeof(t_bench));
	if (argc < 2)
		return (0);
	big_str = from_args_to_big_str(argc, argv);
	bench.score = flag_selector(big_str);
	big_str = ft_truncate(big_str);
	tab = put_args_in_array(big_str);
	stack_a = NULL;
	stack_b = NULL;
	stack_a = build_stack(tab);
	if (!stack_a)
		return (1);
	printf("désordre = %.2f\n", compute_disorder(stack_a, &bench));
	choose_method(bench.score, &stack_a, &stack_b, &bench);	
	printf("bench.desordre = %f\n", bench.disorder);
	printf("bench.total_count = %d\n", bench.total_count);
	printf("bench.sa = %d\n", bench.sa);
	printf("bench.pb = %d\n", bench.pb);
	printf("bench.ra = %d\n", bench.ra);
	printf("bench.strategy = %s\n", bench.strategy);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
