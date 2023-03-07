/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebezerra <ebezerra@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 15:02:51 by ebezerra          #+#    #+#             */
/*   Updated: 2023/01/04 03:57:02 by ebezerra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	size_t	nbr_len(unsigned int i, size_t base_len);

char	*ft_btoa(unsigned int nbr, char *base)
{
	size_t			base_len;
	char			*str;
	static size_t	index;

	base_len = ft_strlen(base);
	index = nbr_len(nbr, base_len);
	str = ft_calloc(index + 1, sizeof (*str));
	if (!str)
		return (NULL);
	while (index > 0)
	{
		str[index - 1] = base[nbr % base_len];
		nbr /= base_len;
		index--;
	}
	return (str);
}

static	size_t	nbr_len(unsigned int i, size_t base_len)
{
	size_t	len;

	len = 0;
	if (i == 0 && ++len)
		return (len);
	while (i != 0 && ++len)
		i /= base_len;
	return (len);
}
