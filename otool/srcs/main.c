/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nm.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdannay <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 10:43:24 by gdannay           #+#    #+#             */
/*   Updated: 2018/03/27 15:27:42 by gdannay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_otool.h"

static void		*load_file(char *file)
{
	int			fd;
	void		*ptr;
	struct stat buf;

	if ((fd = open(file, O_RDONLY)) == -1)
	{
		write(2, "Not a valid file\n", 17);
		return (NULL);
	}
	if (fstat(fd, &buf) < 0)
	{
		close(fd);
		write(2, "Infos could not be loaded\n", 26);
		return (NULL);
	}
	if ((ptr = mmap(0, buf.st_size,
				PROT_READ, MAP_PRIVATE, fd, 0)) == MAP_FAILED)
	{
		close(fd);
		write(2, "Mapping failed\n", 15);
		return (NULL);
	}
	return (ptr);
}

static void		handler_fat(void *ptr, char *name, int is_big_endian)
{
	struct fat_header	*header;
	unsigned long		nb;
	struct fat_arch		*arch;
	uint32_t			nb_arch;

	header = (struct fat_header *)ptr;
	arch = ptr + sizeof(struct fat_header);
	nb = 0;
	nb_arch = endian_32(header->nfat_arch, is_big_endian);
	while (nb < nb_arch)
	{
		if (endian_32(arch->cputype, is_big_endian) == CPU_TYPE_X86_64)
			analyse_file(ptr + swap_32_bytes(arch->offset), name, 0);
		arch = (void *)arch + sizeof(struct fat_arch);
		nb++;
	}
}

void			analyse_file(void *ptr, char *name, int ar)
{
	unsigned int	magic_nb;

	magic_nb = *(int *)ptr;
	if (magic_nb == MH_MAGIC_64)
		handler_64(ptr, name, 0, ar);
	else if (magic_nb == MH_MAGIC)
		handler_32(ptr, name, 0, ar);
	else if (magic_nb == MH_CIGAM_64)
		handler_64(ptr, name, 1, ar);
	else if (magic_nb == MH_CIGAM)
		handler_32(ptr, name, 1, ar);
	else if (magic_nb == FAT_MAGIC)
		handler_fat(ptr, name, 0);
	else if (magic_nb == FAT_CIGAM)
		handler_fat(ptr, name, 1);
	else if (!ft_strncmp(ptr, ARMAG, SARMAG))
		handler_ar(ptr, name);
	else
		write(2, "Not an object file\n", 19);
}

int				main(int ac, char **av)
{
	void	*ptr;
	int		i;

	i = 0;
	if (ac < 2)
	{
		write(2, "Usage: ./ft_otool [files]\n", 26);
		return (EXIT_FAILURE);
	}
	if (ac == 2)
	{
		if ((ptr = load_file(av[1])) == NULL)
			return (EXIT_FAILURE);
		analyse_file(ptr, av[1], 0);
		return (EXIT_SUCCESS);
	}
	while (av[++i])
	{
		if ((ptr = load_file(av[i])))
			analyse_file(ptr, av[i], 0);
		if (i < ac)
			ft_printf("\n");
	}
	return (EXIT_SUCCESS);
}
