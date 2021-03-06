/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   symbols_64.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdannay <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 18:39:28 by gdannay           #+#    #+#             */
/*   Updated: 2018/03/27 16:16:36 by gdannay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_otool.h"

static void				print_content(void *ptr,
						struct section *text, int is_big_endian, int ar)
{
	uint64_t	size;
	int			i;
	int			rest;
	uint64_t	content;

	size = 0;
	while (size * sizeof(uint64_t) < endian_32(text->size, is_big_endian))
	{
		i = 0;
		if (size % 2 == 0)
			ft_printf("%08llx\t", text->addr + size * sizeof(uint64_t));
		rest = endian_64(text->size, is_big_endian) - size * sizeof(uint64_t);
		content = *((uint64_t *)(ptr + text->offset) + size);
		while ((unsigned long)i < sizeof(uint64_t) && i < rest)
		{
			ft_printf("%02llx ", content % 256);
			content /= 256;
			i++;
		}
		if (size % 2 && (!ar || (ar && i < rest)))
			ft_printf("\n");
		size++;
	}
	if (!ar && size % 2)
		ft_printf("\n");
}

static struct section	*search_text(struct load_command *lc,
							uint32_t nb, int is_big_endian)
{
	struct segment_command	*seg;
	struct section			*sec;
	long					i;
	uint32_t				j;

	i = -1;
	j = -1;
	while (++i < (long)nb)
	{
		if (lc->cmd == LC_SEGMENT)
		{
			seg = (struct segment_command *)lc;
			sec = (struct section *)(&(seg[1]));
			if (!ft_strcmp(sec->segname, SEG_TEXT))
			{
				while (++j < seg->nsects && ft_strcmp(sec->sectname, SECT_TEXT))
					sec = (void *)sec + sizeof(*sec);
				if (!ft_strcmp(sec->sectname, SECT_TEXT))
					return (sec);
				return (NULL);
			}
			lc = (void *)lc + endian_32(lc->cmdsize, is_big_endian);
		}
	}
	return (NULL);
}

void					handler_32(void *ptr, char *name,
						int is_big_endian, int ar)
{
	struct mach_header		*header;
	struct load_command		*lc;
	uint64_t				nb;
	struct section			*text;

	header = (struct mach_header *)ptr;
	lc = ptr + sizeof(struct mach_header);
	nb = endian_32(header->ncmds, is_big_endian);
	if ((text = search_text(lc, nb, is_big_endian)) == NULL)
		return ;
	if (ar)
		ft_printf("Contents of (__TEXT,__text) section\n");
	else
		ft_printf("%s:\nContents of (__TEXT,__text) section\n", name);
	print_content(ptr, text, is_big_endian, ar);
}
