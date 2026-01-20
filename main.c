#include "push_swap.h"
#include <stdio.h> 

static void	choose_method(int score)
{
	printf("le score calculé est de : %d\n\n", score); // adaptive
	if (score == 11 || score == 111 || score == 100)
		printf("the method will be \"adaptive\"\n"); // adaptive
	else if (score == 3 || score == 103)
		printf("the method will be \"simple\"\n"); // simple
	else if (score == 5 || score == 105)
		printf("the method will be \"medium\"\n"); // medium
	else if (score == 7 || score == 107)
		printf("the method will be \"complex\"\n"); // complex
	else
		printf("Error\n"); // print_error
	if (score == 100 || score == 111 || score == 103
			|| score == 105 || score == 107)
		printf("Benchmark will be visible\n"); // bench
}
// char *truncate(char *str)
// {
// 	char *str_without_flags;
// 	int	i;
// 	int	score;
	
// 	i = 0;
// 	score = flag_selector(str);
// 	if (score == -1)
// 		return(str);
// 	else 
// 	{
// 		on va au bout de la chaine
// 		on recule while str[i] != ' ' && str[i -1] != minuscule;
// 		str_without_flags = ft_strdup(str + i);
// 		free(str);
// 		return(str_without_flags);
// 	}

// }

int	main(int argc, char **argv)
{
	// t_stack_node	*stack_a;
	// t_stack_node	*stack_b;
	// char			**tab;
	char			*big_str;
	int				score;
	
	if (argc < 2)
		return (0);

	big_str = from_args_to_big_str(argc, argv);
	score = flag_selector(big_str);
	choose_method(score); // seulement apres les constructions des stacks parce qu on en a besoin	
	
	// big_str = truncate(big_str);
	// tab = put_args_in_array(big_str);
	
	//big_str peut-être a free plutôt ici?????
	// stack_a = NULL;
	// stack_b = NULL;
	// stack_a = build_stack(tab);
	// if (!stack_a)
	// 	return (1);
	// range_based_sort(&stack_a, &stack_b); 
	// free_stack(&stack_a);
	// free_stack(&stack_b);
	return (0);
}
