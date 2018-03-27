/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdannay <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 12:14:16 by gdannay           #+#    #+#             */
/*   Updated: 2017/11/13 14:12:20 by gdannay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*new;

	if ((new = (void *)malloc(sizeof(new) * size)) == NULL)
		return (NULL);
	ft_bzero(new, size);
	return (new);
}
