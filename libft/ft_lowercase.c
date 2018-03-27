/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lowercase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdannay <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 18:15:11 by gdannay           #+#    #+#             */
/*   Updated: 2017/11/14 18:19:19 by gdannay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <string.h>

char	*ft_lowercase(char *s)
{
	int		i;
	char	*new;

	i = 0;
	if ((new = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1))) == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		if (s[i] >= 'A' && s[i] <= 'Z')
			new[i] = s[i] - 'A' + 'a';
		else
			new[i] = s[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}
