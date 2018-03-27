/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_wstring.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdannay <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 10:50:28 by gdannay           #+#    #+#             */
/*   Updated: 2018/01/03 20:26:35 by gdannay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*zero_precision(t_flag *tmp)
{
	char	*tmptxt;
	int		rep;
	int		prec;
	char	*t2;

	tmptxt = NULL;
	rep = 0;
	prec = 0;
	while (tmp->wst[prec] && rep <= tmp->precision)
	{
		tmp->nb = tmp->wst[prec];
		if ((t2 = ltoa_base(tmp, BINA)) == NULL)
			return (NULL);
		rep += compute_rep(t2);
		ft_strdel(&t2);
		prec++;
	}
	if (rep > tmp->precision)
		tmptxt = ft_bchar(1, (size_t)prec - 1);
	else
		tmptxt = ft_bchar(1, (size_t)prec);
	if (tmptxt == NULL)
		return (NULL);
	return (tmptxt);
}

static int		display_wstring(t_flag *tmp, char *buff)
{
	int length;
	int i;
	int j;

	i = 0;
	length = 0;
	j = 0;
	while (buff[i] != '\0')
	{
		if (buff[i] == 1)
		{
			tmp->nb = (long long)tmp->wst[j];
			length += manage_uni(tmp, buff);
			j++;
		}
		else
		{
			ft_putchar(buff[i]);
			length++;
		}
		i++;
	}
	buff[0] = '\0';
	return (length);
}

static char		*manage_tmptxt(t_flag *tmp)
{
	char *tmptxt;

	tmptxt = NULL;
	if (tmp->wst == NULL)
		tmptxt = ft_strdup("(null)");
	else if (tmp->precision > 0)
		tmptxt = zero_precision(tmp);
	else
		tmptxt = ft_bchar(1, ft_wstrlen(tmp->wst));
	if (tmptxt == NULL)
		return (NULL);
	return (tmptxt);
}

static void		get_rep(t_flag *tmp, int *rep, int i)
{
	char	*tmptxt;

	tmp->nb = tmp->wst[i];
	if ((tmptxt = ltoa_base(tmp, BINA)) == NULL)
		return ;
	*rep = *rep + compute_rep(tmptxt) - 1;
	ft_strdel(&tmptxt);
}

int				manage_wstring(t_flag *tmp, char *buff)
{
	char	*new;
	int		i;
	int		rep;
	int		l;

	i = -1;
	rep = 0;
	l = 0;
	if (tmp->precision == 0)
		return (display_flag(NULL, tmp, buff));
	if ((new = manage_tmptxt(tmp)) == NULL)
		return (0);
	if (tmp->wst == NULL)
		return (display_flag(new, tmp, buff));
	while (new[++i] && tmp->wst[i] != '\0')
		get_rep(tmp, &rep, i);
	l += print_buff(buff);
	tmp->width -= rep;
	l += manage_buff(buff, new, ft_strlen(new));
	ft_strdel(&new);
	l += display_width(buff, tmp, 0);
	return (l + display_wstring(tmp, buff));
}
