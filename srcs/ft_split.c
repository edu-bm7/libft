/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebezerra <ebezerra@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 19:25:17 by ebezerra          #+#    #+#             */
/*   Updated: 2023/01/05 20:51:01 by ebezerra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_words(const char *s, char c);

char	**ft_split(char const *s, char c)
{
	char	**splitted;
	char	*ruler;
	size_t	i;

	if (count_words(s, c) > __SIZE_MAX__ - 1)
		return (NULL);
	splitted = ft_calloc(count_words(s, c) + 1, sizeof (*splitted));
	if (!splitted)
		return (NULL);
	ruler = (char *)s;
	i = 0;
	while (*ruler)
	{
		if (*ruler != c)
		{
			s = ruler;
			while (*ruler && *ruler != c)
				ruler++;
			splitted[i++] = ft_substr(s, 0, ruler - s);
			ruler--;
		}
		ruler++;
	}
	return (splitted);
}

static size_t	count_words(const char *s, char c)
{
	size_t	word_count;

	word_count = 0;
	while (*s)
	{
		if (*s != c)
		{
			while (*s && *s != c)
				s++;
			word_count++;
			s--;
		}
		s++;
	}
	return (word_count);
}
