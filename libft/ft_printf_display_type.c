/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_type.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdannay <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/02 18:22:57 by gdannay           #+#    #+#             */
/*   Updated: 2017/12/13 19:10:53 by gdannay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*manage_neg(t_flag *tmp, char *new, int taille, int n)
{
	char		*t2;
	char		*tmptxt;

	tmptxt = new;
	if ((t2 = ft_bchar('0', 8)) == NULL)
		return (NULL);
	tmp->nb = 4294967296 - taille;
	if (tmp->type == 'x')
		new = ltoa_base(tmp, HEXAMIN);
	else if (tmp->type == 'X')
		new = ltoa_base(tmp, HEXAMAJ);
	if (new == NULL)
		return (NULL);
	tmp->nb = n + 4294967296 * taille;
	if (tmp->nb == 0)
		new = ft_strjoin(new, ft_bchar('0', 8));
	else if (tmp->type == 'x')
		new = ft_strjoin(new, ltoa_base(tmp, HEXAMIN));
	else if (tmp->type == 'X')
		new = ft_strjoin(new, ltoa_base(tmp, HEXAMAJ));
	if (new == NULL)
		return (NULL);
	ft_strdel(&tmptxt);
	ft_strdel(&t2);
	return (new);
}

static char		*manage_hexa(t_flag *tmp)
{
	char *new;

	new = NULL;
	if (tmp->nb <= -4294967296)
	{
		new = manage_neg(tmp, new,
				size_hexa(tmp->nb), tmp->nb);
	}
	else
	{
		tmp->nb += 4294967296;
		if (tmp->type == 'x')
			new = ltoa_base(tmp, HEXAMIN);
		else if (tmp->type == 'X')
			new = ltoa_base(tmp, HEXAMAJ);
	}
	if (new == NULL)
		return (NULL);
	return (new);
}

int				manage_nb(t_flag *tmp, char *buff)
{
	char	*new;

	new = NULL;
	if (tmp->inttype == 6 && tmp->nb < 0)
		new = manage_hexa(tmp);
	else if (tmp->inttype == 1)
		new = ltoa_base(tmp, DECI);
	else if (tmp->type == 'x' && tmp->length == 0)
		new = ltoa_base(tmp, HEXAMIN);
	else if (tmp->type == 'X' && tmp->length == 0)
		new = ltoa_base(tmp, HEXAMAJ);
	else if (tmp->type == 'x' || tmp->type == 'p')
		new = utoa_base(tmp, HEXAMIN);
	else if (tmp->type == 'X')
		new = utoa_base(tmp, HEXAMAJ);
	else if (tmp->type == 'u' || tmp->type == 'U' || tmp->type == 'D')
		new = utoa_base(tmp, DECI);
	else if (tmp->type == 'o' || tmp->type == 'O')
		new = utoa_base(tmp, OCTA);
	if (new == NULL)
		return (0);
	if (tmp->precision == 0 && ft_strncmp(new, "0", 1) == 0)
		ft_strdel(&new);
	return (display_flag(new, tmp, buff));
}

int				manage_string(t_flag *tmp, char *buff)
{
	char	*tmptxt;

	if (tmp->st == NULL)
	{
		if ((tmp->st = ft_strdup("(null)")) == NULL)
			return (0);
	}
	if (tmp->precision == 0)
		return (display_flag(NULL, tmp, buff));
	else if (tmp->precision > 0)
	{
		if ((tmptxt = ft_strndup(tmp->st, (size_t)tmp->precision)) == NULL)
			return (0);
		return (display_flag(tmptxt, tmp, buff));
	}
	else
	{
		if ((tmptxt = ft_strdup(tmp->st)) == NULL)
			return (0);
		return (display_flag(tmptxt, tmp, buff));
	}
}

int				manage_char(t_flag *tmp, char *buff)
{
	char	*c;

	c = NULL;
	if (tmp->nb == 0)
		return (display_0(tmp, c, buff));
	else
	{
		if ((c = chartostr(tmp->nb)) == NULL)
			return (0);
		return (display_flag(c, tmp, buff));
	}
}
