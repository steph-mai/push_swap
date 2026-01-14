
#include "push_swap.h"
#include <stdio.h>

/* --- OUTILS DE VISUALISATION --- */

// Affiche une pile avec les adresses mémoire (Vital pour debug)
static void print_debug_stack(t_stack_node *stack, char *name)
{
    ft_printf("\n🔵 --- %s ---\n", name);
    if (!stack)
    {
        ft_printf("(Vide)\n");
        return;
    }
    while (stack)
    {
        // On utilise printf standard pour afficher les pointeurs avec %p proprement
        printf("Node [%d] (%p) | Prev: %p | Next: %p\n", 
               stack->number, (void*)stack, (void*)stack->prev, (void*)stack->next);
        
        // Petite vérification automatique de cohérence
        if (stack->prev && stack->prev->next != stack)
            printf("   ⚠️  ERREUR LIEN: Mon Prev ne pointe pas vers moi !\n");
        if (stack->next && stack->next->prev != stack)
            printf("   ⚠️  ERREUR LIEN: Mon Next ne pointe pas vers moi !\n");
            
        stack = stack->next;
    }
}

// Petit utilitaire pour créer des nodes rapidement pour le test
static void add_test_node(t_stack_node **stack, int n)
{
    t_stack_node *new = malloc(sizeof(t_stack_node));
    t_stack_node *last;

    if (!new) return;
    new->number = n;
    new->index = -1; // On s'en fiche pour ce test
    new->next = NULL;
    
    if (!*stack)
    {
        new->prev = NULL;
        *stack = new;
    }
    else
    {
        last = *stack;
        while (last->next)
            last = last->next;
        last->next = new;
        new->prev = last;
    }
}

/* --- SCÉNARIO DE TEST --- */

int main(void)
{
    t_stack_node *a = NULL;
    t_stack_node *b = NULL;

    printf("=========================================\n");
    printf("     TEST UNITAIRE : PUSH & SWAP\n");
    printf("=========================================\n");

    // 1. Initialisation
    printf("\n🔹 1. INIT: A = [1, 2, 3] | B = (vide)\n");
    add_test_node(&a, 1);
    add_test_node(&a, 2);
    add_test_node(&a, 3);
    print_debug_stack(a, "STACK A");
    print_debug_stack(b, "STACK B");

    // 2. Test SA
    printf("\n🔹 2. ACTION: sa (Swap A) -> Attendu: A = [2, 1, 3]\n");
    sa(&a);
    print_debug_stack(a, "STACK A");
    
    // 3. Test PB (premier élément)
    printf("\n🔹 3. ACTION: pb (Push vers B) -> Attendu: B = [2], A = [1, 3]\n");
    pb(&b, &a);
    print_debug_stack(a, "STACK A");
    print_debug_stack(b, "STACK B");

    // 4. Test PB (deuxième élément pour empiler)
    printf("\n🔹 4. ACTION: pb (Push vers B) -> Attendu: B = [1, 2], A = [3]\n");
    pb(&b, &a);
    print_debug_stack(a, "STACK A");
    print_debug_stack(b, "STACK B");

    // 5. Test SB (Swap B)
    printf("\n🔹 5. ACTION: sb (Swap B) -> Attendu: B = [2, 1]\n");
    sb(&b);
    print_debug_stack(b, "STACK B");

    // 6. Test SS (Double Swap : on remet un element dans A pour tester)
    // On a A=[3] et B=[2, 1]. On ajoute 4 dans A pour avoir 2 éléments.
    add_test_node(&a, 4); // A devient [3, 4]
    printf("\n🔹 6. ACTION: ss (Swap A et B) -> A=[3,4], B=[2,1] deviennent A=[4,3], B=[1,2]\n");
    ss(&a, &b);
    print_debug_stack(a, "STACK A");
    print_debug_stack(b, "STACK B");

    // 7. Test PA (Retour vers A)
    printf("\n🔹 7. ACTION: pa (Tout renvoyer vers A)\n");
    while (b)
        pa(&a, &b);
    
    print_debug_stack(a, "STACK A FINAL");
    print_debug_stack(b, "STACK B FINAL");

    // Nettoyage mémoire (simulation free_stack)
    t_stack_node *tmp;
    while (a) { tmp = a; a = a->next; free(tmp); }
    
    return (0);
}