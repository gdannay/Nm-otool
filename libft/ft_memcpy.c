/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memcpy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdannay <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 10:21:55 by gdannay           #+#    #+#             */
/*   Updated: 2017/11/08 10:32:36 by gdannay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*destb;
	unsigned char	*srcb;

	i = 0;
	destb = (unsigned char *)dest;
	srcb = (unsigned char *)src;
	while (i < n)
	{
		destb[i] = srcb[i];
		i++;
	}
	return (dest);
}
