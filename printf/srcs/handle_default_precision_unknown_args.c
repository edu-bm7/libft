/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_default_precision_unknown_args.c            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebezerra <ebezerra@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 15:04:47 by ebezerra          #+#    #+#             */
/*   Updated: 2023/01/04 03:56:41 by ebezerra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	add_default_precision_unknown_args(const char *format, t_formatted *fmt)
{
	char	slice[2];
	int		flag;

	flag = -1;
	slice[1] = '\0';
	while (*format)
	{
		slice[0] = *format;
		if (*format == '.')
		{
			if (flag == 1)
			{
				fmt->str = ft_strdjoin(fmt->str, slice);
				continue ;
			}
			flag = 1;
			slice[0] = '0';
			fmt->str = ft_strdjoin(fmt->str, slice);
			format++;
			continue ;
		}
		fmt->str = ft_strdjoin(fmt->str, slice);
		format++;
	}
}
