/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdannay <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 09:30:33 by gdannay           #+#    #+#             */
/*   Updated: 2017/11/14 19:12:31 by gdannay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>

static void	nb_fill(long nb, char *new, int taille)
{
	if (nb >= 10)
		nb_fill(nb / 10, new, taille - 1);
	new[taille] = nb % 10 + '0';
}

char		*ft_itoa(int n)
{
	int		taille;
	long	nb;
	char	*new;

	nb = n;
	taille = 0;
	while (n)
	{
		n /= 10;
		taille++;
	}
	if (nb <= 0)
		taille++;
	if ((new = (char *)malloc(sizeof(char) * (taille + 1))) == NULL)
		return (NULL);
	if (nb < 0)
	{
		new[0] = '-';
		nb *= -1;
	}
	nb_fill(nb, new, taille - 1);
	new[taille] = '\0';
	return (new);
}
