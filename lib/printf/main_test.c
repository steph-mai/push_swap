/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marberge <marberge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 14:32:29 by marberge          #+#    #+#             */
/*   Updated: 2025/12/10 12:04:22 by marberge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "includes/ft_printf.h"
// #include <stdio.h>
// #include <limits.h>
// #include <stdint.h>

// // commande pour tester : 
// // gcc -g3 -fsanitize=address main_test.c -L. libftprintf.a -o test_asan

// static void sep(const char *title)
// {
//     printf("\n========== %s ==========\n", title);
// }

// int main(void)
// {
//     /* ------------------------------------------------------------ */
//     sep("Test de base - Comparaison avec printf systeme");

//     ft_printf("HELLO %s %d %u %x %X %p %%\n",
//               "world", 42, 42U, 48879, 48879, &sep);
//     printf("HELLO %s %d %u %x %X %p %%\n",
//            "world", 42, 42U, 48879, 48879, &sep);

//     /* ------------------------------------------------------------ */
//     sep("NULL tests");

//     ft_printf("NULL string -> %s\n", NULL);
//     printf("NULL string -> %s\n", NULL);

//     ft_printf("NULL pointer -> %p\n", NULL);
//     printf("NULL pointer -> %p\n", NULL);

//     /* ------------------------------------------------------------ */
//     sep("Int extremums");

//     ft_printf("INT_MAX=%d INT_MIN=%d\n", INT_MAX, INT_MIN);
//     printf("INT_MAX=%d INT_MIN=%d\n", INT_MAX, INT_MIN);

//     /* ------------------------------------------------------------ */
//     sep("Unsigned + overflow behaviour");

//     ft_printf("UINT_MAX=%u\n", UINT_MAX);
//     printf("UINT_MAX=%u\n", UINT_MAX);

//     ft_printf("0 unsigned=%u\n", 0U);
//     printf("0 unsigned=%u\n", 0U);

//     /* ------------------------------------------------------------ */
//     sep("Hex tests (lower/upper)");

//     ft_printf("hex 0=%x\n", 0);
//     printf("hex 0=%x\n", 0);

//     ft_printf("hex UINT_MAX=%x\n", UINT_MAX);
//     printf("hex UINT_MAX=%x\n", UINT_MAX);

//     ft_printf("HEX UINT_MAX=%X\n", UINT_MAX);
//     printf("HEX UINT_MAX=%X\n", UINT_MAX);

//     /* ------------------------------------------------------------ */
//     sep("Pointer tests");

//     int a = 1337;
//     ft_printf("ptr valid=%p\n", &a);
//     printf("ptr valid=%p\n", &a);

//     ft_printf("ptr huge=%p\n", (void*)ULONG_MAX);
//     printf("ptr huge=%p\n", (void*)ULONG_MAX);

//     /* ------------------------------------------------------------ */
//     sep("Characters");

//     ft_printf("char=%c %c %c\n", 'A', 0, 127);
//     printf("char=%c %c %c\n", 'A', 0, 127);

//     /* ------------------------------------------------------------ */
//     sep("Stress test: long string");

//     char big[2000];
//     for (int i = 0; i < 1999; i++)
//         big[i] = 'A' + (i % 26);
//     big[1999] = 0;

//     printf("BIG: %s\n", big);
//     ft_printf("BIG: %s\n", big);

//     /* ------------------------------------------------------------ */
//     sep("Stress test: chain with many %%%%");

//     printf("==> %d\n", ft_printf("%%%%%%%HELLO%%%%%%WORLD%%%%%%\n"));
//     printf("==> %d\n", printf("%%%%%%%HELLO%%%%%%WORLD%%%%%%\n"));

//     /* ------------------------------------------------------------ */
//     sep("Mix everything");

//     ft_printf("Mix: %s %d %u %x %p %c %% FIN\n",
//               "OK", -214748, 999999U, 0xDEADBEEF, &a, '?');
//     printf("Mix: %s %d %u %x %p %c %% FIN\n",
//            "OK", -214748, 999999U, 0xDEADBEEF, &a, '?');

//     /* ------------------------------------------------------------ */
//     sep("Case bizarre : argument manquant");

//     ft_printf(" -> %d %s %x\n");
//     printf(" -> %d %s %x\n");

//     /* ------------------------------------------------------------ */
//     sep("Case bizarre : format invalide");

//     ft_printf("invalid %q test\n");
//     printf("invalid %q test\n");

//     /* ------------------------------------------------------------ */
//     sep("Case bizarre : % suivi du \0");

//     char str0[] = "ABC%\0DEF";
//     ft_printf("TEST='%s'\n", str0);
//     printf("TEST='%s'\n", str0);

//     /* ------------------------------------------------------------ */
//     sep("Test buffer overflow volontaire");

//     for (int i = 0; i < 3000; i++)
//         ft_printf("A");

//     printf("\nOK: overflow test passed\n");

//     /* ------------------------------------------------------------ */
//     sep("FIN DES TESTS");

//     return 0;
// }
