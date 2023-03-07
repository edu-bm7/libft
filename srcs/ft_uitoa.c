/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebezerra <ebezerra@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 15:03:54 by ebezerra          #+#    #+#             */
/*   Updated: 2023/01/05 20:51:51 by ebezerra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	size_t	uint_len(unsigned int i);

// Malloc len of int n provided plus space for a '\0'.
// str initially points to the last null pointer of the string.
char	*ft_uitoa(unsigned int nbr)
{
	char	*str;
	size_t	n_len;

	n_len = uint_len(nbr);
	str = ft_calloc(n_len + 1, sizeof (*str));
	if (!str)
		return (NULL);
	str = &str[n_len];
	if (nbr == 0)
		*--str = '0';
	while (nbr != 0)
	{
		*--str = '0' + (nbr % 10);
		nbr /= 10;
	}
	return (str);
}

static	size_t	uint_len(unsigned int i)
{
	size_t	len;

	len = 0;
	if (i == 0 && ++len)
		return (len);
	while (i != 0 && ++len)
		i /= 10;
	return (len);
}
