/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebezerra <ebezerra@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 19:25:32 by ebezerra          #+#    #+#             */
/*   Updated: 2023/01/05 20:51:05 by ebezerra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*ft_strchr(const char *s, int c)
{
	unsigned char		chr;
	const unsigned char	*str;

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
