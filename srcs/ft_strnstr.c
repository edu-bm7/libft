/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebezerra <ebezerra@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 19:25:51 by ebezerra          #+#    #+#             */
/*   Updated: 2023/01/05 20:51:36 by ebezerra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	max_index;
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	if (!*little)
		return ((char *) big);
	if (ft_strlen(big) < ft_strlen(little))
		return (NULL);
	max_index = ft_strlen(big) - ft_strlen(little);
	while (i <= max_index && big[i])
	{
		j = i;
		k = 0;
		while (big[j] == little[k] && little[k] && j < len)
		{
			j++;
			k++;
		}
		if (!little[k])
			return ((char *) &big[i]);
		i++;
	}
	return (NULL);
}
