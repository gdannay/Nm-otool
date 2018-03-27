/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdannay <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 19:44:59 by gdannay           #+#    #+#             */
/*   Updated: 2018/01/07 16:26:19 by gdannay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*c1;
	unsigned char	*c2;

	i = 0;
	c1 = (unsigned char *)s1;
	c2 = (unsigned char *)s2;
	if (!(c1) && !(c2))
		return (0);
	else if (!(c1))
		return (-c2[i]);
	else if (!(c2))
		return (c1[i]);
	if (n == 0)
		return (0);
	while (c1[i] != '\0' && c2[i] != '\0'
			&& i < n - 1 && c1[i] == c2[i])
		i++;
	return (c1[i] - c2[i]);
}
