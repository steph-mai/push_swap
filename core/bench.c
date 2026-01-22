/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stmaire <stmaire@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 14:54:43 by marberge          #+#    #+#             */
/*   Updated: 2026/01/22 15:58:43 by stmaire          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	exec_and_count(char *move, t_bench *bench)
{
	ft_printf(1, "%s\n", move);
	bench->total_count++;
	if (ft_strcmp(move, "pa") == 0)
		bench->pa++;
	else if (ft_strcmp(move, "pb") == 0)
		bench->pb++;
	else if (ft_strcmp(move, "sa") == 0)
		bench->sa++;
	else if (ft_strcmp(move, "sb") == 0)
		bench->sb++;
	else if (ft_strcmp(move, "ss") == 0)
		bench->ss++;
	else if (ft_strcmp(move, "ra") == 0)
		bench->ra++;
	else if (ft_strcmp(move, "rb") == 0)
		bench->rb++;
	else if (ft_strcmp(move, "rr") == 0)
		bench->rr++;
	else if (ft_strcmp(move, "rra") == 0)
		bench->rra++;
	else if (ft_strcmp(move, "rrb") == 0)
		bench->rrb++;
	else if (ft_strcmp(move, "rrr") == 0)
		bench->rrr++;
}

static void	settle_strategy_class(t_bench *bench)
{
	if (ft_strcmp(bench->strategy, "Simple") == 0)
		bench->theory_class = "O(n²)";
	else if (ft_strcmp(bench->strategy, "Medium") == 0)
		bench->theory_class = "O(n√n)";
	else if (ft_strcmp(bench->strategy, "Complex") == 0)
		bench->theory_class = "O(n log n)";
}

static int	get_len(int n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

static char	*disorder_to_string(t_bench *bench)
{
	int		whole;
	int		dec;
	int		size;
	char	*str;
	char	*tmp;

	whole = (int)(bench->disorder);
	dec = (int)(((bench->disorder) - whole) * 100);
	size = get_len(whole) + 4;
	str = ft_calloc(size, sizeof(char));
	if (!str)
		return (NULL);
	tmp = ft_itoa(whole);
	ft_strlcpy(str, tmp, size);
	free(tmp);
	ft_strlcat(str, ".", size);
	if (dec < 10)
		ft_strlcat(str, "0", size);
	tmp = ft_itoa(dec);
	ft_strlcat(str, tmp, size);
	free(tmp);
	return (str);
}

void	bench_print(t_bench *bench)
{
	char	*res;

	res = disorder_to_string(bench);
	settle_strategy_class(bench);
	ft_printf(2, "[bench] disorder: %s%\n", res);
	ft_printf(2, "[bench] stategy: %s / ", bench->strategy);
	ft_printf(2, "%s\n", bench->theory_class);
	ft_printf(2, "[bench] total_ops: %d\n", bench->total_count);
	ft_printf(2, "[bench] sa: %d  sb: %d", bench->sa, bench->sb);
	ft_printf(2, " ss: %d  pa: %d  pb: %d\n", bench->ss, bench->pa, bench->pb);
	ft_printf(2, "[bench] ra: %d  rb: %d", bench->ra, bench->rb);
	ft_printf(2, " rr: %d  rra: %d", bench->rr, bench->rra);
	ft_printf(2, " rrb: %d  rrr: %d\n", bench->rrb, bench->rrr);
	free(res);
}
