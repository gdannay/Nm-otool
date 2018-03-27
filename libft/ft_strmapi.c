/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdannay <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 13:34:44 by gdannay           #+#    #+#             */
/*   Updated: 2017/11/14 17:11:13 by gdannay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	size_t	size;
	char	*new;

	i = 0;
	if (s == NULL || f == NULL)
		return (NULL);
	size = ft_strlen(s);
	if ((new = (char *)malloc(sizeof(char) * (size + 1))) == NULL)
		return (NULL);
	while (i < size)
	{
		new[i] = (*f)((unsigned int)i, s[i]);
		i++;
	}
	new[i] = '\0';
	return (new);
}
