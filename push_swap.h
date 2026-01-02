/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stmaire <stmaire@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 14:26:35 by stmaire           #+#    #+#             */
/*   Updated: 2025/12/31 13:13:20 by stmaire          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define	PUSH_SWAP_H

#include "libft/libft.h"
#include "printf/ft_printf.h"
#include <unistd.h>
#include <stdlib.h>
#include <limits.h>

//-------------------------------STRUCTURE-------------------------------
typedef struct s_stack_node
{
	/* data to complete */
	int					number;
	struct s_stack_node	*prev;
	struct s_stack_node	*next;
}						t_stack_node;
/* -------------------------------PARSING---------------------------------*/
//***build***/
char			**put_args_in_array(int argc, char **argv);
t_stack_node	*build_stack(char **tab);
//***check***/
int				check_args_syntax(char **tab);
int 			check_args_overflow(long i);
int				check_args_doubles(t_stack_node *node, int nb_to_check);
//***free***/
t_stack_node 	*free_if_error(t_stack_node *stack,char **tab);

#endif