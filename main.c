/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marberge <marberge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 10:19:30 by stmaire           #+#    #+#             */
/*   Updated: 2026/01/27 12:36:06 by marberge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// static void	choose_method(int score, t_stack **a,
// 	t_stack **b, t_bench *bench)
// {
// 	if (score == 11 || score == 111 || score == 100)
// 	{
// 		select_algo(a, b, bench);
// 		bench->strategy = "Adaptive";
// 	}
// 	else if (score == 3 || score == 103)
// 	{
// 		selection_sort(a, b, bench);
// 		bench->strategy = "Simple";
// 	}
// 	else if (score == 5 || score == 105)
// 	{
// 		range_based_sort(a, b, bench);
// 		bench->strategy = "Medium";
// 	}
// 	else if (score == 7 || score == 107)
// 	{
// 		radix_sort(a, b, bench);
// 		bench->strategy = "Complex";
// 	}
// 	else
// 		ft_printf(2, "Error\n");
// 	if (score == 100 || score == 103 || score == 105
// 		|| score == 107 || score == 111)
// 		bench_print(bench);
// }

// static	char	*ft_truncate(char *str, t_bench *bench)
// {
// 	char	*str_without_flags;
// 	int		i;

// 	if (!str)
// 		return (NULL);
// 	if (bench->score == -1)
// 		return (str);
// 	else
// 	{
// 		i = 0;
// 		while (str[i] != '\0')
// 		{
// 			if (is_digit(str[i])
// 				|| ((str[i] == '-' || str[i] == '+') && is_digit(str[i + 1])))
// 			{
// 				str_without_flags = ft_strdup(str + i);
// 				free(str);
// 				return (str_without_flags);
// 			}
// 			i++;
// 		}
// 		free(str);
// 		exit(0);
// 	}
// }

int	main(int argc, char **argv)
{
	t_stack		*stack_a;
	t_stack		*stack_b;
	t_data		data;
	t_bench		bench;

	ft_bzero(&bench, sizeof(t_bench));
	ft_bzero(&data, sizeof(t_data));
	if (argc < 2)
		return (0);
	stack_a = NULL;
	stack_b = NULL;

	data.error_id = from_args_to_big_str(argc, argv, &data);
	if (data.error_id != NO_ERROR)
		return (free_exit(&data, &bench, &stack_a, &stack_b));
	else {
		ft_printf(1, "Tout va bien\n");
	}
	// bench.score = flag_selector(data);
	// data.big_str = ft_truncate(data, &bench);
	// data.tab = put_args_in_array(data);
	// stack_a = build_stack(data);
	// if (!stack_a)
	// 	return (1);
	// bench.disorder = compute_disorder(stack_a);
	// if (bench.disorder == 0.00)
	// 	return (0);
	// choose_method(bench.score, &stack_a, &stack_b, &bench);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
