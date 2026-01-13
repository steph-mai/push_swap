/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marberge <marberge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 12:33:01 by marberge          #+#    #+#             */
/*   Updated: 2025/12/08 19:52:42 by marberge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stddef.h>
# include <stdlib.h>

# define BUFFER_SIZE 1024

int		ft_printf(const char *str, ...);
int		ft_manage_sign(char c, char *buffer, int *buf_index, va_list args);
int		ft_add_char(char *buffer, int *buf_index, char char_to_add);
int		ft_add_to_buffer(char *buffer, int *buf_index, char *str_to_add);
int		ft_add_number(char *buffer, int *buf_index, int nb);
int		ft_add_address(char *buffer, int *buf_index, void *ptr, int is_lower);
int		ft_add_hexa(char *buffer, int *buf_index, unsigned int nb, int is_lwr);
int		ft_parsing(const char *str, char *buffer, int *buf_index, va_list args);
int		ft_flush_buffer(char *buffer, int *buf_index);
size_t	ft_strlen(const char *s);
char	*ft_itoa(int n);
char	*ft_unsigned_itoa(unsigned int n);
char	*ft_itoa_base(unsigned long n, int is_lowercase);
void	ft_bzero(void *s, size_t n);

#endif
