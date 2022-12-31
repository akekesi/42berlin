/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_03.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akekesi <akekesi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 15:59:29 by akekesi           #+#    #+#             */
/*   Updated: 2022/12/31 17:17:19 by akekesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_hex_flag(unsigned int arg, char c, const char *str, int f)
{
	int	n;

	n = 0;
	if (arg && ft_char_in_str_n('#', str, f))
	{
		n += write(1, "0", 1);
		n += write(1, &c, 1);
	}
	n += ft_print_hex(arg, c, 0);
	return (n);
}

int	ft_print_int_flag(int arg, const char *str, int f)
{
	int	n;

	n = 0;
	if (ft_char_in_str_n('+', str, f) && 0 <= arg)
		n += write(1, "+", 1);
	else if (ft_char_in_str_n(' ', str, f) && 0 <= arg)
		n += write(1, " ", 1);
	n = ft_print_int(arg, n);
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
	n += ft_print_pad(str, f, len_arg);
	n += ft_print_str(arg);
	return (n);
}
