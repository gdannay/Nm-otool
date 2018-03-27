/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dtabdup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdannay <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/07 11:59:17 by gdannay           #+#    #+#             */
/*   Updated: 2018/01/17 10:43:20 by gdannay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_tabdup(char **tab)
{
	int		i;
	char	**cpy;

	i = 0;
	cpy = NULL;
	while (tab && tab[i])
		i++;
	if ((cpy = (char **)malloc(sizeof(char *) * (i + 1))) == NULL)
		return (NULL);
	cpy[i] = 0;
	i = -1;
	while (tab && tab[++i])
		cpy[i] = ft_strdup(tab[i]);
	return (cpy);
}
