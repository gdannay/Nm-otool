/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdannay <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 10:22:51 by gdannay           #+#    #+#             */
/*   Updated: 2018/01/11 19:00:29 by gdannay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "libft.h"

char	*ft_strjoinwq(char *s1, char *s2, char quote)
{
	char	*new;
	size_t	i;
	size_t	j;

	i = -1;
	j = -1;
	if ((new = (char *)malloc(sizeof(char) *
				(ft_strlenwq(s1, quote) + ft_strlenwq(s2, quote) + 1))) == NULL)
		return (0);
	while (s1 && s1[++j] != '\0')
	{
		if (s1[i] != quote && (s1[i] != '\\'
				|| (s1[i + 1] && s1[i + 1] == '\\'
				&& (i == 0 || s1[i - 1] != '\\'))))
			new[++i] = s1[j];
	}
	j = -1;
	while (s2 && s2[++j] != '\0')
	{
		if (s2[j] != quote && (s2[j] != '\\' || (s2[j + 1]
				&& s2[j + 1] != '\\' && (j == 0 || s2[j - 1] != '\\'))))
			new[++i] = s2[j];
	}
	new[i + 1] = '\0';
	return (new);
}
