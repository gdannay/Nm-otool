/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdannay <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 10:38:34 by gdannay           #+#    #+#             */
/*   Updated: 2017/12/11 17:22:48 by gdannay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long long		atoi_base(char *str, char *input_b)
{
	int			i;
	int			neg;
	long long	n;

	i = 0;
	neg = 0;
	n = 0;
	if (str[i] == '-')
	{
		i++;
		neg = 1;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		n = n * ft_strlen(input_b) - (str[i] - '0');
		i++;
	}
	if (neg)
		return (n);
	return (-n);
}
