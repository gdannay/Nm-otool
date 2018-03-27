/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdannay <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 19:54:44 by gdannay           #+#    #+#             */
/*   Updated: 2018/01/08 14:53:50 by gdannay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strstr(const char *str, const char *need)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	k = 0;
	if (str == NULL || need == NULL)
		return (NULL);
	while (str[i] != '\0')
	{
		while (str[i + k] == need[j])
		{
			k++;
			j++;
			if (need[j] == '\0')
				return ((char *)(str + i));
		}
		k = 0;
		j = 0;
		i++;
	}
	if (need[j] == '\0')
		return ((char *)(str));
	return (NULL);
}
