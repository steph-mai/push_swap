#include "push_swap.h"

/* Fonction de debug temporaire.
   Elle parcourt la liste et affiche chaque nombre.
*/
static void	print_stack(t_stack_node *stack)
{
	ft_printf("\n--- VISUALISATION STACK A ---\n");
	if (!stack)
	{
		ft_printf("(La pile est vide)\n");
		return ;
	}
	while (stack)
	{
		ft_printf("  %d\t|   %d\n", stack->index, stack->number);
		stack = stack->next;
	}
	ft_printf("-----------------------------\n\n");
}

int	main(int argc, char **argv)
{
	t_stack_node	*stack_a;
	char			**tab;

	// 1. Si aucun argument n'est donné, le programme doit rendre le prompt sans rien afficher
	if (argc < 2)
		return (0);

	// 2. Parsing des arguments
	tab = put_args_in_array(argc, argv);
	
	// 3. Construction de la stack
	// Note : Si build_stack échoue (erreur de syntaxe/overflow), 
	// elle a déjà affiché "Error", free tout, et renvoyé NULL.
	stack_a = build_stack(tab);

	// Si stack_a est NULL, c'est qu'il y a eu une erreur, on arrête.
	if (!stack_a)
		return (1);

	// 4. TEST : On affiche le résultat
	print_stack(stack_a);

	// 5. Nettoyage final (très important pour Valgrind)
	free_stack(&stack_a);

	return (0);
}