/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdannay <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 10:22:51 by gdannay           #+#    #+#             */
/*   Updated: 2018/01/17 10:43:38 by gdannay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "libft.h"

char	**ft_tabjoin(char **s1, char **s2)
{
	size_t	size1;
	size_t	size2;
	char	**new;
	size_t	i;
	size_t	j;

	i = -1;
	j = 0;
	size1 = ft_tablen(s1);
	size2 = ft_tablen(s2);
	if ((new = (char **)malloc(sizeof(char *) * (size1 + size2 + 1))) == NULL)
		return (0);
	while (s1 && s1[++i])
		new[i] = ft_strdup(s1[i]);
	while (s2 && s2[j])
		new[i++] = ft_strdup(s2[j++]);
	new[i] = 0;
	return (new);
}
