/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ltoa_base.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdannay <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 17:14:04 by gdannay           #+#    #+#             */
/*   Updated: 2018/03/21 17:12:53 by gdannay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		nb_fill(unsigned long long nb, char *new, int tail, char *base)
{
	if (nb >= (unsigned long long)ft_strlen(base))
		nb_fill(nb / (unsigned long long)ft_strlen(base), new, tail - 1, base);
	new[tail] = base[nb % (unsigned long long)ft_strlen(base)];
}

char			*ft_lltoa_base(uint64_t nb, char *base)
{
	uint64_t	n;
	int			taille;
	char		*new;

	n = nb;
	taille = 0;
	while (n)
	{
		n /= (long long)ft_strlen(base);
		taille++;
	}
	if (nb == 0)
		taille++;
	if ((new = (char *)malloc(sizeof(char) * (taille + 1))) == NULL)
		return (NULL);
	nb_fill(nb, new, taille - 1, base);
	new[taille] = '\0';
	return (new);
}
