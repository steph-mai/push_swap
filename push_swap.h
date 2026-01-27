/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marberge <marberge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 14:26:35 by stmaire           #+#    #+#             */
/*   Updated: 2026/01/27 19:22:23 by marberge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./lib/libft/libft.h"
# include "./lib/printf/includes/ft_printf.h"
# include <stdlib.h>
# include <limits.h>

//-------------------------------STRUCTURE-------------------------------
typedef enum e_error
{
    NO_ERROR = 0,       // Tout va bien
	NO_ARGS = 1,
    BIG_STR_FAIL = 2,   // Erreur allocation chaine géante
	FLAG_ERROR = 3,
	TUNCATE_FAIL = 4,
    TAB_FAIL = 5,       // Erreur allocation tableau d'entiers
    CREATE_STACK_FAIL = 6, // Erreur création de la stack
	ALREADY_SORTED = 7
}			t_error;

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

typedef struct s_data
{
	char		**tab;
	char		*big_str;
	t_error		error_id;
}			t_data;

/* -------------------------------PARSING---------------------------------*/
//***build***/
t_error			from_args_to_big_str(int argc, char **argv, t_data *data);
char			**put_args_in_array(t_data *data);
t_stack			*build_stack(t_data *data);

//***check***/
int				check_args_syntax(char **tab);
int				check_args_overflow(long i);
int				check_args_doubles(t_stack *node, int nb_to_check);

//***free***/
void			free_tab(char **tab);
void			free_stack(t_stack **stack);
t_stack			*free_if_error(t_stack **stack, char **tab);
int				check_err(t_error err, t_data *data, t_stack **a, t_stack **b);
t_error			set_error(t_error id_of_error, t_data data);

//***flags***/
int				flag_selector(t_data *data);
int				ft_strcmp(char *s1, char *s2);
int				is_digit(char c);
int				skip_valid_number(char *str, int *i);
int				process_flag_token(char *str, int *i);
int				is_flag(char *str, int start, int end);

/* -----------------------------STACK_UTILS-------------------------------*/
t_stack			*lstlast(t_stack *lst);
int				lstsize(t_stack *lst);
void			append_node(t_stack **stack, int nb, t_data *data);
void			index_stack(t_stack *stack, t_data *data);
t_stack			*find_max(t_stack *stack);
t_stack			*find_min(t_stack *stack);
int				get_position(t_stack *stack, t_stack *target);

/* ----------------------------- CORE -------------------------------*/
float			compute_disorder(t_stack *a);
void			three_sort(t_stack **stack_a, t_bench *bench);
/*------------  ALGO SIMPLE  ---------------*/
void			selection_sort(t_stack **a, t_stack **b, t_bench *bench);
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
void			sa(t_stack **head, t_bench *bench);
void			sb(t_stack **head, t_bench *bench);
void			ss(t_stack **head_a, t_stack **head_b, t_bench *bench);
/*------------  PUSH  ---------------*/
void			pa(t_stack **stack_a, t_stack **stack_b, t_bench *bench);
void			pb(t_stack **stack_a, t_stack **stack_b, t_bench *bench);
/*------------  ROTATE  ---------------*/
void			ra(t_stack **a, t_bench *bench);
void			rb(t_stack **b, t_bench *bench);
void			rrr(t_stack **a, t_stack **b, t_bench *bench);
/*------------  REVERSE ROTATE  ---------------*/
void			rra(t_stack **a, t_bench *bench);
void			rrb(t_stack **b, t_bench *bench);
void			rrr(t_stack **a, t_stack **b, t_bench *bench);

#endif