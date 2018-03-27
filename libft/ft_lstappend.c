/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstappend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdannay <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 12:49:22 by gdannay           #+#    #+#             */
/*   Updated: 2017/11/14 16:30:10 by gdannay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

void	ft_lstappend(t_list **alst, t_list *new)
{
	t_list	*list;

	list = *alst;
	while (list->next != NULL)
		list = list->next;
	list->next = new;
}
