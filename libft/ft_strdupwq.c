/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdannay <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 21:40:08 by gdannay           #+#    #+#             */
/*   Updated: 2018/01/11 16:46:57 by gdannay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "libft.h"

char	*ft_strdupwq(char *s, char quote)
{
	int		i;
	int		j;
	char	*new;

	i = 0;
	j = -1;
	if (s == NULL)
		return (NULL);
	if (quote < 0)
		quote *= -1;
	i = ft_strlenwq(s, quote);
	if ((new = (char *)malloc(sizeof(char) * (i + 1))) == NULL)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] != quote && (s[i] != '\\' || (s[i + 1] && s[i + 1] == '\\')))
			new[++j] = s[i];
		i++;
	}
	new[j + 1] = '\0';
	return (new);
}
