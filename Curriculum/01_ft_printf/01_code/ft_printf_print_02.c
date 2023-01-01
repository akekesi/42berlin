/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_print_02.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akekesi <akekesi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 15:59:29 by akekesi           #+#    #+#             */
/*   Updated: 2023/01/01 04:10:12 by akekesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_hex_flag(unsigned int arg, int c, const char *str, int f)
{
	int	n;
	int	n_;
	int	c_;

	n = ft_print_hex_flag_pre(arg, c, str, f);
	n_ = n;
	c_ = ' ';
	if (ft_first_int_in_str_zero(str, f))
		c_ = '0';
	if (ft_char_in_str_n('.', str, f))
	{
		n += ft_print_pad(str, f, ft_hex_len(arg), '0');
		n += ft_print_hex(arg, c, 0);
	}
	else if (ft_char_in_str_n('-', str, f))
	{
		n += ft_print_hex(arg, c, 0);
		n += ft_print_pad(str, f, ft_hex_len(arg) + n_, c_);
	}
	else
	{
		n += ft_print_pad(str, f, ft_hex_len(arg) + n_, c_);
		n += ft_print_hex(arg, c, 0);
	}
	return (n);
}

int	ft_print_hex_flag_pre(unsigned int arg, int c, const char *str, int f)
{
	int	n;

	n = 0;
	if (arg && ft_char_in_str_n('#', str, f))
	{
		n += write(1, "0", 1);
		n += write(1, &c, 1);
	}
	return (n);
}

int	ft_print_int_flag(int arg, const char *str, int f)
{
	int	n;
	int	sign;

	n = 0;
	sign = 1;
	if (arg < 0)
	{
		n += write(1, "-", 1);
		sign *= -1;
	}
	n += ft_print_int_flag_sub1(arg, str, f, sign);
	return (n);
}

int	ft_print_int_flag_sub2(int arg, int sign, int n)
{
	if (arg == -2147483648 && sign < 0)
		n += ft_print_str("2147483648");
	else
		n = ft_print_int(sign * arg, n);
	return (n);
}

int	ft_print_int_flag_sub1(int arg, const char *str, int f, int sign)
{
	int	n;
	int	len_arg;

	n = 0;
	len_arg = ft_int_len(arg);
	if (ft_char_in_str_n('.', str, f))
	{
		if (arg < 0)
			len_arg -= 1;
		n += ft_print_pad(str, f, len_arg, '0');
		n = ft_print_int_flag_sub2(arg, sign, n);
	}
	else if (ft_char_in_str_n('-', str, f))
	{
		n = ft_print_int_flag_sub2(arg, sign, n);
		n += ft_print_pad_int(arg, str, f, len_arg);
	}
	else
	{
		n += ft_print_pad_int(arg, str, f, len_arg);
		n = ft_print_int_flag_sub2(arg, sign, n);
	}
	return (n);
}
