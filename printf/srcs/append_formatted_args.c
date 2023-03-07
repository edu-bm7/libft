/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   append_formatted_args.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebezerra <ebezerra@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 15:04:34 by ebezerra          #+#    #+#             */
/*   Updated: 2023/01/04 03:56:33 by ebezerra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	append_args_default_order(char *formatted_arg, t_formatted *fmt,
				t_flags *flags);
static void	append_args_left_justify(char *formatted_arg, t_formatted *fmt,
				t_flags *flags);
static void	append_precision_str(char *formatted_arg, t_formatted *fmt,
				t_flags *flags);
static void	append_specifier(char *formatted_arg, t_formatted *fmt,
				t_flags *flags);

void	append_args_and_flags(char *formatted_arg, t_formatted *fmt,
				t_flags *flags)
{
	if (*formatted_arg == '0' && ft_strchr("xX", flags->specifier))
		flags->has_hash = false_;
	if (!flags->has_minus)
		append_args_default_order(formatted_arg, fmt, flags);
	else
		append_args_left_justify(formatted_arg, fmt, flags);
}

static void	append_args_default_order(char *formatted_arg, t_formatted *fmt,
				t_flags *flags)
{
	if (flags->has_width && !flags->has_zero)
		append_width(fmt, flags);
	if (flags->is_negative)
	{
		fmt->str = ft_specstrdjoin(fmt->str, "-", fmt->length,
				flags->specifier);
		fmt->length++;
	}
	if (flags->has_zero)
		append_width(fmt, flags);
	if (flags->has_hash)
		append_hash(fmt, flags);
	else if (flags->has_plus)
		append_plus(fmt, flags);
	else if (flags->has_space)
		append_space(fmt, flags);
	if (flags->specifier != 's')
	{
		if (flags->has_precision)
			append_precision(fmt, flags);
	}
	append_specifier(formatted_arg, fmt, flags);
}

static void	append_args_left_justify(char *formatted_arg, t_formatted *fmt,
				t_flags *flags)
{
	if (flags->has_hash)
		append_hash(fmt, flags);
	if (flags->is_negative)
	{
		fmt->str = ft_specstrdjoin(fmt->str, "-", fmt->length,
				flags->specifier);
		fmt->length++;
	}
	if (flags->has_plus)
		append_plus(fmt, flags);
	if (flags->has_space)
		append_space(fmt, flags);
	if (flags->specifier != 's')
	{
		if (flags->has_precision)
			append_precision(fmt, flags);
	}
	append_specifier(formatted_arg, fmt, flags);
	if (flags->has_width)
		append_width(fmt, flags);
}

static void	append_precision_str(char *formatted_arg, t_formatted *fmt,
				t_flags *flags)
{
	if (flags->precision < 6 && ft_strncmp("(null)", formatted_arg, 6) == 0)
		return ;
	while (*formatted_arg && flags->precision--)
	{
		fmt->str = ft_specstrd2join(fmt->str, char_to_str(*formatted_arg),
				fmt->length, flags->specifier);
		fmt->length++;
		formatted_arg++;
	}
}

static void	append_specifier(char *formatted_arg, t_formatted *fmt,
				t_flags *flags)
{
	if (flags->specifier == 'c' && *formatted_arg == 0)
		fmt->length++;
	if ((flags->specifier == 'd' || flags->specifier == 'i')
		&& *formatted_arg == '-')
	{
		fmt->str = ft_specstrdjoin(fmt->str, &formatted_arg[1], fmt->length,
				flags->specifier);
		fmt->length += (int)ft_strlen(&formatted_arg[1]);
	}
	else if (flags->specifier == 's' && flags->has_precision)
		append_precision_str(formatted_arg, fmt, flags);
	else
	{
		fmt->str = ft_specstrdjoin(fmt->str, formatted_arg, fmt->length,
				flags->specifier);
		fmt->length += (int)ft_strlen(formatted_arg);
	}
	free(formatted_arg);
}
