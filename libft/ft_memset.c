/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdannay <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 19:00:01 by gdannay           #+#    #+#             */
/*   Updated: 2017/11/08 11:53:44 by gdannay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*new;
	unsigned char	c2;

	new = (unsigned char *)s;
	i = 0;
	c2 = (unsigned char)c;
	while (i < n)
	{
		new[i] = c2;
		i++;
	}
	return (s);
}
