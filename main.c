/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stmaire <stmaire@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 10:19:30 by stmaire           #+#    #+#             */
/*   Updated: 2026/01/30 11:14:22 by stmaire          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	choose_method(int score, t_stack **a,
	t_stack **b, t_bench *bench)
{
	if (score == 11 || score == 111 || score == 100)
	{
		select_algo(a, b, bench);
		bench->strategy = "Adaptive";
	}
	else if (score == 3 || score == 103)
	{
		selection_sort(a, b, bench);
		bench->strategy = "Simple";
	}
	else if (score == 5 || score == 105)
	{
		range_based_sort(a, b, bench);
		bench->strategy = "Medium";
	}
	else if (score == 7 || score == 107)
	{
		radix_sort(a, b, bench);
		bench->strategy = "Complex";
	}
	else
		write(2, "Error\n", 6);
	if (score == 100 || score == 103 || score == 105
		|| score == 107 || score == 111)
		bench_print(bench);
}

static	char	*ft_truncate(char *str, t_data *data)
{
	char	*str_without_flags;
	int		i;

	if (!str)
	{
		set_error(TRUNCATE_FAIL, data);
		return (NULL);
	}
	i = 0;
	while (str[i] != '\0')
	{
		if (is_digit(str[i])
			|| ((str[i] == '-' || str[i] == '+') && is_digit(str[i + 1])))
		{
			str_without_flags = ft_strdup(str + i);
			free(str);
			if (!str_without_flags)
				set_error(TRUNCATE_FAIL, data);
			return (str_without_flags);
		}
		i++;
	}
	free(str);
	set_error(NO_NUMBER, data);
	return (NULL);
}

static void	init_and_parse(int argc, char **argv, t_data *data, t_bench *bench)
{
	ft_bzero(bench, sizeof(t_bench));
	ft_bzero(data, sizeof(t_data));
	data->error_id = from_args_to_big_str(argc, argv, data);
	check_err(data->error_id, data, NULL, NULL);
	bench->score = flag_selector(data);
	data->big_str = ft_truncate(data->big_str, data);
	check_err(data->error_id, data, NULL, NULL);
	data->tab = put_args_in_array(data);
	check_err(data->error_id, data, NULL, NULL);
}

int	main(int argc, char **argv)
{
	t_stack		*stack_a;
	t_stack		*stack_b;
	t_data		data;
	t_bench		bench;

	if (argc < 2)
		return (0);
	stack_a = NULL;
	stack_b = NULL;
	init_and_parse(argc, argv, &data, &bench);
	stack_a = build_stack(&data);
	check_err(data.error_id, &data, &stack_a, &stack_b);
	bench.disorder = compute_disorder(stack_a);
	if (bench.disorder == 0.00)
		check_err(ALREADY_SORTED, &data, &stack_a, &stack_b);
	choose_method(bench.score, &stack_a, &stack_b, &bench);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
