/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebezerra <ebezerra@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 19:25:54 by ebezerra          #+#    #+#             */
/*   Updated: 2023/01/05 20:51:39 by ebezerra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t			len;
	unsigned char	*str;
	unsigned char	chr;

	len = ft_strlen(s);
	str = (unsigned char *)s;
	chr = c;
	while (len)
	{
		if (chr == str[len])
			return ((char *)&str[len]);
		len--;
	}
	if (chr == str[len])
		return ((char *)&str[len]);
	return (NULL);
}
