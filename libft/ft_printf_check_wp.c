/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_wp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdannay <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 16:33:54 by gdannay           #+#    #+#             */
/*   Updated: 2017/12/11 16:41:42 by gdannay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		fill_wp(t_flag *tmp, va_list va)
{
	if (tmp->width == -2)
	{
		tmp->width = va_arg(va, int);
		if (tmp->width < 0)
		{
			tmp->minus = 1;
			tmp->width *= -1;
		}
	}
	if (tmp->width == -3)
	{
		va_arg(va, int);
		tmp->width = tmp->nb;
		if (tmp->width < 0)
		{
			tmp->minus = 1;
			tmp->width *= -1;
		}
	}
	if (tmp->precision == -2)
		tmp->precision = va_arg(va, int);
}

void		check_width(char *str, int *i, t_flag *new, int *ret)
{
	if (str[*i] == '*')
	{
		new->width = -2;
		*i = *i + 1;
		*ret = 1;
	}
	if (str[*i] == '.')
	{
		while (str[*i] == '.')
			*i = *i + 1;
		if (str[*i] == '*')
		{
			new->precision = -2;
			*i = *i + 1;
		}
		else if (str[*i] >= '0' && str[*i] <= '9')
		{
			new->precision = ft_atoi(str + *i);
			*i = *i + length_nbr(new->precision);
		}
		else
			new->precision = 0;
		*ret = 1;
	}
}

void		check_wp(char *str, int *i, t_flag *new)
{
	int ret;

	ret = 1;
	while (ret)
	{
		ret = 0;
		if (str[*i] > '0' && str[*i] <= '9')
		{
			if (new->width == -2)
			{
				new->width = -3;
				new->nb = ft_atoi(str + *i);
				*i = *i + length_nbr(new->nb);
			}
			else
			{
				new->width = ft_atoi(str + *i);
				*i = *i + length_nbr(new->width);
			}
			ret = 1;
		}
		check_width(str, i, new, &ret);
	}
}
