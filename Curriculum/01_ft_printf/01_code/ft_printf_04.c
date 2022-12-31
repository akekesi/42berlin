/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_04.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akekesi <akekesi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 16:31:34 by akekesi           #+#    #+#             */
/*   Updated: 2022/12/31 21:46:11 by akekesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_pad(const char *str, int f, int len_arg, int c)
{
	int	n;
	int	pad;

	n = 0;
	pad = ft_int_in_str(str, f);
	pad -= len_arg;
	while (0 < pad)
	{
		n += ft_print_char(c);
		pad--;
	}
	return (n);
}

int	ft_print_pad_int(int arg, const char *str, int f, int len_arg, int c)
{
	int	n;

	n = 0;
	if (ft_char_in_str_n('+', str, f) && 0 <= arg)
	{
		n += ft_print_pad(str, f, len_arg + 1, c);
		n += write(1, "+", 1);
	}
	else if (ft_char_in_str_n(' ', str, f) && 0 <= arg)
	{
		n += ft_print_pad(str, f, len_arg, c);
		if (!n)
			n += write(1, " ", 1);
	}
	else
		n += ft_print_pad(str, f, len_arg, c);
	return (n);
}

int	ft_print_pad_uint(const char *str, int f, int len_arg, int c)
{
	int	n;

	n = 0;
	if (ft_char_in_str_n('+', str, f))
	{
		n += ft_print_pad(str, f, len_arg + 1, c);
		n += write(1, "+", 1);
	}
	else if (ft_char_in_str_n(' ', str, f))
	{
		n += ft_print_pad(str, f, len_arg, c);
		if (!n)
			n += write(1, " ", 1);
	}
	else
		n += ft_print_pad(str, f, len_arg, c);
	return (n);
}
