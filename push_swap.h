/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marberge <marberge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 14:26:35 by stmaire           #+#    #+#             */
/*   Updated: 2026/01/13 18:39:57 by marberge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./lib/libft/libft.h"
# include "./lib/printf/includes/ft_printf.h"
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

//-------------------------------STRUCTURE-------------------------------
typedef struct s_stack_node
{
	/* data to complete */
	int					number;
	int					index;
	struct s_stack_node	*prev;
	struct s_stack_node	*next;
}						t_stack_node;

/* -------------------------------PARSING---------------------------------*/
//***build***/
char			**put_args_in_array(int argc, char **argv);
t_stack_node	*build_stack(char **tab);

//***check***/
int				check_args_syntax(char **tab);
int				check_args_overflow(long i);
int				check_args_doubles(t_stack_node *node, int nb_to_check);

//***free***/
void			free_tab(char **tab);
void			free_stack(t_stack_node **stack);
t_stack_node	*free_if_error(t_stack_node **stack, char **tab);

/* -----------------------------STACK_UTILS-------------------------------*/
t_stack_node	*lstlast(t_stack_node *lst);
int				lstsize(t_stack_node *lst);
void			append_node(t_stack_node **stack, int nb);
int				*sort_numbers(int *tab, int size);
void			find_index(t_stack_node *stack, int *tab, int size);
void			index_stack(t_stack_node *stack);

/* ----------------------------- CORE -------------------------------*/
float			compute_disorder(t_stack_node *a);

/* ----------------------------- CORE -------------------------------*/
void			swap(t_stack_node **head);

#endif