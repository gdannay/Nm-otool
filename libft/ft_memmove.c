/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdannay <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 11:58:53 by gdannay           #+#    #+#             */
/*   Updated: 2017/11/08 14:57:13 by gdannay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t			i;
	int				j;
	unsigned char	*destb;
	unsigned char	*srcb;

	i = -1;
	j = n;
	destb = (unsigned char*)dest;
	srcb = (unsigned char*)src;
	if (dest - src <= 0)
	{
		while (++i < n)
			destb[i] = srcb[i];
	}
	else
	{
		while (--j >= 0)
			destb[j] = srcb[j];
	}
	return (dest);
}
