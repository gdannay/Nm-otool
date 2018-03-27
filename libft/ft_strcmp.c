/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdannay <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 19:43:57 by gdannay           #+#    #+#             */
/*   Updated: 2018/01/07 16:54:12 by gdannay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t			i;
	unsigned char	*c1;
	unsigned char	*c2;

	i = 0;
	c1 = (unsigned char *)s1;
	c2 = (unsigned char *)s2;
	if (!(s1) && !(s2))
		return (0);
	if (!(c1))
		return (-c2[0]);
	if (!(c2))
		return (c1[0]);
	while (c1[i] != '\0' && c2[i] != '\0' && c1[i] == c2[i])
		i++;
	return (c1[i] - c2[i]);
}
