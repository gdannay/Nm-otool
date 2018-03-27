/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdannay <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 18:43:06 by gdannay           #+#    #+#             */
/*   Updated: 2018/03/27 15:11:43 by gdannay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_otool.h"

void			print_ar(void *ptr, t_arfile *first,
						struct ranlib *ranlib, uint32_t size)
{
	struct ar_hdr	*header;
	t_arfile		*tmp;
	uint32_t		i;
	int				name_size;

	i = 0;
	ft_printf("Archive : %s", first->ar_name);
	while (i < size)
	{
		if (first->to_display)
		{
			header = (struct ar_hdr *)(ptr + ranlib[i].ran_off);
			ft_printf("\n%s(%s):\n", first->ar_name, first->name);
			name_size = get_name_size(header->ar_name);
			analyse_file((void *)header + sizeof(struct ar_hdr)
							+ name_size, first->ar_name, 1);
		}
		tmp = first;
		first = first->next;
		ft_strdel(&(tmp->name));
		ft_strdel(&(tmp->ar_name));
		free(tmp);
		i++;
	}
	ft_printf("\n");
}
