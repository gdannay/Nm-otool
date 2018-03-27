/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdannay <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 12:30:46 by gdannay           #+#    #+#             */
/*   Updated: 2017/11/13 14:18:19 by gdannay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "libft.h"

char	*ft_strnew(size_t size)
{
	size_t	i;
	char	*new;

	i = 0;
	if ((new = (char *)malloc(sizeof(char) * (size + 1))) == NULL)
		return (NULL);
	while (i < size + 1)
	{
		new[i] = '\0';
		i++;
	}
	return (new);
}
