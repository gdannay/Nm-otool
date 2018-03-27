/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chartostr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdannay <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 11:04:37 by gdannay           #+#    #+#             */
/*   Updated: 2017/12/06 11:06:14 by gdannay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*chartostr(long long c)
{
	char *new;

	if ((new = (char *)malloc(sizeof(char) * 2)) == NULL)
		return (NULL);
	new[0] = (char)c;
	new[1] = '\0';
	return (new);
}
