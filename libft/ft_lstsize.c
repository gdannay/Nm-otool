/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdannay <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/21 16:49:53 by gdannay           #+#    #+#             */
/*   Updated: 2017/12/15 18:28:14 by gdannay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

size_t	ft_lstsize(t_list *begin_list)
{
	t_list	*temp;
	size_t	i;

	i = 0;
	temp = begin_list;
	while (temp)
	{
		temp = temp->next;
		i++;
	}
	return (i);
}
