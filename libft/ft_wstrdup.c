/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdannay <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 21:40:08 by gdannay           #+#    #+#             */
/*   Updated: 2017/12/11 18:34:35 by gdannay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "libft.h"

wchar_t	*ft_wstrdup(const wchar_t *s)
{
	int		i;
	wchar_t	*new;

	i = 0;
	if (s == NULL)
		return (NULL);
	while (s[i] != '\0')
		i++;
	if ((new = (wchar_t *)malloc(sizeof(wchar_t) * (i + 1))) == NULL)
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
