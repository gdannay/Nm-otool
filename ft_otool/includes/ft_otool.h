/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_otool.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdannay <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 15:11:05 by gdannay           #+#    #+#             */
/*   Updated: 2018/03/27 15:11:19 by gdannay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_OTOOL_H
# define FT_OTOOL_H

# include "../../libft/libft.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <sys/mman.h>
# include <mach-o/loader.h>
# include <mach-o/nlist.h>
# include <mach-o/fat.h>
# include <mach-o/ranlib.h>
# include <ar.h>

# define BIT_2 16711680
# define BIT_3 65280
# define BIT_2_64 71776119061217280
# define BIT_3_64 280375465082880
# define BIT_4_64 1095216660480
# define BIT_5_64 4278190080
# define BIT_6_64 16711680
# define BIT_7_64 65280

typedef struct		s_arfile
{
	char			*name;
	char			*ar_name;
	int				to_display;
	struct s_arfile	*next;
}					t_arfile;

void				handler_64(void *ptr, char *name,
					int is_big_endian, int ar);
void				handler_32(void *ptr, char *name,
					int is_big_endian, int ar);
void				analyse_file(void *ptr, char *name, int ar);
void				handler_ar(void *ptr, char *name);
uint16_t			swap_16_bytes(uint16_t nb);
uint32_t			swap_32_bytes(uint32_t nb);
uint64_t			swap_64_bytes(uint64_t nb);
uint32_t			endian_32(uint32_t nb, int is_big_endian);
uint64_t			endian_64(uint64_t nb, int is_big_endian);
void				print_ar(void *ptr, t_arfile *first,
					struct ranlib *ranlib, uint32_t size);
int					get_name_size(char *str);

#endif
