/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdannay <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 18:50:51 by gdannay           #+#    #+#             */
/*   Updated: 2017/11/13 14:12:46 by gdannay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*new;
	unsigned char	d;

	i = 0;
	d = (unsigned char)c;
	new = (unsigned char *)s;
	while (i < n)
	{
		if (new[i] == d)
			return (new + i);
		i++;
	}
	return (NULL);
}
