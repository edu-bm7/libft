/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_specstrd2join.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebezerra <ebezerra@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 15:03:25 by ebezerra          #+#    #+#             */
/*   Updated: 2023/01/05 20:50:53 by ebezerra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_specstrd2join(char *s1, char *s2, size_t s1_len, char specifier)
{
	size_t	s2_len;
	char	*new;

	if (!s1 || !s2)
		return (NULL);
	s2_len = ft_strlen(s2);
	if (s1_len > __SIZE_MAX__ - s2_len)
		return (NULL);
	new = ft_calloc((s1_len + s2_len) + 1, sizeof (*new));
	if (!new)
		return (NULL);
	ft_memcpy(new, s1, s1_len);
	if (specifier == 'c')
		ft_memcpy(&new[s1_len], s2, 1);
	else
		ft_memcpy(&new[s1_len], s2, s2_len);
	free(s1);
	free(s2);
	return (new);
}
