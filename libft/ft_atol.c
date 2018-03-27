/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdannay <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 10:46:46 by gdannay           #+#    #+#             */
/*   Updated: 2018/01/17 10:46:48 by gdannay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long	ft_atol(const char *nbr)
{
	int		i;
	int		neg;
	long	n;

	i = 0;
	neg = 0;
	n = 0;
	while ((nbr[i] >= 8 && nbr[i] <= 13) || nbr[i] == ' ')
		i++;
	if (nbr[i] == '-')
		neg = 1;
	if (nbr[i] == '-' || nbr[i] == '+')
		i++;
	while (nbr[i] != '\0' && nbr[i] >= '0' && nbr[i] <= '9')
	{
		n = n * 10 - (nbr[i] - '0');
		i++;
	}
	if (neg == 1)
		return (n);
	return (-n);
}
