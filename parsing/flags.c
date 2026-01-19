/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marberge <marberge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 17:18:40 by marberge          #+#    #+#             */
/*   Updated: 2026/01/19 17:52:39 by marberge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	flag_selector(char *str)
{
	int	i;
	int	k;
	int	j;
	int	res;

	i = 0;
	res = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '-' && str[i + 1] == '-')
		{
			k = i + 2;
			while (str[k] != ' ' || str[k] != '\0')
			{
				if (str[k] < 97 && str[k] > 122)
					return (-1);
				k++;
			}
			if (k == 0)
				return (-1);
			res += compare_to_flag(str, i, k);
		}
		i++;
	}
}
