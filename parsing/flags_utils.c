/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stmaire <stmaire@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 23:08:33 by marberge          #+#    #+#             */
/*   Updated: 2026/01/26 09:28:06 by stmaire          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_digit(char c)
{
	return (c >= '0' && c <= '9');
}

int	skip_valid_number(char *str, int *i)
{
	if (str[*i] == '-' || str[*i] == '+')
		(*i)++;
	while (str[*i] >= '0' && str[*i] <= '9')
		(*i)++;
	if (str[*i] != ' ' && str[*i] != '\0')
		return (0);
	return (1);
}

int	process_flag_token(char *str, int *i)
{
	int	k;
	int	val;	

	k = *i;
	while (str[k] != ' ' && str[k] != '\0')
		k++;
	val = is_flag(str, *i, k);
	*i = k;
	return (val);
}
