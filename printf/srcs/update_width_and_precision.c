/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_width_and_precision.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebezerra <ebezerra@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 15:04:52 by ebezerra          #+#    #+#             */
/*   Updated: 2023/01/04 03:56:54 by ebezerra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	update_width(char *formatted_arg, t_flags *flags, int len)
{
	if ((*formatted_arg == 0 && flags->specifier == 'c') || flags->is_negative)
		flags->width--;
	if (flags->specifier == 's' && flags->has_precision
		&& flags->precision < len)
		flags->width -= flags->precision;
	else if (flags->specifier == 's')
		flags->width -= len;
	else if ((flags->width > len)
		|| ((*formatted_arg == '-'
				&& (flags->specifier == 'i' || flags->specifier == 'd'))
			&& flags->width > (int)ft_strlen(&formatted_arg[1])))
	{
		if (flags->has_hash)
			flags->width -= 2;
		else if (flags->has_space || flags->has_plus)
			flags->width--;
		if ((flags->specifier == 'i' || flags->specifier == 'd')
			&& *formatted_arg == '-')
			flags->width -= (int)ft_strlen(&formatted_arg[1]);
		else
			flags->width -= len;
	}
	else
		flags->width = 0;
}

void	update_precision(char *formatted_arg, t_flags *flags, int len)
{
	if ((flags->precision > len) || (flags->int_min
			&& flags->precision > (int)ft_strlen(&formatted_arg[1])))
	{
		if (flags->int_min)
		{
			flags->precision -= (int)ft_strlen(&formatted_arg[1]);
			if (flags->width > flags->precision)
				flags->width -= flags->precision;
			else
				flags->width = 0;
		}
		else
		{
			flags->precision -= len;
			if (flags->width > flags->precision)
				flags->width -= flags->precision;
			else
				flags->width = 0;
		}
	}
	else
		flags->precision = 0;
}
