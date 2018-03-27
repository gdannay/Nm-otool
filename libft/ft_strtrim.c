/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdannay <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 09:47:59 by gdannay           #+#    #+#             */
/*   Updated: 2017/11/14 19:13:00 by gdannay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>

static char	*remp_new(int der, int pre, char const *s)
{
	int		i;
	char	*new;

	i = 0;
	if ((new = (char *)malloc(sizeof(char) * (der - pre + 2))) == NULL)
		return (NULL);
	while (pre <= der)
	{
		new[i] = s[pre];
		i++;
		pre++;
	}
	new[i] = '\0';
	return (new);
}

char		*ft_strtrim(char const *s)
{
	int		i;
	int		der;
	int		pre;

	i = 0;
	der = 0;
	pre = 0;
	if (s == NULL)
		return (NULL);
	while (s[pre] != '\0' && (s[pre] == ' ' ||
				s[pre] == '\n' || s[pre] == '\t'))
		pre++;
	while (s[i] != '\0')
	{
		if (s[i] != ' ' && s[i] != '\n' && s[i] != '\t')
			der = i;
		i++;
	}
	if (der == 0)
	{
		der = -1;
		pre = 0;
	}
	return (remp_new(der, pre, s));
}
