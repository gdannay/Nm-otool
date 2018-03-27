/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdannay <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 19:51:50 by gdannay           #+#    #+#             */
/*   Updated: 2017/11/14 19:12:55 by gdannay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strnstr(const char *str, const char *need, size_t n)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	j = 0;
	k = 0;
	while (str[i] != '\0' && i + k < n)
	{
		while (str[i + k] == need[j] && i + k < n)
		{
			k++;
			j++;
			if (need[j] == '\0')
				return ((char *)(str + i));
		}
		k = 0;
		j = 0;
		i++;
	}
	if (need[j] == '\0')
		return ((char *)(str));
	return (NULL);
}
