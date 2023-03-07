/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_validation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebezerra <ebezerra@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 15:04:36 by ebezerra          #+#    #+#             */
/*   Updated: 2023/01/04 03:55:25 by ebezerra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	handle_flags(const char *format, t_flags *flags);
static void	handle_width(const char **format, t_flags *flags, va_list args);
static void	handle_precision(const char **format, t_flags *flags,
				va_list args);
static void	handle_specifier(const char *format, t_flags *flags);

t_bool	validate_args(const char *format, t_flags *flags, va_list args)
{
	while (*format)
	{
		if (ft_strchr(FLAGS, *format))
			handle_flags(format, flags);
		else if ((*format >= '1' && *format <= '9') || *format == '*')
			handle_width(&format, flags, args);
		else if (ft_strchr(PRECISION, *format))
		{
			handle_precision(&format, flags, args);
			flags->has_precision = true_;
			continue ;
		}
		else if (ft_strchr(SPECIFIERS, *format))
		{
			handle_specifier(format, flags);
			break ;
		}
		else
			flags->unknown_format = true_;
		format++;
	}
	if (flags->unknown_format || !flags->specifier)
		return (false_);
	return (true_);
}

static void	handle_flags(const char *format, t_flags *flags)
{
	if (flags->has_precision || flags->has_width)
	{
		flags->unknown_format = true_;
		return ;
	}
	if (*format == ' ')
		flags->has_space = true_;
	else if (*format == '+')
		flags->has_plus = true_;
	else if (*format == '#')
		flags->has_hash = true_;
	else if (*format == '-')
		flags->has_minus = true_;
	else if (*format == '0')
	{
		if (!flags->has_minus)
		{
			flags->has_zero = true_;
			flags->pad = '0';
		}
	}
}

static void	handle_width(const char **format, t_flags *flags, va_list args)
{
	if (flags->has_width)
	{
		flags->unknown_format = true_;
		return ;
	}
	flags->has_width = true_;
	if (**format == '*')
		flags->width = va_arg(args, int);
	else
		flags->width = ft_atoi(*format);
	if (!flags->has_zero)
		flags->pad = ' ';
	if (**format != '*')
	{
		while (ft_isdigit(**format))
			(*format)++;
		--(*format);
	}
}

static void	handle_precision(const char **format, t_flags *flags,
				va_list args)
{
	flags->has_zero = false_;
	flags->pad = ' ';
	if (++(*format) && flags->has_precision)
	{
		flags->unknown_format = true_;
		return ;
	}
	if (ft_isdigit(**format))
	{
		flags->precision = ft_atoi(*format);
		while (ft_isdigit(**format))
			(*format)++;
	}
	else if (**format == '*' && ++(*format))
		flags->precision = va_arg(args, int);
	else if (!ft_isdigit(**format))
	{
		flags->precision = 0;
		flags->default_precision = true_;
		if (!ft_strchr("cspdiuxX", **format))
		{
			flags->unknown_format = true_;
			return ;
		}
	}
}

static void	handle_specifier(const char *format, t_flags *flags)
{
	if (flags->has_zero || flags->has_hash || flags->has_space
		|| flags->has_precision || flags->has_plus)
	{
		if ((ft_strchr("di", *format) && !flags->has_hash) || (ft_strchr("u",
					*format) && !flags->has_hash && !flags->has_space
				&& !flags->has_plus) || (ft_strchr("xX", *format)
				&& !flags->has_space && !flags->has_plus) || (ft_strchr("s",
					*format) && !flags->has_zero && !flags->has_hash
				&& !flags->has_space && !flags->has_plus))
			flags->specifier = *format;
		else
			flags->unknown_format = true_;
	}
	else
	{
		if (ft_strchr(SPECIFIERS, *format))
		{
			if (*format == '%' && flags->has_minus)
				flags->unknown_format = true_;
			else
				flags->specifier = *format;
		}
		else
			flags->unknown_format = true_;
	}
}
