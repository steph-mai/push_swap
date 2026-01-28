/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steph <steph@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 14:36:44 by stmaire           #+#    #+#             */
/*   Updated: 2026/01/28 15:59:35 by steph            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	*append_arg_with_space(char *s, char *arg)
{
	char	*temp;

	temp = ft_strjoin(s, arg);
	free(s);
	if (!temp)
		return (NULL);
	s = temp;
	temp = ft_strjoin(s, " ");
	free(s);
	return (temp);
}

t_error	from_args_to_big_str(int argc, char **argv, t_data *data)
{
	char	*s;
	int		i;

	if (argc < 2)
		return (set_error(NO_ARGS, data));
	i = 1;
	s = ft_strdup("");
	if (!s)
		return (set_error(BIG_STR_FAIL, data));
	while (i < argc)
	{
		s = append_arg_with_space(s, argv[i]);
		if (!s)
			return (set_error(BIG_STR_FAIL, data));
		i++;
	}
	data->big_str = s;
	return (NO_ERROR);
}

char	**put_args_in_array(t_data *data)
{
	char	**tab;

	if (!data->big_str)
	{
		set_error(TAB_FAIL, data);
		return (NULL);
	}
	tab = ft_split(data->big_str, ' ');
	if (!tab)
	{
		set_error(TAB_FAIL, data);
		return (NULL);
	}
	free(data->big_str);
	data->big_str = NULL;
	return (tab);
}
