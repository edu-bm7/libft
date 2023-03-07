/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebezerra <ebezerra@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 06:37:19 by ebezerra          #+#    #+#             */
/*   Updated: 2023/01/05 20:51:56 by ebezerra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

char	*ft_strchr2(const char *s, int c)
{
	unsigned char		chr;
	const unsigned char	*str;

	if (!s)
		return (NULL);
	chr = c;
	str = (const unsigned char *)s;
	while (*str)
	{
		if (chr == *str)
			return ((char *)str);
		str++;
	}
	if (!*str && chr == *str)
		return ((char *)str);
	return (NULL);
}

char	*ft_strjoin2(char *s1, char *s2)
{
	char	*new;
	size_t	i;
	size_t	j;

	i = -1;
	j = -1;
	if (!s1)
		s1 = ft_calloc(1, sizeof (*s1));
	if (!s1 || !s2)
		return (NULL);
	if (ft_strlen(s1) > __SIZE_MAX__ - ft_strlen(s2) - 1)
		return (NULL);
	new = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof (*new));
	if (!new)
		return (NULL);
	while (s1[++i])
		new[i] = s1[i];
	while (s2[++j])
		new[i + j] = s2[j];
	new[i + j] = '\0';
	free(s1);
	return (new);
}
