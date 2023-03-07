/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join_char_to_fmt_str.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebezerra <ebezerra@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 16:20:39 by ebezerra          #+#    #+#             */
/*   Updated: 2023/01/04 03:56:50 by ebezerra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	join_char_to_fmt_str(t_formatted *fmt, const char **format,
								t_flags *flags)
{	
	fmt->str = ft_specstrd2join(fmt->str, char_to_str(**format),
			fmt->length, flags->specifier);
	fmt->length++;
	++(*format);
}
