/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   append_flags.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebezerra <ebezerra@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 15:04:31 by ebezerra          #+#    #+#             */
/*   Updated: 2023/01/04 03:56:31 by ebezerra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	append_width(t_formatted *fmt, t_flags *flags)
{
	if (flags->width > 0)
	{
		while (flags->width)
		{
			fmt->str = ft_specstrd2join(fmt->str, char_to_str(flags->pad),
					fmt->length, flags->specifier);
			flags->width--;
			fmt->length++;
		}
	}
}

void	append_hash(t_formatted *fmt, t_flags *flags)
{
	if (flags->specifier == 'x')
		fmt->str = ft_specstrdjoin(fmt->str, "0x", fmt->length,
				flags->specifier);
	else if (flags->specifier == 'X')
		fmt->str = ft_specstrdjoin(fmt->str, "0X", fmt->length,
				flags->specifier);
	fmt->length += 2;
}

void	append_plus(t_formatted *fmt, t_flags *flags)
{
	if (!flags->is_negative)
	{
		fmt->str = ft_specstrdjoin(fmt->str, "+", fmt->length,
				flags->specifier);
		fmt->length++;
	}
}

void	append_space(t_formatted *fmt, t_flags *flags)
{
	if (!flags->is_negative)
	{
		fmt->str = ft_specstrdjoin(fmt->str, " ", fmt->length,
				flags->specifier);
		fmt->length++;
	}
}

void	append_precision(t_formatted *fmt, t_flags *flags)
{
	if (flags->precision > 0)
	{
		while (flags->precision)
		{
			fmt->str = ft_specstrd2join(fmt->str, char_to_str('0'), fmt->length,
					flags->specifier);
			flags->precision--;
			fmt->length++;
		}
	}
}
