/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebezerra <ebezerra@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 19:25:58 by ebezerra          #+#    #+#             */
/*   Updated: 2023/01/05 20:51:44 by ebezerra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, size_t start, size_t len)
{
	char	*sub;
	size_t	s_len;

	s_len = ft_strlen(s);
	if (start >= s_len)
	{
		sub = (ft_calloc(1, sizeof (*sub)));
		if (!sub)
			return (NULL);
		return (sub);
	}
	else if (s_len - start < len)
		len = s_len - start;
	if (len + 1 < len)
		return (NULL);
	sub = ft_calloc(len + 1, sizeof (*sub));
	if (!sub)
		return (NULL);
	ft_strlcpy(sub, &s[start], len + 1);
	return (sub);
}
