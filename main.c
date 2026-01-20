#include "push_swap.h"
#include <stdio.h> // #TODO: a retirer

/* Fonction de debug temporaire.
   Elle parcourt la liste et affiche chaque nombre.
*/
// static void	print_stack(t_stack_node *stack)
// {
// 	//ft_printf("\n--- VISUALISATION STACK ---\n");
// 	if (!stack)
// 	{
// 		ft_printf("(La pile est vide)\n");
// 		return ;
// 	}
// 	while (stack)
// 	{
// 		ft_printf("  %d\t|   %d\n", stack->index, stack->number);
// 		stack = stack->next;
// 	}
// 	ft_printf("-----------------------------\n\n");
// }

static void	choose_method(int score)
{
		if (score == 11 || score == 111 || score == 100)
			printf("the method will be \"adaptive\""); // adaptive
		else if (score == 3 || score == 103)
			printf("the method will be \"simple\""); // simple
		else if (score == 5 || score == 105)
			printf("the method will be \"medium\""); // medium
		else if (score == 7 || score == 107)
			printf("the method will be \"complex\""); // complex
		else
			printf("Error\n"); // print_error
		if (score == 100 || score == 111 || score == 103
			|| score == 105 || score == 107)
			printf("Benchmark will be visible"); // bench
}


int	main(int argc, char **argv)
{
	t_stack_node	*stack_a;
	t_stack_node	*stack_b;
	char			**tab;
	// t_stack_node	*node_max;
	// t_stack_node	*node_min;
	// long			size;


	// 1. Si aucun argument n'est donné, le programme doit rendre le prompt sans rien afficher
	if (argc < 2)
		return (0);

/*	-----------	PSEUDO CODE ---------------

	str = bigstr

	fonction flag(big str)
	truncate(bigstr)

	tab = put_args_in_array(bigstr);
*/

	// 2. Parsing des arguments
	tab = put_args_in_array(argc, argv);

	// 3. Construction de la stack
	// Note : Si build_stack échoue (erreur de syntaxe/overflow), 
	// elle a déjà affiché "Error", free tout, et renvoyé NULL.
	stack_a = NULL;
	stack_b = NULL;
	stack_a = build_stack(tab);

	// Si stack_a est NULL, c'est qu'il y a eu une erreur, on arrête.
	if (!stack_a)
		return (1);

	//4. TEST : On affiche le résultat
	// printf("********** STACK A AVANT LE TRI **********\n");
	// print_stack(stack_a);
	// printf("********** STACK B AVANT LE TRI **********\n");
	// print_stack(stack_b);
	// size = lstsize(stack_a);
	// printf("size de la stack a = %ld\n", size);
	// printf("disorder = %.2f\n\n", compute_disorder(stack_a));
    // node_max = find_max(stack_a);
	// printf("*********** la VALEUR MAX de la stack a ************\n");
	// printf("adresse du node_max = %p\n", node_max);
    // printf("index_max = %u\n", node_max->index);
    // printf("value_max = %d\n", node_max->number);
	// printf("*********** la VALEUR MIN de la stack a ************\n");
	// node_min = find_min(stack_a);
    // printf("node_min = %p\n", node_min);
    // printf("index_min = %u\n", node_min->index);
    // // printf("value_min = %d\n", node_min->number);
	range_based_sort(&stack_a, &stack_b); 
	// printf("********** STACK A APRES LE TRI **********\n");
	// print_stack(stack_a);
	// printf("********** STACK B APRES LE TRI **********\n");
	// print_stack(stack_b);
	free_stack(&stack_a);
	free_stack(&stack_b);

	return (0);
}
