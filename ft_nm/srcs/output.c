/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdannay <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 18:43:06 by gdannay           #+#    #+#             */
/*   Updated: 2018/03/27 14:44:53 by gdannay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"

static t_sym	*order_alpha(t_sym *first)
{
	t_sym	*tmp;
	t_sym	*to_return;

	tmp = first->next;
	to_return = first;
	while (tmp)
	{
		if (ft_strcmp(to_return->name, tmp->name) > 0)
			to_return = tmp;
		tmp = tmp->next;
	}
	return (to_return);
}

void			print_output(t_sym *first, int is_32)
{
	t_sym	*tmp;

	while (first)
	{
		tmp = order_alpha(first);
		if (tmp->type != 'U' && tmp->type != 'u' && is_32)
			ft_printf("%08llx %c %s\n", tmp->value, tmp->type, tmp->name);
		else if (is_32)
			ft_printf("%10c %s\n", tmp->type, tmp->name);
		else if (tmp->type != 'U' && tmp->type != 'u')
			ft_printf("%016llx %c %s\n", tmp->value, tmp->type, tmp->name);
		else
			ft_printf("%18c %s\n", tmp->type, tmp->name);
		if (tmp == first)
			first = first->next;
		else if (tmp->next == NULL)
			tmp->prev->next = NULL;
		else
		{
			tmp->next->prev = tmp->prev;
			tmp->prev->next = tmp->next;
		}
		free(tmp);
	}
}

void			print_ar(void *ptr, t_arfile *first,
						struct ranlib *ranlib, uint32_t size)
{
	struct ar_hdr	*header;
	t_arfile		*tmp;
	uint32_t		i;
	int				name_size;

	i = 0;
	while (i < size)
	{
		if (first->to_display)
		{
			header = (struct ar_hdr *)(ptr + ranlib[i].ran_off);
			ft_printf("\n%s(%s):\n", first->ar_name, first->name);
			name_size = get_name_size(header->ar_name);
			analyse_file((void *)header + sizeof(struct ar_hdr)
							+ name_size, first->ar_name);
		}
		tmp = first;
		first = first->next;
		ft_strdel(&(tmp->name));
		ft_strdel(&(tmp->ar_name));
		free(tmp);
		i++;
	}
}

t_sym			*init_sym(t_sym *prev)
{
	t_sym	*new;

	if ((new = (t_sym *)malloc(sizeof(t_sym))) == NULL)
		return (NULL);
	new->prev = prev;
	if (prev)
		prev->next = new;
	new->next = NULL;
	new->type = 0;
	return (new);
}
