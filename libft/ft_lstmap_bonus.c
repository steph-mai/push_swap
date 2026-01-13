/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marberge <marberge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 16:04:04 by marberge          #+#    #+#             */
/*   Updated: 2025/11/22 19:20:36 by marberge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// #include <stdio.h>

size_t		ft_strlen(const char *s);
char		*ft_strdup(const char *s);
t_list		*ft_lstnew(void *content);
void		ft_lstadd_front(t_list **lst, t_list *new);
void		ft_lstadd_back(t_list **lst, t_list *new);
void		ft_lstclear(t_list **lst, void (*del)(void *));

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*tmp;
	t_list	*result;
	t_list	*new_node;
	void	*new_content;

	result = NULL;
	tmp = lst;
	if (!tmp || !f || !del)
		return (NULL);
	while (tmp)
	{
		new_content = f(tmp->content);
		new_node = ft_lstnew(new_content);
		if (!new_node)
		{
			del(new_content);
			ft_lstclear(&result, del);
			return (NULL);
		}
		ft_lstadd_back(&result, new_node);
		tmp = tmp->next;
	}
	return (result);
}

// static void	ft_delcontent(void *content)
// {
// 	if (content)
// 		free(content);
// }

// static void	*ft_reverse_case(void *c)
// {
// 	int		i;
// 	char	*str;
// 	int		len;
// 	char	*res;

// 	i = 0;
// 	str = (char *)c;
// 	len = ft_strlen(str);
// 	res = malloc((len + 1) * sizeof(char));
// 	if (!res)
// 		return (NULL);
// 	while (str[i] != '\0')
// 	{
// 		if (str[i] >= 65 && str[i] <= 90)
// 			res[i] = str[i] + 32;
// 		else if (str[i] >= 97 && str[i] <= 122)
// 			res[i] = str[i] - 32;
// 		else
// 			res[i] = str[i];
// 		i++;
// 	}
// 	res[i] = '\0';
// 	return (res);
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
// 	t_list	*list2;

// 	list = NULL;
// 	list2 = NULL;
// 	node = ft_lstnew(ft_strdup("hello"));
// 	node2 = ft_lstnew(ft_strdup("world"));
// 	node3 = ft_lstnew(ft_strdup("MARCO"));
// 	ft_lstadd_front(&list, node);
// 	ft_lstadd_back(&list, node2);
// 	ft_lstadd_back(&list, node3);
// 	ft_print_list(list);
// 	list2 = ft_lstmap(list, ft_reverse_case, ft_delcontent);
// 	ft_print_list(list2);
// 	return (0);
// }