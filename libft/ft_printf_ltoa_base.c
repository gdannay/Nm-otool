/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ltoa_base.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdannay <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 17:14:04 by gdannay           #+#    #+#             */
/*   Updated: 2017/12/13 19:10:55 by gdannay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		nb_fill(unsigned long long nb, char *new, int tail, char *base)
{
	if (nb >= (unsigned long long)ft_strlen(base))
		nb_fill(nb / (unsigned long long)ft_strlen(base), new, tail - 1, base);
	new[tail] = base[nb % (unsigned long long)ft_strlen(base)];
}

static void		nb_fill_neg(long long nb, char *new, int taille, char *base)
{
	if (nb <= (long long)ft_strlen(base) * -1)
		nb_fill_neg(nb / (long long)ft_strlen(base), new, taille - 1, base);
	new[taille] = base[nb % (long long)ft_strlen(base) * -1];
}

char			*ltoa_base(t_flag *tmp, char *base)
{
	long long	n;
	int			taille;
	char		*new;

	n = tmp->nb;
	taille = 0;
	while (n)
	{
		n /= (long long)ft_strlen(base);
		taille++;
	}
	if (tmp->nb <= 0)
		taille++;
	if ((new = (char *)malloc(sizeof(char) * (taille + 1))) == NULL)
		return (NULL);
	if (tmp->nb < 0)
	{
		new[0] = '-';
		nb_fill_neg(tmp->nb, new, taille - 1, base);
	}
	else
		nb_fill((unsigned long long)tmp->nb, new, taille - 1, base);
	new[taille] = '\0';
	return (new);
}

char			*utoa_base(t_flag *tmp, char *base)
{
	unsigned long long	n;
	int					taille;
	char				*new;

	n = tmp->unb;
	taille = 0;
	while (n)
	{
		n /= (long long)ft_strlen(base);
		taille++;
	}
	if (tmp->unb == 0)
		taille++;
	if ((new = (char *)malloc(sizeof(char) * (taille + 1))) == NULL)
		return (NULL);
	nb_fill(tmp->unb, new, taille - 1, base);
	new[taille] = '\0';
	return (new);
}
