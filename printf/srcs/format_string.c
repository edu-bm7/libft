/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_string.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebezerra <ebezerra@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 15:04:39 by ebezerra          #+#    #+#             */
/*   Updated: 2023/01/04 03:55:27 by ebezerra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		handle_args(const char *format, va_list args, t_formatted *fmt,
					t_flags *flags);
static void		parse_args(const char **format, va_list args, t_formatted *fmt,
					t_flags *flags);
static t_bool	verify_unknown_args(const char *format, t_flags *flags,
					va_list args);
static void		append_formatted_args(char *formatted_arg, t_formatted *fmt,
					t_flags *flags);

void	format_string(const char *format, va_list args, t_formatted *fmt,
			t_flags *flags)
{
	char	*str;

	if (!ft_strchr(format, '%'))
	{
		str = ft_strdup(format);
		free(fmt->str);
		fmt->str = str;
		fmt->length = (int)ft_strlen(fmt->str);
		return ;
	}
	else
		handle_args(format, args, fmt, flags);
}

static void	handle_args(const char *format, va_list args, t_formatted *fmt,
				t_flags *flags)
{
	while (*format)
	{
		if (*format == '%' && ++format && init_flags(flags))
		{
			if (!verify_unknown_args(format, flags, args) && --format)
			{
				if (flags->default_precision)
					add_default_precision_unknown_args(format, fmt);
				else
					fmt->str = ft_strdjoin(fmt->str, format);
				break ;
			}
			else
			{
				parse_args(&format, args, fmt, flags);
				continue ;
			}
		}
		if (!flags->has_error && fmt->str && *format)
			join_char_to_fmt_str(fmt, &format, flags);
	}
}

static void	parse_args(const char **format, va_list args, t_formatted *fmt,
				t_flags *flags)
{
	char	*formatted_arg;

	while (!ft_strchr(SPECIFIERS, **format))
		(*format)++;
	init_formatted_arg(args, flags, &formatted_arg);
	if (!formatted_arg)
		flags->has_error = true_;
	else
		append_formatted_args(formatted_arg, fmt, flags);
	++(*format);
}

static t_bool	verify_unknown_args(const char *format, t_flags *flags,
					va_list args)
{
	if (!validate_args(format, flags, args))
		return (false_);
	return (true_);
}

static void	append_formatted_args(char *formatted_arg, t_formatted *fmt,
				t_flags *flags)
{
	int	len;

	if (*formatted_arg == '0' && flags->precision == 0
		&& ft_strchr("diuxX", flags->specifier))
	{
		free(formatted_arg);
		formatted_arg = ft_strdup("");
	}
	len = (int)ft_strlen(formatted_arg);
	update_width(formatted_arg, flags, len);
	if (flags->has_precision && flags->specifier != 's')
		update_precision(formatted_arg, flags, len);
	append_args_and_flags(formatted_arg, fmt, flags);
}
