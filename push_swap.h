/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stmaire <stmaire@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 14:26:35 by stmaire           #+#    #+#             */
/*   Updated: 2026/01/22 11:41:28 by stmaire          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./lib/libft/libft.h"
# include "./lib/printf/includes/ft_printf.h"
# include <stdlib.h>
# include <limits.h>

//-------------------------------STRUCTURE-------------------------------
typedef struct s_stack
{
	int					number;
	int					index;
	struct s_stack		*prev;
	struct s_stack		*next;
}						t_stack;
typedef struct s_bench
{
	float	disorder;
	int		score;
	char	*strategy;
	char	*theory_class;
	int		total_count;
	int		sa;
	int		sb;
	int		ss;
	int		pa;
	int		pb;
	int		ra;
	int		rb;
	int		rr;
	int		rra;
	int		rrb;
	int		rrr;	
}			t_bench;

/* -------------------------------PARSING---------------------------------*/
//***build***/
char			*from_args_to_big_str(int argc, char **argv);
char			**put_args_in_array(char *big_str);
t_stack			*build_stack(char **tab);

//***check***/
int				check_args_syntax(char **tab);
int				check_args_overflow(long i);
int				check_args_doubles(t_stack *node, int nb_to_check);

//***free***/
void			free_tab(char **tab);
void			free_stack(t_stack **stack);
t_stack			*free_if_error(t_stack **stack, char **tab);

//***flags***/
int				flag_selector(char *str);
int				ft_strcmp(char *s1, char *s2);

/* -----------------------------STACK_UTILS-------------------------------*/
t_stack			*lstlast(t_stack *lst);
int				lstsize(t_stack *lst);
void			append_node(t_stack **stack, int nb);
int				*sort_numbers(int *tab, int size);
void			find_index(t_stack *stack, int *tab, int size);
void			index_stack(t_stack *stack);
t_stack			*find_max(t_stack *stack);
t_stack			*find_min(t_stack *stack);
int				get_position(t_stack *stack, t_stack *target);

/* ----------------------------- CORE -------------------------------*/
float			compute_disorder(t_stack *a);
void			three_sort(t_stack **stack_a, t_bench *bench);
/*------------  ALGO SIMPLE  ---------------*/
void			selection_sort(t_stack **a, t_stack **b, t_bench *bench);
void			insertion_sort(t_stack **a, t_stack **b, t_bench *bench);
/*------------  ALGO MEDIUM  ---------------*/
void			range_based_sort(t_stack **a, t_stack **b, t_bench *bench);
/*------------  ALGO COMPLEX  ---------------*/
void			radix_sort(t_stack **a, t_stack **b, t_bench *bench);
/*------------  ALGO ADAPTIVE  ---------------*/
void			select_algo(t_stack **a, t_stack **b, t_bench *bench);
/*------------  BENCH  ---------------*/
void			exec_and_count(char *move, t_bench *bench);
void			bench_print(t_bench *bench);

/* ----------------------------- OPERATIONS -------------------------------*/
/*------------  SWAP  ---------------*/
void			swap(t_stack **head);
void			sa(t_stack **head, t_bench *bench);
void			sb(t_stack **head, t_bench *bench);
void			ss(t_stack **head_a, t_stack **head_b, t_bench *bench);
/*------------  PUSH  ---------------*/
void			push(t_stack **dest, t_stack **src);
void			pa(t_stack **stack_a, t_stack **stack_b, t_bench *bench);
void			pb(t_stack **stack_a, t_stack **stack_b, t_bench *bench);
/*------------  ROTATE  ---------------*/
void			rotate(t_stack **head);
void			ra(t_stack **a, t_bench *bench);
void			rb(t_stack **b, t_bench *bench);
void			rrr(t_stack **a, t_stack **b, t_bench *bench);
/*------------  REVERSE ROTATE  ---------------*/
void			reverse_rotate(t_stack **head);
void			rra(t_stack **a, t_bench *bench);
void			rrb(t_stack **b, t_bench *bench);
void			rrr(t_stack **a, t_stack **b, t_bench *bench);

#endif