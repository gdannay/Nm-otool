/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdannay <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 09:44:24 by gdannay           #+#    #+#             */
/*   Updated: 2018/01/07 16:51:47 by gdannay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>

static int		nb_mots(char const *s, char c)
{
	int	i;
	int	nb;

	i = 0;
	nb = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			while (s[i + 1] != '\0' && s[i + 1] != c)
				i++;
			nb++;
		}
		i++;
	}
	return (nb);
}

static int		length(char const *s, char **new, char c)
{
	int	i;
	int	deb;
	int	mot;

	i = 0;
	deb = 0;
	mot = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			deb = i;
			while (s[i] != '\0' && s[i] != c)
				i++;
			if (!(new[mot] = (char *)malloc(sizeof(char) * (i - deb + 1))))
				return (1);
			mot++;
		}
		else
			i++;
	}
	return (0);
}

static void		fill(char const *s, char **new, char c)
{
	int i;
	int j;
	int mot;

	i = 0;
	mot = 0;
	j = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			while (s[i] != '\0' && s[i] != c)
				new[mot][j++] = s[i++];
			new[mot][j] = '\0';
			mot++;
		}
		else
			i++;
		j = 0;
	}
	new[mot] = 0;
}

char			**ft_strsplit(char const *s, char c)
{
	char	**new;
	int		nb;

	if (s == NULL)
		return (NULL);
	nb = nb_mots(s, c);
	if ((new = (char **)malloc(sizeof(new) * (nb + 1))) == NULL)
		return (NULL);
	if (length(s, new, c))
		return (NULL);
	fill(s, new, c);
	return (new);
}
