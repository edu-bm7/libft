/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebezerra <ebezerra@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 19:25:47 by ebezerra          #+#    #+#             */
/*   Updated: 2023/01/05 20:51:30 by ebezerra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(size_t, char))
{
	char			*str;
	size_t			i;

	i = 0;
	if (ft_strlen(s) > __SIZE_MAX__ - 1)
		return (NULL);
	str = ft_calloc(ft_strlen(s) + 1, sizeof (*str));
	if (!str)
		return (NULL);
	while (s[i])
	{
		str[i] = f(i, s[i]);
		i++;
	}
	return (str);
}
