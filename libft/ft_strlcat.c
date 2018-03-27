/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strlcat.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdannay <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 13:10:23 by gdannay           #+#    #+#             */
/*   Updated: 2017/11/14 19:12:47 by gdannay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	init;

	i = 0;
	j = 0;
	init = ft_strlen(dest);
	while (dest[i] != '\0' && i < size)
		i++;
	if (i == size)
		return (size + ft_strlen(src));
	while (src[j] != '\0' && i < size - 1)
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (init + ft_strlen(src));
}
