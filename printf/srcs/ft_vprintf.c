/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebezerra <ebezerra@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 15:04:44 by ebezerra          #+#    #+#             */
/*   Updated: 2023/01/04 03:55:33 by ebezerra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

int	init_flags(t_flags *flags);

int	ft_vprintf(const char *format, va_list args)
{
	t_formatted	fmt;
	t_flags		flags;
	int			size;

	init_flags(&flags);
	fmt.length = 0;
	fmt.str = ft_strdup("");
	format_string(format, args, &fmt, &flags);
	if (!flags.has_error && fmt.str)
	{
		size = write(STDOUT, fmt.str, fmt.length);
		free(fmt.str);
		return (size);
	}
	free(fmt.str);
	return (-1);
}

int	ft_vdprintf(int fd, const char *format, va_list args)
{
	t_formatted	fmt;
	t_flags		flags;
	int			size;

	init_flags(&flags);
	fmt.length = 0;
	fmt.str = ft_strdup("");
	format_string(format, args, &fmt, &flags);
	if (!flags.has_error && fmt.str)
	{
		size = write(fd, fmt.str, fmt.length);
		free(fmt.str);
		return (size);
	}
	free(fmt.str);
	return (-1);
}

int	init_flags(t_flags *flags)
{
	flags->width = 0;
	flags->precision = -1;
	flags->has_width = false_;
	flags->has_hash = false_;
	flags->has_minus = false_;
	flags->has_precision = false_;
	flags->has_plus = false_;
	flags->has_space = false_;
	flags->has_zero = false_;
	flags->unknown_format = false_;
	flags->specifier = 0;
	flags->pad = 0;
	flags->default_precision = false_;
	flags->has_error = false_;
	flags->is_negative = false_;
	flags->int_min = false_;
	return (1);
}
