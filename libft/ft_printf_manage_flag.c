/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_flag.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdannay <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/26 13:40:36 by gdannay           #+#    #+#             */
/*   Updated: 2017/12/13 18:14:31 by gdannay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_type	g_typeconv[] =
{
	{'d', 1, 1},
	{'D', 1, 1},
	{'i', 1, 1},
	{'c', 1, 2},
	{'C', 8, 8},
	{'s', 2, 3},
	{'S', 9, 9},
	{'p', 3, 6},
	{'o', 4, 6},
	{'O', 4, 6},
	{'u', 4, 1},
	{'U', 4, 1},
	{'x', 6, 6},
	{'X', 6, 6},
};

static void		check_length(t_flag *new, char *str, int *i)
{
	while (str[*i] == 'h' || str[*i] == 'l' || str[*i] == 'z'
			|| str[*i] == 'j' || str[*i] == 't')
	{
		if (str[*i] == 'h' && str[*i + 1] == 'h')
		{
			*i = *i + 1;
			new->length = new->length < 1 ? 1 : new->length;
		}
		else if (str[*i] == 'h')
			new->length = new->length < 2 ? 2 : new->length;
		else if (str[*i] == 'l')
			new->length = new->length < 3 ? 3 : new->length;
		else if (str[*i] == 'l' && str[*i + 1] == 'l')
		{
			*i = *i + 1;
			new->length = new->length < 4 ? 4 : new->length;
		}
		else if (str[*i] == 'z')
			new->length = !(new->length) ? 6 : new->length;
		else if (str[*i] == 'j')
			new->length = !(new->length) ? 7 : new->length;
		else if (str[*i] == 't')
			new->length = !(new->length) ? 8 : new->length;
		*i = *i + 1;
	}
}

static void		manage_flag(char *str, int *i, t_flag **new)
{
	while (str[*i] == '-' || str[*i] == '+' ||
			str[*i] == ' ' || str[*i] == '0' || str[*i] == '#')
	{
		if (str[*i] == '-')
			(*new)->minus = 1;
		else if (str[*i] == '+')
			(*new)->plus = 1;
		else if (str[*i] == ' ')
			(*new)->space = 1;
		else if (str[*i] == '0')
			(*new)->zero = 1;
		else if (str[*i] == '#')
			(*new)->hash = 1;
		if ((*new)->minus == 1)
			(*new)->zero = 0;
		*i = *i + 1;
	}
}

static void		check(char *str, int *i, t_flag **new)
{
	while (str[*i] == '.' || str[*i] == ' ' || str[*i] == '#' || str[*i] == '0'
			|| str[*i] == '+' || str[*i] == '-')
	{
		if (str[*i] == '.')
			check_wp(str, i, *new);
		else
			manage_flag(str, i, new);
	}
}

static void		correction_lsc(t_flag *new, int j)
{
	if (new->type != 0 && j >= 14)
	{
		new->inttype = 10;
		new->intdisplay = 2;
		new->nb = (long long)new->type;
	}
	if (new->type == 'c' && new->length == 3)
	{
		new->inttype = 8;
		new->intdisplay = 8;
	}
	if (new->type == 's' && new->length == 3)
	{
		new->inttype = 9;
		new->intdisplay = 9;
	}
}

t_flag			*check_carac(char *str, int *i)
{
	t_flag		*new;
	int			j;

	j = 0;
	if ((new = create_flag()) == NULL)
		return (NULL);
	manage_flag(str, i, &new);
	check_wp(str, i, new);
	check_length(new, str, i);
	check(str, i, &new);
	new->type = str[*i];
	while (new->type != g_typeconv[j].type && j < 14)
		j++;
	if (j < 14)
	{
		new->inttype = g_typeconv[j].conv;
		new->intdisplay = g_typeconv[j].display;
	}
	correction_lsc(new, j);
	return (new);
}
