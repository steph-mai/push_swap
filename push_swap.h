/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stmaire <stmaire@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 14:26:35 by stmaire           #+#    #+#             */
/*   Updated: 2026/01/15 15:12:09 by stmaire          ###   ########.fr       */
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
t_stack_node    *find_max(t_stack_node *stack);
t_stack_node    *find_min(t_stack_node *stack);

/* ----------------------------- CORE -------------------------------*/
float			compute_disorder(t_stack_node *a);
void			three_sort(t_stack_node **stack_a);
void			simple_algo(t_stack_node **a, t_stack_node **b);

/* ----------------------------- OPERATIONS -------------------------------*/
/*------------  SWAP  ---------------*/
void			swap(t_stack_node **head);
void			sa(t_stack_node **head);
void			sb(t_stack_node **head);
void			ss(t_stack_node **head_a, t_stack_node **head_b);
/*------------  PUSH  ---------------*/
void			push(t_stack_node **dest, t_stack_node **src);
void			pa(t_stack_node **stack_a, t_stack_node **stack_b);
void			pb(t_stack_node **stack_a, t_stack_node **stack_b);
/*------------  ROTATE  ---------------*/
void			rotate(t_stack_node **head);
void			ra(t_stack_node **a);
void			rb(t_stack_node **b);
void			rrr(t_stack_node **a, t_stack_node **b);
/*------------  REVERSE ROTATE  ---------------*/
void			reverse_rotate(t_stack_node **head);
void			rra(t_stack_node **a);
void			rrb(t_stack_node **b);
void			rrr(t_stack_node **a, t_stack_node **b);


#endif