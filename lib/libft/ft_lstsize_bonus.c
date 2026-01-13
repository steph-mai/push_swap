/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marberge <marberge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 18:09:23 by marberge          #+#    #+#             */
/*   Updated: 2025/11/22 19:33:12 by marberge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// #include <stdio.h>

int	ft_lstsize(t_list *lst)
{
	int	count;

	count = 0;
	while (lst)
	{
		count++;
		lst = lst->next;
	}
	return (count);
}

// int	main(void)
// {
// 	t_list	*list = NULL;
// 	t_list	*node;
// 	t_list	*node2;
// 	t_list	*node3;
// 	char	*s = "world";
// 	char	*s2 = "Hello";
// 	char	*s3 = "TOTO";

// 	node = ft_lstnew(s);
// 	node2 = ft_lstnew(s2);
// 	node3 = ft_lstnew(s3);
// 	printf("number of node : %d\n", ft_lstsize(list));
// 	printf("n1 : %p | %s |  %p\n", node, (char *)node->content, node->next);
// 	printf("n2 : %p | %s |  %p\n", node2, (char *)node2->content, node2->next);
// 	printf("n3 : %p | %s |  %p\n", node3, (char *)node3->content, node3->next);
// 	ft_lstadd_front(&list, node);
// 	ft_lstadd_front(&list, node2);
// 	ft_lstadd_front(&list, node3);
// 	printf("\n");
// 	printf("number of node : %d\n", ft_lstsize(list));
// 	while (list)
// 	{
// 		printf("%p | %s |  %p\n", list, (char *)list->content, list->next);
// 		list = list->next;
// 	}
// 	return (0);
// }