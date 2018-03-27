/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_wp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdannay <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 11:13:23 by gdannay           #+#    #+#             */
/*   Updated: 2018/01/03 20:29:05 by gdannay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			display_width(char *buff, t_flag *tmp, int index)
{
	if ((int)ft_strlen(buff) - index < tmp->width)
	{
		if (tmp->minus == 1)
			return (add_char_left(buff, ' ', &index,
						(size_t)tmp->width - ft_strlen(buff) + index));
		else if (tmp->zero == 1)
		{
			if (tmp->type == 'p')
				return (add_char_left(buff, '0', &index,
							(size_t)tmp->width - ft_strlen(buff) + index));
			else
				return (add_char_right(buff, '0', index,
							(size_t)tmp->width - ft_strlen(buff) + index));
		}
		else
			return (add_char_right(buff, ' ',
						index, (size_t)tmp->width - ft_strlen(buff) + index));
	}
	return (0);
}

static int	display_plus(char *buff, t_flag *tmp, int index)
{
	int		i;

	i = 0;
	if (tmp->zero == 1 && buff[index] == '0')
		buff[index] = '+';
	else if (buff[index] == ' ')
	{
		while (buff[index + i] && buff[index + i] == ' ')
			i++;
		buff[index + i - 1] = '+';
	}
	else
	{
		if ((int)ft_strlen(buff) - i == tmp->width)
			buff[(int)ft_strlen(buff) - 1] = '\0';
		return (add_right(buff, "+", index, 1));
	}
	return (0);
}

static int	correction_neg(char *buff, t_flag *tmp, int index)
{
	int i;

	i = 1;
	while (buff[index + i] && buff[index + i] == buff[index])
		i++;
	if (buff[index] == '0')
	{
		buff[index + i] = '0';
		if (tmp->zero == 1 || (int)ft_strlen(buff) - index == tmp->precision)
			buff[index] = '-';
		else
			return (add_right(buff, "-", index, 1));
	}
	else if (buff[index] == ' ')
	{
		if (buff[index + i] && buff[index + i] == '0')
			buff[index + i] = '-';
		i++;
		while (buff[index + i] && buff[index + i] != '-')
			i++;
		if (buff[index + i])
			buff[index + i] = '0';
	}
	return (0);
}

int			correction_sign(char *buff, t_flag *tmp, int index)
{
	if (tmp->intdisplay == 1 && tmp->type != 'u' && tmp->type != 'U')
	{
		if (tmp->nb < 0)
			return (correction_neg(buff, tmp, index));
		else if (tmp->nb >= 0 && tmp->plus == 1)
			return (display_plus(buff, tmp, index));
		else if (tmp->space && tmp->nb >= 0 &&
				tmp->width <= (int)ft_strlen(buff) - index)
			return (add_right(buff, " ", index, 1));
	}
	return (0);
}
