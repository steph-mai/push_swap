/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marberge <marberge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 15:11:15 by marberge          #+#    #+#             */
/*   Updated: 2026/01/21 14:32:57 by marberge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_add_to_buffer(char *buffer, int *buf_index, char *str_to_add)
{
	int	i;
	int	added;

	if (!buffer || !buf_index)
		return (0);
	if (!str_to_add)
		str_to_add = "(null)";
	i = 0;
	added = 0;
	while (str_to_add[i])
	{
		if (*buf_index + 1 >= BUFFER_SIZE)
		{
			if (ft_flush_buffer(buffer, buf_index, 1) == -1)
				return (-1);
		}
		buffer[*buf_index] = str_to_add[i];
		(*buf_index)++;
		buffer[*buf_index] = '\0';
		i++;
		added++;
	}
	return (added);
}

int	ft_add_char(char *buffer, int *buf_index, char char_to_add)
{
	if (!buffer || !buf_index)
		return (0);
	if (*buf_index + 1 >= BUFFER_SIZE)
	{
		if (ft_flush_buffer(buffer, buf_index, 1) == -1)
			return (-1);
	}
	buffer[*buf_index] = char_to_add;
	(*buf_index)++;
	buffer[*buf_index] = '\0';
	return (1);
}

int	ft_add_number(char *buffer, int *buf_index, int nb)
{
	char	*str;
	int		len;

	str = ft_itoa(nb);
	if (!str)
		return (0);
	len = ft_add_to_buffer(buffer, buf_index, str);
	free(str);
	return (len);
}

int	ft_add_address(char *buffer, int *buf_index, void *ptr, int is_lower)
{
	char			*str;
	int				prefix;
	int				len;
	unsigned long	ptr_as_ulong;

	prefix = 0;
	if (!ptr)
		len = ft_add_to_buffer(buffer, buf_index, "(nil)");
	else
	{
		ptr_as_ulong = (unsigned long)ptr;
		str = ft_itoa_base(ptr_as_ulong, is_lower);
		if (!str)
			return (0);
		prefix = ft_add_to_buffer(buffer, buf_index, "0x");
		len = ft_add_to_buffer(buffer, buf_index, str);
		if (len == -1 || prefix == -1)
		{
			free(str);
			return (-1);
		}
		free(str);
	}
	return (len + prefix);
}

int	ft_add_hexa(char *buffer, int *buf_index, unsigned int nb, int is_lwr)
{
	char			*str;
	int				len;
	unsigned long	uint_as_ulong;

	uint_as_ulong = (unsigned long)nb;
	str = ft_itoa_base(uint_as_ulong, is_lwr);
	if (!str)
		return (0);
	len = ft_add_to_buffer(buffer, buf_index, str);
	free(str);
	return (len);
}
