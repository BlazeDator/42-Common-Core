/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 16:22:04 by pabernar          #+#    #+#             */
/*   Updated: 2023/10/10 17:45:30 by pabernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newlist;
	t_list	*start;

	if (!lst || !f || !del)
		return (0);
	newlist = 0;
	while (lst)
	{
		if (!newlist)
		{
			newlist = ft_lstnew(f(lst->content));
			start = newlist;
		}
		else
		{
			newlist->next = ft_lstnew(f(lst->content));
			newlist = newlist->next;
		}
		if (!newlist)
		{
			ft_lstclear(&start, del);
			start = 0;
			break;
		}
		lst = lst->next;
	}
	return (start);
}
