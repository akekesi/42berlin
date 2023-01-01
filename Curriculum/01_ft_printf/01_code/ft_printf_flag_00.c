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
	int		n;
	char	*arg;

	arg = ft_char_to_str(va_arg(*args, int));
	if (!arg)
		return (0);
	n = ft_print_pad_pos(arg, str, t, ' ');
	return (n);
}

int	ft_print_str_flag(va_list *args, const char *str, int t)
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
