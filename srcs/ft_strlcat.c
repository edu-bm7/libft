/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebezerra <ebezerra@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 19:25:41 by ebezerra          #+#    #+#             */
/*   Updated: 2023/01/05 20:51:22 by ebezerra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	char	*dst_cmp;
	size_t	src_len;
	size_t	dest_len;
	size_t	i;

	i = size;
	dst_cmp = dst;
	src_len = ft_strlen(src);
	while (i-- && *dst_cmp)
		dst_cmp++;
	dest_len = dst_cmp - dst;
	if (dest_len == size)
		return (dest_len + src_len);
	return (dest_len + ft_strlcpy(dst + dest_len, src, size - dest_len));
}
