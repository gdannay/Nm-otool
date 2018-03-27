/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdannay <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 21:40:08 by gdannay           #+#    #+#             */
/*   Updated: 2017/12/05 17:42:42 by gdannay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>

char	*ft_strdup(const char *s)
{
	int		i;
	char	*new;

	i = 0;
	if (s == NULL)
		return (NULL);
	while (s[i] != '\0')
		i++;
	if ((new = (char *)malloc(sizeof(char) * (i + 1))) == NULL)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		new[i] = s[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}
