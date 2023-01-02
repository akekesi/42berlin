/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_flag_00.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akekesi <akekesi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 20:59:03 by akekesi           #+#    #+#             */
/*   Updated: 2023/01/01 20:59:03 by akekesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "test.h" // delete !!!

int	ft_print_char_flag(va_list *args, const char *str, int t)
{
	int	n;
	int	arg;
	int	pad_len;

	n = 0;
	arg = va_arg(*args, int);
	pad_len = ft_int_in_str(str, t);
	if (ft_char_in_str_n('-', str, t) != -1)
	{
		n += write(1, &arg, 1);
		n += ft_print_pad(' ', pad_len - 1);
	}
	else
	{
		n += ft_print_pad(' ', pad_len - 1);
		n += write(1, &arg, 1);
	}
	return (n);
}

int	ft_print_str_flag(va_list *args, const char *str, int t)
{
	int		n;
	int		dot;
	int		dot_int;
	char	*arg;

	n = 0;
	arg = ft_str_to_str(va_arg(*args, char *));
	dot = ft_char_in_str_n('.', str, t);
	if (dot != -1)
	{
		dot_int = ft_int_in_str(str + dot, t - dot);
		if (dot_int < ft_str_len(arg))
			arg[dot_int] = '\0';
	}
	n = ft_print_pad_pos(arg, str, t, ' ');
	free(arg);
	return (n);
}

int	ft_print_ptr_flag(va_list *args, const char *str, int t)
{
	int	n;
	int	c;

	n = 0;
	t = 0;
	str = NULL;
	printf("%d, %s", t, str);
	c = va_arg(*args, int);
	n += write(1, &c, 1);
	return (n);
}

int	ft_print_int_flag(va_list *args, const char *str, int t)
{
	int	n;
	int	c;

	n = 0;
	t = 0;
	str = NULL;
	printf("%d, %s", t, str);
	c = va_arg(*args, int);
	n += write(1, &c, 1);
	return (n);
}

int	ft_print_uint_flag(va_list *args, const char *str, int t)
{
	int	n;
	int	c;

	n = 0;
	t = 0;
	str = NULL;
	printf("%d, %s", t, str);
	c = va_arg(*args, int);
	n += write(1, &c, 1);
	return (n);
}

int	ft_print_hex_flag(va_list *args, const char *str, int t)
{
	int	n;
	int	c;

	n = 0;
	t = 0;
	str = NULL;
	printf("%d, %s", t, str);
	c = va_arg(*args, int);
	n += write(1, &c, 1);
	return (n);
}
