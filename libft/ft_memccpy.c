/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdannay <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 10:35:13 by gdannay           #+#    #+#             */
/*   Updated: 2017/11/08 11:51:46 by gdannay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	c2;
	unsigned char	*destb;
	unsigned char	*srcb;

	i = 0;
	c2 = (unsigned char)c;
	destb = (unsigned char *)dest;
	srcb = (unsigned char *)src;
	while (i < n && srcb[i] != c2)
	{
		destb[i] = srcb[i];
		i++;
	}
	if (i == n)
		return (NULL);
	destb[i] = srcb[i];
	return (dest + i + 1);
}
