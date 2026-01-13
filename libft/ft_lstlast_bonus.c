/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marberge <marberge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 18:27:27 by marberge          #+#    #+#             */
/*   Updated: 2025/11/22 19:21:21 by marberge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// #include <stdio.h>

t_list		*ft_lstnew(void *content);
void		ft_lstadd_front(t_list **lst, t_list *new);

t_list	*ft_lstlast(t_list *lst)
{
	while (lst)
	{
		if (lst->next == NULL)
			return (lst);
		lst = lst->next;
	}
	return (NULL);
}

// int	main(void)
// {
// 	t_list	*list;
// 	t_list	*node;
// 	t_list	*node2;
// 	t_list	*node3;
// 	char	*s = "world";
// 	char	*s2 = "Hello";
// 	char	*s3 = "TOTO";

// 	list = NULL;
// 	node = ft_lstnew(s);
// 	node2 = ft_lstnew(s2);
// 	node3 = ft_lstnew(s3);
// 	printf("n1 : %p | %s |  %p\n", node, (char *)node->content, node->next);
// 	printf("n2 : %p | %s |  %p\n", node2, (char *)node2->content, node2->next);
// 	printf("n3 : %p | %s |  %p\n", node3, (char *)node3->content, node3->next);
// 	ft_lstadd_front(&list, node);
// 	ft_lstadd_front(&list, node2);
// 	ft_lstadd_front(&list, node3);
// 	printf("last node : %p\n", ft_lstlast(list));
// 	return (0);
// }