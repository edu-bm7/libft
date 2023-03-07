/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebezerra <ebezerra@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 19:25:38 by ebezerra          #+#    #+#             */
/*   Updated: 2023/01/05 20:51:19 by ebezerra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	char	*new;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	if (s1_len > __SIZE_MAX__ - s2_len)
		return (NULL);
	new = ft_calloc((s1_len + s2_len) + 1, sizeof (*new));
	if (!new)
		return (NULL);
	ft_memcpy(new, s1, s1_len);
	ft_memcpy(&new[s1_len], s2, s2_len);
	return (new);
}
