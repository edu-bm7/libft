/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebezerra <ebezerra@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 19:25:56 by ebezerra          #+#    #+#             */
/*   Updated: 2023/01/05 20:51:42 by ebezerra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	s1_len;
	size_t	end;
	char	*trimmed;

	if (!*s1 || !*set)
	{
		if (!*s1)
			return (ft_strdup(""));
		return (ft_strdup(s1));
	}
	start = 0;
	s1_len = ft_strlen(s1);
	end = s1_len - 1;
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;
	while (end && ft_strchr(set, s1[end]))
		end--;
	if (start > ++end)
		return (ft_strdup(""));
	trimmed = ft_substr(s1, start, end - start);
	return (trimmed);
}
