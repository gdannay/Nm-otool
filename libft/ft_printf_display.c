/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdannay <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 15:03:31 by gdannay           #+#    #+#             */
/*   Updated: 2018/01/03 20:38:28 by gdannay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		manage_display(t_flag *tmp, char *buff)
{
	int		length;

	length = 0;
	if (tmp->intdisplay == 1 || tmp->intdisplay == 6)
		length = manage_nb(tmp, buff);
	else if (tmp->intdisplay == 9)
		length = manage_wstring(tmp, buff);
	else if (tmp->intdisplay == 8)
		length = manage_uni(tmp, buff);
	else if (tmp->intdisplay == 2 || tmp->intdisplay == 9)
		length = manage_char(tmp, buff);
	else if (tmp->intdisplay == 3)
		length = manage_string(tmp, buff);
	return (length);
}

static int		display_normal(char *str, int *i, char *buff)
{
	int length;
	int j;

	length = 0;
	j = *i;
	while (str[*i] && str[*i] != '%')
	{
		length++;
		*i = *i + 1;
	}
	return (manage_buff(buff, str + j, (size_t)(*i - j)));
}

static void		manage_undefined(char *str, int *i, t_flag *tmp)
{
	*i = *i + 1;
	while (str[*i] && str[*i] != tmp->type)
		*i = *i + 1;
	if (tmp && str[*i] == tmp->type)
		tmp = tmp->next;
}

static int		print_arg(char *buff, t_flag **tmp, char *str, int *i)
{
	int length;

	length = 0;
	length = manage_display(*tmp, buff);
	*i = *i + 1;
	while (str[*i + 1] && str[*i] != (*tmp)->type)
		*i = *i + 1;
	*tmp = (*tmp)->next;
	*i = *i + 1;
	return (length);
}

int				display(char *str, t_flag *flag)
{
	int		i;
	int		length;
	t_flag	*tmp;
	char	buff[BUFF_SIZE];

	i = 0;
	length = 0;
	buff[0] = '\0';
	tmp = flag;
	while (str && str[i] != '\0')
	{
		if (str[i] == '%' && str[i + 1] && tmp->inttype != 0)
			length += print_arg(buff, &tmp, str, &i);
		else if (str[i] == '%' && ((!tmp) || tmp->inttype == 0))
			manage_undefined(str, &i, tmp);
		else
			length += display_normal(str, &i, buff);
	}
	length += print_buff(buff);
	return (length);
}
