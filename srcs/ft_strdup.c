/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebezerra <ebezerra@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 19:25:35 by ebezerra          #+#    #+#             */
/*   Updated: 2023/01/05 20:51:12 by ebezerra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	s_len;
	char	*dup;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s) + 1;
	dup = malloc(s_len);
	if (!dup)
		return (NULL);
	dup = ft_memcpy(dup, s, s_len);
	return (dup);
}
