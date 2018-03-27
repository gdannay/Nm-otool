/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdannay <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 12:54:55 by gdannay           #+#    #+#             */
/*   Updated: 2017/11/14 16:28:23 by gdannay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*list;
	t_list	*beg;
	t_list	*tmp;
	t_list	*tmp2;

	tmp = (*f)(lst);
	list = ft_lstnew(tmp->content, tmp->content_size);
	beg = list;
	lst = lst->next;
	while (lst)
	{
		tmp = (*f)(lst);
		tmp2 = ft_lstnew(tmp->content, tmp->content_size);
		list->next = tmp2;
		list = list->next;
		lst = lst->next;
	}
	return (beg);
}
