/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_flag.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdannay <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 10:23:15 by gdannay           #+#    #+#             */
/*   Updated: 2018/01/03 20:47:38 by gdannay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			display_precision(char *buff, t_flag *tmp, int index)
{
	int length;

	length = 0;
	if (tmp->nb < 0 && tmp->precision > 0)
		tmp->precision = tmp->precision + 1;
	if (tmp->precision >= 0 && (tmp->intdisplay == 1 || tmp->intdisplay == 6))
		tmp->zero = 0;
	if ((int)ft_strlen(buff) - index < tmp->precision
			&& (tmp->intdisplay == 1 || tmp->intdisplay == 6))
		length = add_char_right(buff, '0', index,
					tmp->precision - (int)ft_strlen(buff) + index);
	return (length);
}

static int	display_hash_blank(char *buff, t_flag *tmp, int index)
{
	if (tmp->type == 'x' || tmp->type == 'p')
		return (add_right(buff, "0x", index, 2));
	else if (tmp->type == 'X')
		return (add_right(buff, "0X", index, 2));
	else if ((tmp->type == 'o' || tmp->type == 'O')
			&& ((int)ft_strlen(buff) - index < tmp->precision
				|| tmp->precision <= 0))
		return (add_right(buff, "0", index, 1));
	return (0);
}

static int	display_hash_zero(char *buff, t_flag *tmp, int index)
{
	if (buff[index] == '0' && buff[index + 1] == '0')
		buff[index + 1] = tmp->type;
	else
	{
		if (buff[index] == '0' && buff[index + 1] != '0')
		{
			buff[index] = tmp->type;
			return (add_right(buff, "0", index, 1));
		}
		else if (buff[0] != 0)
		{
			if (tmp->type == 'x')
				return (add_right(buff, "0x", index, 1));
			else if (tmp->type == 'X')
				return (add_right(buff, "0X", index, 1));
		}
	}
	return (0);
}

int			display_flag(char *new, t_flag *tmp, char *buff)
{
	int		index;
	int		l;

	index = ft_strlen(buff);
	l = manage_buff(buff, new, ft_strlen(new));
	ft_strdel(&new);
	if (ft_strlen(buff) < (size_t)index)
		index = 0;
	l += display_precision(buff, tmp, index);
	if ((tmp->nb == 0 && tmp->unb == 0) && (tmp->type == 'x'
				|| tmp->type == 'X' ||
				(tmp->type == 'o' && tmp->precision != 0)))
		tmp->hash = 0;
	if (tmp->space == 1 && tmp->plus == 0
			&& (tmp->intdisplay == 1 || tmp->intdisplay == 6))
		tmp->width = tmp->width - 1;
	if (tmp->type == 'p' ||
			(tmp->intdisplay == 6 && tmp->hash == 1 && tmp->zero == 0))
		l += display_hash_blank(buff, tmp, index);
	l += display_width(buff, tmp, index);
	if ((tmp->type == 'X' || tmp->type == 'x')
			&& tmp->hash == 1 && tmp->zero == 1)
		l += display_hash_zero(buff, tmp, index);
	l += correction_sign(buff, tmp, index);
	return (l);
}
