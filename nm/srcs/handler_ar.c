/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_ar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdannay <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 16:10:59 by gdannay           #+#    #+#             */
/*   Updated: 2018/04/18 13:49:09 by gdannay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"

int				get_name_size(char *str)
{
	if (!ft_strncmp(str, AR_EFMT1, 3))
		return (ft_atoi(str + 3));
	return (0);
}

static char		*get_name(struct ar_hdr *header, int name_size)
{
	int	end;

	end = 0;
	if (header == NULL)
		return (NULL);
	if (name_size == 0)
	{
		while (header->ar_name[end] && header->ar_name[end] != '/')
			end++;
		return (ft_strsub(header->ar_name, 0, end));
	}
	return (ft_strdup((char *)header + sizeof(struct ar_hdr)));
}

static void		check_double(t_arfile *first)
{
	t_arfile	*tmp;
	t_arfile	*parse;

	tmp = first;
	while (tmp)
	{
		tmp->to_display = 1;
		tmp = tmp->next;
	}
	tmp = first;
	while (tmp)
	{
		parse = tmp->next;
		while (parse)
		{
			if (!ft_strcmp(parse->name, tmp->name))
				parse->to_display = 0;
			parse = parse->next;
		}
		tmp = tmp->next;
	}
}

static t_arfile	*parse_object_list(void *ptr, struct ranlib *ranlib,
									uint32_t size, char *ar_name)
{
	int					i;
	t_arfile			*first;
	t_arfile			*tmp;
	t_arfile			*prev;
	struct ar_hdr		*header;

	i = -1;
	first = NULL;
	prev = NULL;
	while (++i < (int)size)
	{
		header = (struct ar_hdr *)(ptr + ranlib[i].ran_off);
		if (!(tmp = (t_arfile *)malloc(sizeof(t_arfile)))
		|| !(tmp->name = get_name(header, get_name_size(header->ar_name)))
		|| !(tmp->ar_name = ft_strdup(ar_name)))
			return (NULL);
		tmp->next = NULL;
		if (first == NULL)
			first = tmp;
		if (prev)
			prev->next = tmp;
		prev = tmp;
	}
	check_double(first);
	return (first);
}

void			handler_ar(void *ptr, char *name)
{
	struct ar_hdr	*header;
	struct ranlib	*ranlib;
	int				name_size;
	uint32_t		size;
	t_arfile		*first;

	header = (struct ar_hdr *)(ptr + SARMAG);
	name_size = get_name_size(header->ar_name);
	size = *((uint32_t *)((void *)header + sizeof(struct ar_hdr) + name_size));
	size /= sizeof(struct ranlib);
	ranlib = (struct ranlib *)((void *)header +
			sizeof(struct ar_hdr) + name_size + sizeof(uint32_t));
	if ((first = parse_object_list(ptr, ranlib, size, name)) == NULL)
		return ;
	print_ar(ptr, first, ranlib, size);
}
