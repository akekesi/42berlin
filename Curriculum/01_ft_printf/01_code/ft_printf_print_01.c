/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_print_01.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akekesi <akekesi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 17:00:34 by akekesi           #+#    #+#             */
/*   Updated: 2023/01/01 04:04:49 by akekesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_ptr(unsigned long long arg)
{
	int	i;

	i = 0;
	if (arg == 0)
		i += ft_print_str(ft_get_null('p'));
	if (arg)
	{
		i += ft_print_str("0x");
		i = ft_print_uhex(arg, i);
	}
	return (i);
}

int	ft_print_int(int arg, int n)
{
	if (arg == -2147483648)
		n += ft_print_str("-2147483648");
	else
	{
		if (arg < 0)
		{
			n += ft_print_char('-');
			arg *= -1;
		}
		if (9 < arg)
		{
			n = ft_print_int(arg / 10, n);
		}
		n += ft_print_char((arg % 10) + '0');
	}
	return (n);
}

int	ft_print_uint(unsigned int arg, int n)
{
	if (9 < arg)
		n = ft_print_uint(arg / 10, n);
	n += ft_print_char((arg % 10) + '0');
	return (n);
}

int	ft_print_hex(unsigned int arg, int c, int n)
{
	int	r;

	if (15 < arg)
		n += ft_print_hex(arg / 16, c, n);
	r = arg % 16;
	if (r < 10)
		n += ft_print_char(r + '0');
	if (9 < r)
		n += ft_print_char(r - 10 + 'a' - 'x' + c);
	return (n);
}

int	ft_print_uhex(unsigned long long arg, int n)
{
	int	r;

	if (15 < arg)
		n = ft_print_uhex(arg / 16, n);
	r = arg % 16;
	if (r < 10)
		n += ft_print_char(r + '0');
	if (9 < r)
		n += ft_print_char(r - 10 + 'a');
	return (n);
}
