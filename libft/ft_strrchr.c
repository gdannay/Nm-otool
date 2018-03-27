/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdannay <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 19:54:19 by gdannay           #+#    #+#             */
/*   Updated: 2017/11/29 12:42:34 by gdannay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strrchr(const char *s, int c)
{
	int				i;
	int				j;
	unsigned char	b;

	i = 0;
	j = -1;
	b = (unsigned char)c;
	if (!s)
		return (NULL);
	while (s[i] != '\0')
	{
		if (s[i] == b)
			j = i;
		i++;
	}
	if (j == -1 && b != '\0')
		return (NULL);
	if (b == '\0')
		return ((char *)(s + i));
	return ((char *)(s + j));
}
