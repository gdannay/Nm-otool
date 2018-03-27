/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdannay <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 09:44:24 by gdannay           #+#    #+#             */
/*   Updated: 2018/01/11 10:53:28 by gdannay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

static int		is_space(char c)
{
	if (c == ' ' || c == '\t')
		return (1);
	return (0);
}

static int		nb_mots(char const *s)
{
	int	i;
	int	nb;

	i = 0;
	nb = 0;
	while (s[i] != '\0')
	{
		if (!is_space(s[i]))
		{
			while (s[i + 1] != '\0' && !is_space(s[i + 1]))
				i++;
			nb++;
		}
		i++;
	}
	return (nb);
}

static int		length(char const *s, char **new)
{
	int	i;
	int	deb;
	int	mot;

	i = 0;
	deb = 0;
	mot = 0;
	while (s[i] != '\0')
	{
		if (!is_space(s[i]))
		{
			deb = i;
			while (s[i] != '\0' && !is_space(s[i]))
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

static void		fill(char const *s, char **new)
{
	int i;
	int j;
	int mot;

	i = 0;
	mot = 0;
	j = 0;
	while (s[i] != '\0')
	{
		if (!is_space(s[i]))
		{
			while (s[i] != '\0' && !is_space(s[i]))
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

char			**ft_strsplitspace(char const *s)
{
	char	**new;
	int		nb;

	if (s == NULL)
		return (NULL);
	nb = nb_mots(s);
	if ((new = (char **)malloc(sizeof(new) * (nb + 1))) == NULL)
		return (NULL);
	if (length(s, new))
		return (NULL);
	fill(s, new);
	return (new);
}
