/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebezerra <ebezerra@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 15:03:15 by ebezerra          #+#    #+#             */
/*   Updated: 2023/01/05 20:50:36 by ebezerra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	size_t	nbr_len(uintptr_t i, size_t base_len);

char	*ft_ptoa(void *nbr, char *base)
{
	size_t			base_len;
	char			*str;
	static size_t	index;
	uintptr_t		nbr_cast;

	nbr_cast = (uintptr_t)nbr;
	base_len = ft_strlen(base);
	index = nbr_len(nbr_cast, base_len);
	str = ft_calloc(index + 3, sizeof (*str));
	if (!str)
		return (NULL);
	str[0] = '0';
	str[1] = 'x';
	while (index > 0)
	{
		str[--index + 2] = base[nbr_cast % base_len];
		nbr_cast /= base_len;
	}
	return (str);
}

static	size_t	nbr_len(uintptr_t i, size_t base_len)
{
	size_t	len;

	len = 0;
	if (i == 0 && ++len)
		return (len);
	while (i != 0 && ++len)
		i /= base_len;
	return (len);
}
