/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_formatted_args.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebezerra <ebezerra@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 15:04:49 by ebezerra          #+#    #+#             */
/*   Updated: 2023/01/04 03:56:47 by ebezerra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*pointer_to_str(void *ptr);
static char	*check_str(char *arg);
static int	verify_negative_value(t_flags *flags, va_list args);

void	init_formatted_arg(va_list args, t_flags *flags,
			char **formatted_arg)
{
	if (flags->specifier == 'c')
		*formatted_arg = char_to_str(va_arg(args, int));
	else if (flags->specifier == 's')
		*formatted_arg = check_str(va_arg(args, char *));
	else if (flags->specifier == 'p')
		*formatted_arg = pointer_to_str(va_arg(args, void *));
	else if (flags->specifier == 'd' || flags->specifier == 'i')
		*formatted_arg = ft_itoa(verify_negative_value(flags, args));
	else if (flags->specifier == 'u')
		*formatted_arg = ft_uitoa(va_arg(args, unsigned int));
	else if (flags->specifier == 'x')
		*formatted_arg = ft_btoa(va_arg(args, unsigned int),
				"0123456789abcdef");
	else if (flags->specifier == 'X')
		*formatted_arg = ft_btoa(va_arg(args, unsigned int),
				"0123456789ABCDEF");
	else if (flags->specifier == '%')
		*formatted_arg = ft_strdup("%");
}

char	*char_to_str(int c)
{
	char	*str;

	str = ft_calloc(2, sizeof (*str));
	if (!str)
		return (NULL);
	str[0] = (char)c;
	return (str);
}

static char	*pointer_to_str(void *ptr)
{
	char	*str;

	if (!ptr)
		return (ft_strdup("(nil)"));
	str = ft_ptoa(ptr, "0123456789abcdef");
	return (str);
}

static int	verify_negative_value(t_flags *flags, va_list args)
{
	int	value;

	value = va_arg(args, int);
	if (value < 0)
	{
		flags->is_negative = true_;
		if (value == -2147483648)
			flags->int_min = true_;
		else
			value = -value;
	}
	return (value);
}

static char	*check_str(char *arg)
{
	if (!arg)
		return (ft_strdup("(null)"));
	return (ft_strdup(arg));
}
