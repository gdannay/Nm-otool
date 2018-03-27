/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdannay <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 10:02:16 by gdannay           #+#    #+#             */
/*   Updated: 2017/12/13 18:12:06 by gdannay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_flag		*parse_str(char *str)
{
	t_flag		*flag;
	t_flag		*tmp;
	t_flag		*tmp2;
	int			i;

	flag = NULL;
	tmp = NULL;
	tmp2 = NULL;
	i = 0;
	while (str && str[i] != '\0')
	{
		if (str[i] == '%' && str[i + 1])
		{
			i++;
			if ((tmp = check_carac(str, &i)) == NULL)
				return (NULL);
			if (flag == NULL)
				flag = tmp;
			else
				tmp2->next = tmp;
			tmp2 = tmp;
		}
		i++;
	}
	return (flag);
}

static void			fill_unsigned(va_list va, t_flag *tmp)
{
	if (tmp->type == 'U')
		tmp->unb = (unsigned long long)va_arg(va, unsigned long long);
	else if (tmp->type == 'O')
		tmp->unb = va_arg(va, unsigned long);
	else if (tmp->length == 1)
		tmp->unb = (unsigned char)va_arg(va, int);
	else if (tmp->length == 2)
		tmp->unb = (unsigned short)va_arg(va, int);
	else if (tmp->length == 3)
		tmp->unb = va_arg(va, unsigned long);
	else if (tmp->length == 4)
		tmp->unb = va_arg(va, unsigned long long);
	else if (tmp->length == 6)
		tmp->unb = va_arg(va, size_t);
	else if (tmp->length == 7)
		tmp->unb = va_arg(va, intmax_t);
	else
		tmp->unb = va_arg(va, unsigned int);
}

static void			fill_int(va_list va, t_flag *tmp)
{
	if (tmp->type == 'D')
		tmp->nb = va_arg(va, long);
	else if (tmp->length == 1)
		tmp->nb = (char)va_arg(va, int);
	else if (tmp->length == 2)
		tmp->nb = (short)va_arg(va, int);
	else if (tmp->length == 3)
		tmp->nb = va_arg(va, long);
	else if (tmp->length == 4)
		tmp->nb = va_arg(va, long long);
	else if (tmp->length == 6)
		tmp->nb = va_arg(va, size_t);
	else if (tmp->length == 7)
		tmp->nb = va_arg(va, intmax_t);
	else
		tmp->nb = va_arg(va, int);
}

static void			fill_content(va_list va, t_flag *tmp)
{
	if (tmp->width == -2 || tmp->precision == -2 || tmp->width == -3)
		fill_wp(tmp, va);
	if (tmp->inttype == 1 || (tmp->inttype == 6 && tmp->length == 0))
		fill_int(va, tmp);
	else if (tmp->inttype == 4 || tmp->inttype == 6)
		fill_unsigned(va, tmp);
	else if (tmp->inttype == 2)
		tmp->st = ft_strdup(va_arg(va, char *));
	else if (tmp->inttype == 3)
		tmp->unb = (unsigned long long)va_arg(va, void *);
	else if (tmp->inttype == 8)
		tmp->nb = va_arg(va, wchar_t);
	else if (tmp->inttype == 9)
		tmp->wst = ft_wstrdup(va_arg(va, wchar_t *));
}

int					ft_printf(char *str, ...)
{
	va_list		va;
	t_flag		*flag;
	t_flag		*tmp;
	int			length;

	va_start(va, str);
	length = 0;
	if ((flag = parse_str(str)) == NULL && str == NULL)
		return (0);
	tmp = flag;
	while (tmp)
	{
		fill_content(va, tmp);
		tmp = tmp->next;
	}
	length = display(str, flag);
	free_lst(&flag);
	va_end(va);
	return (length);
}
