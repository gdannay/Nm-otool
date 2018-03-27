/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdannay <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 21:40:08 by gdannay           #+#    #+#             */
/*   Updated: 2018/01/11 19:00:54 by gdannay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

char	*ft_strndupwq(const char *s, size_t n)
{
	int		i;
	int		j;
	char	*new;

	i = 0;
	j = -1;
	if (n <= 0)
		return (NULL);
	while (s && s[i] != '\0' && (size_t)i < n)
		i++;
	if ((new = (char *)malloc(sizeof(char) * (i + 1))) == NULL)
		return (NULL);
	i = 0;
	while (s && s[i] != '\0' && j < (int)n)
	{
		if (s[i] != '\\' || (s[i + 1] && s[i + 1] == '\\'
				&& (i == 0 || s[i - 1] != '\\')))
			new[++j] = s[i];
		i++;
	}
	new[j + 1] = '\0';
	return (new);
}
