/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdannay <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 12:56:49 by gdannay           #+#    #+#             */
/*   Updated: 2017/11/14 17:08:12 by gdannay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	size_t i;
	size_t size;

	i = 0;
	if (s != NULL && f != NULL)
	{
		size = ft_strlen(s);
		while (i < size)
		{
			(*f)((unsigned int)i, &s[i]);
			i++;
		}
	}
}
