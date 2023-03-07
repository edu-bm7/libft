/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebezerra <ebezerra@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 19:25:49 by ebezerra          #+#    #+#             */
/*   Updated: 2023/01/05 20:51:33 by ebezerra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t				i;
	const unsigned char	*p1 = (const unsigned char	*)s1;
	const unsigned char	*p2 = (const unsigned char	*)s2;

	i = 0;
	if (n == 0)
		return (0);
	while (i < n - 1 && p1[i] != '\0' && p1[i] == p2[i])
		i++;
	return (p1[i] - p2[i]);
}
