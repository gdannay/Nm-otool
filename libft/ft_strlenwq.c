/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdannay <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 21:39:57 by gdannay           #+#    #+#             */
/*   Updated: 2018/01/11 14:20:26 by gdannay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

size_t	ft_strlenwq(char *s, char quote)
{
	size_t	i;
	size_t	size;

	i = 0;
	size = 0;
	if (s == NULL)
		return (0);
	while (s[i] != '\0')
	{
		if (s[i] != quote && (s[i] != '\\' || (s[i + 1] && s[i + 1] == '\\')))
			size++;
		i++;
	}
	return (size);
}
