/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marberge <marberge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 19:27:48 by marberge          #+#    #+#             */
/*   Updated: 2025/11/22 19:33:03 by marberge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// #include <stdio.h>

t_list		*ft_lstnew(void *content);
void		ft_lstadd_front(t_list **lst, t_list *new);

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*list;

	list = *lst;
	if (!list)
	{
		*lst = new;
		return ;
	}
	while (list)
	{
		if (list->next == NULL)
		{
			list->next = new;
			return ;
		}
		list = list->next;
	}
}

// int	main(void)
// {
// 	t_list	*list;
// 	t_list	*node;
// 	t_list	*node2;
// 	t_list	*tmp;

// 	list = NULL;
// 	node = ft_lstnew(ft_strdup("hello"));
// 	node2 = ft_lstnew(ft_strdup("world"));
// 	ft_lstadd_front(&list, node);
// 	ft_lstadd_back(&list, node2);
// 	tmp = list;
// 	while (tmp)
// 	{
// 		printf("%p | %s |  %p\n", tmp, (char *)tmp->content, tmp->next);
// 		tmp = tmp->next;
// 	}
// 	return (0);
// }