/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebezerra <ebezerra@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 19:23:26 by ebezerra          #+#    #+#             */
/*   Updated: 2023/01/04 03:57:00 by ebezerra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_hexval(char c);

int	ft_atoi(const char *nptr)
{
	int	result;
	int	sign;

	result = 0;
	sign = 1;
	while ((*nptr >= '\t' && *nptr <= '\r') || *nptr == ' ')
		nptr++;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			sign *= -1;
		nptr++;
	}
	if (ft_strncmp(nptr, "0x", 2) == 0)
	{
		nptr += 2;
		while (*nptr && ft_isxdigit(*nptr))
			result = result * 16 + ft_hexval(*nptr++);
	}
	else
	{
		while (*nptr && ft_isdigit(*nptr))
			result = result * 10 + *nptr++ - '0';
	}
	return (sign * result);
}

static int	ft_hexval(char c)
{
	if (c >= '0' && c <= '9')
		return (c - '0');
	else if (c >= 'a' && c <= 'f')
		return (c - 'a' + 10);
	else if (c >= 'A' && c <= 'F')
		return (c - 'A' + 10);
	return (0);
}
