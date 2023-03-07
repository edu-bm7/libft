/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebezerra <ebezerra@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 19:24:27 by ebezerra          #+#    #+#             */
/*   Updated: 2023/01/05 20:49:39 by ebezerra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	size_t	int_len(int i);
static char		*int_to_ascii(char *str, int n);

// Malloc len of int n provided plus space for a '\0' and '-', if necessary.
// str initially points to the last null pointer of the string.
char	*ft_itoa(int n)
{
	char	*str;
	size_t	n_len;

	n_len = int_len(n);
	if (n >= 0)
	{
		str = ft_calloc(n_len + 1, sizeof (*str));
		if (!str)
			return (NULL);
		str = &str[n_len];
	}
	else
	{
		str = ft_calloc(n_len + 2, sizeof (*str));
		if (!str)
			return (NULL);
		str = &str[n_len + 1];
	}
	str = int_to_ascii(str, n);
	return (str);
}

static	size_t	int_len(int i)
{
	size_t	len;

	len = 0;
	if (i == 0 && ++len)
		return (len);
	while (i != 0 && ++len)
		i /= 10;
	return (len);
}

static char	*int_to_ascii(char *str, int n)
{
	if (n >= 0)
	{
		if (n == 0)
			*--str = '0';
		while (n != 0)
		{
			*--str = '0' + (n % 10);
			n /= 10;
		}
	}
	else
	{
		while (n != 0)
		{
			*--str = '0' - (n % 10);
			n /= 10;
		}
		*--str = '-';
	}
	return (str);
}
