/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_bytes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdannay <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 11:32:01 by gdannay           #+#    #+#             */
/*   Updated: 2018/03/19 17:40:47 by gdannay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"

uint16_t	swap_16_bytes(uint16_t nb)
{
	return (nb << 8 | nb >> 8);
}

uint32_t	swap_32_bytes(uint32_t nb)
{
	nb = (nb << 24) | ((nb << 8) & BIT_2)
		| (nb >> 24) | ((nb >> 8) & BIT_3);
	return (nb);
}

uint64_t	swap_64_bytes(uint64_t nb)
{
	nb = (nb << 56) | ((nb << 48) & BIT_2_64)
		| ((nb << 40) & BIT_3_64) | ((nb << 32) & BIT_4_64)
		| ((nb >> 32) & BIT_5_64) | ((nb >> 40) & BIT_6_64)
		| ((nb >> 48) & BIT_7_64) | (nb >> 56);
	return (nb);
}

uint32_t	endian_32(uint32_t nb, int is_big_endian)
{
	if (is_big_endian)
		return (swap_32_bytes(nb));
	return (nb);
}

uint64_t	endian_64(uint64_t nb, int is_big_endian)
{
	if (is_big_endian)
		return (swap_64_bytes(nb));
	return (nb);
}
