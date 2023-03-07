/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebezerra <ebezerra@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 19:25:00 by ebezerra          #+#    #+#             */
/*   Updated: 2023/01/05 20:50:30 by ebezerra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, void *src, size_t n)
{
	unsigned char		*dest_ptr;
	const unsigned char	*src_ptr;
	unsigned char		*final_dest;
	const unsigned char	*final_src;

	dest_ptr = dest;
	src_ptr = src;
	if (dest_ptr == src_ptr || n == 0)
		return (dest);
	if (dest_ptr > src_ptr && dest_ptr < src_ptr + n)
	{
		final_dest = dest_ptr + (n - 1);
		final_src = src_ptr + (n - 1);
		while (n--)
			*final_dest-- = *final_src--;
		return (dest);
	}
	return (ft_memcpy(dest, src, n));
}
