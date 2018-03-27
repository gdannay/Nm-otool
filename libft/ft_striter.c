/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdannay <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 12:48:16 by gdannay           #+#    #+#             */
/*   Updated: 2017/11/14 17:07:47 by gdannay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

void	ft_striter(char *s, void (*f)(char *))
{
	size_t	i;
	size_t	size;

	i = 0;
	if (s != NULL && f != NULL)
	{
		size = ft_strlen(s);
		while (i < size)
		{
			(*f)(&s[i]);
			i++;
		}
	}
}
