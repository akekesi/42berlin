/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_03.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akekesi <akekesi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 15:59:29 by akekesi           #+#    #+#             */
/*   Updated: 2022/12/31 21:45:58 by akekesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_hex_flag(unsigned int arg, int c, const char *str, int f)
{
	int	n;
	int	c_;
	int	len_arg;

	n = 0;
	if (arg && ft_char_in_str_n('#', str, f))
	{
		n += write(1, "0", 1);
		n += write(1, &c, 1);
	}
	c_ = ' ';
	len_arg = ft_hex_len(arg);
	if (ft_first_int_in_str_zero(str, f))
		c_ = '0';
	n += ft_print_pad(str, f, len_arg + n, c_);
	n += ft_print_hex(arg, c, 0);
	return (n);
}

int	ft_print_int_flag(int arg, const char *str, int f)
{
	int	n;
	int	c;
	int	sign;
	int	len_arg;

	n = 0;
	c = ' ';
	sign = 1;
	len_arg = ft_int_len(arg);
	if (ft_first_int_in_str_zero(str, f))
	{
		c = '0';
		if (arg < 0)
		{
			n += write(1, "-", 1);
			sign *= -1;
		}
	}
	n += ft_print_pad_int(arg, str, f, len_arg, c);
	if (arg == -2147483648 && sign < 0)
		n += ft_print_str("2147483648");
	else
		n = ft_print_int(sign * arg, n);
	return (n);
}

int	ft_print_str_flag(char *arg, const char *str, int f)
{
	int	n;
	int	len_arg;

	n = 0;
	if (arg == NULL)
		len_arg = ft_str_len(ft_get_null('s'));
	else
		len_arg = ft_str_len(arg);
	n += ft_print_pad(str, f, len_arg, ' ');
	n += ft_print_str(arg);
	return (n);
}

int	ft_print_uint_flag(unsigned int arg, const char *str, int f)
{
	int	n;
	int	c;
	int	len_arg;

	n = 0;
	c = ' ';
	len_arg = ft_uint_len(arg);
	if (ft_first_int_in_str_zero(str, f))
		c = '0';
	n += ft_print_pad_uint(str, f, len_arg, c);
	n = ft_print_uint(arg, n);
	return (n);
}
