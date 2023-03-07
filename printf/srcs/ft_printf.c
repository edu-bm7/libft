/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebezerra <ebezerra@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 15:04:42 by ebezerra          #+#    #+#             */
/*   Updated: 2023/01/04 03:55:29 by ebezerra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		done;

	va_start(args, format);
	done = ft_vprintf(format, args);
	va_end(args);
	return (done);
}

int	ft_dprintf(int fd, const char *format, ...)
{
	va_list	args;
	int		done;

	va_start(args, format);
	done = ft_vdprintf(fd, format, args);
	va_end(args);
	return (done);
}
