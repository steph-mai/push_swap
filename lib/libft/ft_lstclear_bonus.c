/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marberge <marberge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 12:23:44 by marberge          #+#    #+#             */
/*   Updated: 2025/11/22 14:44:43 by marberge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// #include <stdio.h>

size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s);
t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void *));

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*list;
	t_list	*tmp;

	list = *lst;
	tmp = *lst;
	if (!list)
		return ;
	while (tmp)
	{
		list = tmp;
		tmp = list->next;
		ft_lstdelone(list, del);
	}
	ft_lstdelone(tmp, del);
	*lst = NULL;
}

// static void	ft_delcontent(void *content)
// {
// 	if (content)
// 		free(content);
// }

// static void	ft_print_list(t_list *lst)
// {
// 	t_list	*tmp;

// 	tmp = lst;
// 	if (!tmp)
// 		printf("ce noeud est NULL");
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
// 	node3 = ft_lstnew(ft_strdup("Marco"));
// 	ft_lstadd_front(&list, node);
// 	ft_lstadd_back(&list, node2);
// 	ft_lstadd_back(&list, node3);
// 	printf("BEFORE : %p\n", list);
// 	ft_print_list(list);
// 	ft_lstclear(&list, ft_delcontent);
// 	if (!list)
// 	{
// 		printf("AFTER : %p\n", list);
// 		printf("ok !\n");
// 	}
// 	return (0);
// }
