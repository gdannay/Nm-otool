/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bchar.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdannay <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 11:00:30 by gdannay           #+#    #+#             */
/*   Updated: 2017/12/06 11:05:39 by gdannay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_bchar(char c, size_t length)
{
	size_t	i;
	char	*new;

	i = 0;
	if ((new = (char *)malloc(sizeof(char) * (length + 1))) == NULL)
		return (NULL);
	while (i < length)
	{
		new[i] = c;
		i++;
	}
	new[i] = '\0';
	return (new);
}
