/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marberge <marberge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 17:27:29 by marberge          #+#    #+#             */
/*   Updated: 2025/11/22 19:32:37 by marberge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// #include <stdio.h>

t_list		*ft_lstnew(void *content);
void		ft_lstadd_front(t_list **lst, t_list *new);

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	new->next = *lst;
	*lst = new;
}

// int	main(void)
// {
// 	t_list	*list;
// 	t_list	*node;
// 	t_list	*node2;
// 	char	*s = "world";
// 	char	*s2 = "Hello";

// 	list = NULL;
// 	node = ft_lstnew(s);
// 	node2 = ft_lstnew(s2);
// 	printf("n1 : %p | %s |  %p\n", node, (char *)node->content, node->next);
// 	printf("n2 : %p | %s |  %p\n", node2, (char *)node2->content, node2->next);
// 	printf("list adress (first node) : %p\n", list);
// 	ft_lstadd_front(&list, node);
// 	ft_lstadd_front(&list, node2);
// 	printf("\n");
// 	printf("list adress (first node) : %p\n", list);
// 	while (list)
// 	{
// 		printf("%p | %s |  %p\n", list, (char *)list->content, list->next);
// 		list = list->next;
// 	}
// 	return (0);
// }
