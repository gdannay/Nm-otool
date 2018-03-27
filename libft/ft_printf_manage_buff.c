/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_buff.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdannay <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 10:00:11 by gdannay           #+#    #+#             */
/*   Updated: 2017/12/13 19:04:26 by gdannay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		add_char_left(char *buff, char c, int *index, size_t length)
{
	int l;
	int i;

	l = 0;
	i = 0;
	if ((size_t)BUFF_SIZE - ft_strlen(buff) < length)
	{
		*index = 0;
		l = print_buff(buff);
	}
	while (buff[i] != '\0')
		i++;
	while (length > 0)
	{
		buff[i] = c;
		i++;
		length--;
	}
	buff[i] = '\0';
	return (l);
}

int		add_char_right(char *buff, char c, int index, size_t length)
{
	int i;
	int l;

	l = 0;
	i = (int)ft_strlen(buff) + (int)length;
	if ((size_t)BUFF_SIZE - ft_strlen(buff) < length)
	{
		index = 0;
		l = print_buff(buff);
	}
	while (i - (int)length >= index)
	{
		buff[i] = buff[i - length];
		i--;
	}
	i = 0;
	while (length > 0)
	{
		buff[index] = c;
		index++;
		length--;
	}
	return (l);
}

int		add_right(char *buff, char *str, int index, size_t length)
{
	int i;
	int l;

	l = 0;
	i = (int)ft_strlen(buff) + (int)length;
	if ((size_t)BUFF_SIZE - ft_strlen(buff) < length)
		l = print_buff(buff);
	while (i - (int)length >= index)
	{
		buff[i] = buff[i - length];
		i--;
	}
	i = 0;
	i = 0;
	while (length > 0)
	{
		buff[index] = (char)str[i];
		index++;
		i++;
		length--;
	}
	return (l);
}

int		print_buff(char *buff)
{
	int		i;
	int		length;

	i = 0;
	length = (int)ft_strlen(buff);
	if (length == 0)
		return (0);
	write(1, buff, (size_t)length);
	while (buff && buff[i])
	{
		buff[i] = '\0';
		i++;
	}
	return (length);
}

int		manage_buff(char *buff, char *str, size_t length)
{
	int l;

	l = 0;
	if ((size_t)BUFF_SIZE - ft_strlen(buff) > length)
		buff = ft_strncat(buff, str, length);
	else if ((size_t)BUFF_SIZE - ft_strlen(buff) <= length)
	{
		l = print_buff(buff);
		if (BUFF_SIZE <= length)
		{
			write(1, str, length);
			return (l + (int)length);
		}
		else
			buff = ft_strncat(buff, str, length);
	}
	return (l);
}
