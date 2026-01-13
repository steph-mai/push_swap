/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marberge <marberge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 14:47:00 by marberge          #+#    #+#             */
/*   Updated: 2025/11/22 16:33:22 by marberge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// #include <stdio.h>

size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s);
t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_lstadd_back(t_list **lst, t_list *new);

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*tmp;

	tmp = lst;
	if (!tmp || !f)
		return ;
	while (tmp)
	{
		f(tmp->content);
		tmp = tmp->next;
	}
}

// static void	ft_reverse_case(void *c)
// {
// 	int		i;
// 	char	*str;

// 	i = 0;
// 	str = (char *)c;
// 	while (str[i] != '\0')
// 	{
// 		if (str[i] >= 65 && str[i] <= 90)
// 			str[i] = str[i] + 32;
// 		else if (str[i] >= 97 && str[i] <= 122)
// 			str[i] = str[i] - 32;
// 		i++;
// 	}
// }

// static void	ft_print_list(t_list *lst)
// {
// 	t_list	*tmp;

// 	tmp = lst;
// 	if (!tmp)
// 	{
// 		printf("ce noeud est NULL\n");
// 		return ;
// 	}
// 	while (tmp)
// 	{
// 		printf("%p | %s |  %p\n", tmp, (char *)tmp->content, tmp->next);
// 		tmp = tmp->next;
// 	}
// 	printf("\n");
// }

// int	main(void)
// {
// 	t_list	*list;
// 	t_list	*node;
// 	t_list	*node2;
// 	t_list	*node3;

// 	list = NULL;
// 	node = ft_lstnew(ft_strdup("hello"));
// 	node2 = ft_lstnew(ft_strdup("world"));
// 	node3 = ft_lstnew(ft_strdup("MARCO"));
// 	ft_lstadd_front(&list, node);
// 	ft_lstadd_back(&list, node2);
// 	ft_lstadd_back(&list, node3);
// 	ft_print_list(list);
// 	ft_lstiter(list, ft_reverse_case);
// 	ft_print_list(list);
// 	return (0);
// }
