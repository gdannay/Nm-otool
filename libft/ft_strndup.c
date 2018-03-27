/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdannay <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 21:40:08 by gdannay           #+#    #+#             */
/*   Updated: 2017/12/05 14:56:34 by gdannay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>

char	*ft_strndup(const char *s, size_t n)
{
	int		i;
	char	*new;

	i = 0;
	if (n <= 0)
		return (NULL);
	while (s && s[i] != '\0' && (size_t)i < n)
		i++;
	if ((new = (char *)malloc(sizeof(char) * (i + 1))) == NULL)
		return (NULL);
	i = 0;
	while (s && s[i] != '\0' && (size_t)i < n)
	{
		new[i] = s[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}
