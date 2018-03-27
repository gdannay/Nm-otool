/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   symbols_64.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdannay <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 18:39:28 by gdannay           #+#    #+#             */
/*   Updated: 2018/03/27 15:03:27 by gdannay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"

static char		compare_type(struct section_64 *sec, uint64_t index)
{
	if (!(ft_strcmp(sec[index].sectname, "__text")))
		return ('t');
	else if (!(ft_strcmp(sec[index].sectname, "__bss")))
		return ('b');
	else if (!(ft_strcmp(sec[index].sectname, "__data")))
		return ('d');
	return ('s');
}

static char		get_type(struct nlist_64 sym, void *ptr,
				int is_big_endian, struct mach_header_64 *header)
{
	struct load_command			*lc;
	struct segment_command_64	*segment;
	uint64_t					i;
	int							nb_sec;
	uint64_t					nb;

	lc = (struct load_command *)(ptr + sizeof(struct mach_header_64));
	i = 0;
	nb_sec = 0;
	nb = endian_64(header->ncmds, is_big_endian);
	while (i < nb)
	{
		if (lc->cmd == LC_SEGMENT_64)
		{
			segment = (struct segment_command_64 *)lc;
			if (nb_sec + endian_64(segment->nsects, is_big_endian)
					>= endian_64(sym.n_sect, is_big_endian))
				return (compare_type((struct section_64 *)(&(segment[1])),
							sym.n_sect - nb_sec - 1));
				nb_sec += endian_64(segment->nsects, is_big_endian);
		}
		i++;
		lc = (void *)lc + endian_32(lc->cmdsize, is_big_endian);
	}
	return ('s');
}

static t_sym	*create_new_symbol(t_sym *prev, struct nlist_64 sym,
				int is_big_endian, void *ptr)
{
	t_sym			*tmp;

	if ((tmp = init_sym(prev)) == NULL)
		return (NULL);
	if ((sym.n_type & N_TYPE) == N_UNDF)
		tmp->type = 'u';
	else if ((sym.n_type & N_TYPE) == N_ABS)
		tmp->type = 'a';
	else if (sym.n_sect != NO_SECT)
		tmp->type = get_type(sym, ptr, is_big_endian,
				(struct mach_header_64 *)ptr);
	if (sym.n_type & N_EXT)
		tmp->type = toupper(tmp->type);
	tmp->value = endian_64(sym.n_value, is_big_endian);
	return (tmp);
}

static t_sym	*get_syms(struct symtab_command *sym, void *ptr, int is_b_e)
{
	uint32_t		i;
	struct nlist_64	*array;
	char			*string_table;
	t_sym			*first;
	t_sym			*tmp;

	i = 0;
	array = ptr + endian_32(sym->symoff, is_b_e);
	string_table = ptr + endian_32(sym->stroff, is_b_e);
	tmp = NULL;
	first = NULL;
	while (i < endian_32(sym->nsyms, is_b_e))
	{
		if (!(array[i].n_type & N_STAB))
		{
			if (!((tmp = create_new_symbol(tmp, array[i], is_b_e, ptr))) ||
			(tmp->name = ft_strdup(string_table +
							endian_64(array[i].n_un.n_strx, is_b_e))) == NULL)
				return (NULL);
		}
		if (first == NULL)
			first = tmp;
		i++;
	}
	return (first);
}

void			handler_64(void *ptr, int is_big_endian)
{
	struct mach_header_64		*header;
	struct load_command			*lc;
	uint64_t					i;
	t_sym						*first;
	uint64_t					nb;

	i = 0;
	first = NULL;
	header = (struct mach_header_64 *)ptr;
	lc = ptr + sizeof(struct mach_header_64);
	nb = endian_32(header->ncmds, is_big_endian);
	while (i < nb)
	{
		if (lc->cmd == LC_SYMTAB)
		{
			if ((first = get_syms((struct symtab_command *)lc,
							ptr, is_big_endian)) == NULL)
				return ;
			break ;
		}
		lc = (void *)lc + endian_64(lc->cmdsize, is_big_endian);
		i++;
	}
	print_output(first, 0);
}
