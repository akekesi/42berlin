/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akekesi <akekesi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 15:12:53 by akekesi           #+#    #+#             */
/*   Updated: 2023/01/01 15:12:53 by akekesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "test.h" // test

int	ft_printf(const char *str, ...)
{
	int		i;
	int		n;
	int		t;
	int		*flags_info;
	va_list	args;

	if (!str)
		return (0);
	flags_info = (int *)malloc(sizeof(int) * 9); // hard coded
	if (!flags_info)
		return (0); // needed?
	va_start(args, str);
	i = 0;
	n = 0;
	while (str[i])
	{
		t = ft_check_print(&str[i]);
		if (t)
		{
			ft_set_zero(flags_info, 9);
			flags_info = ft_flags_in_str(&str[i], t, flags_info);
			test_print_flags_info(flags_info); // test: flag_info
			n += ft_print_call(&args, flags_info);
			i += t;
		}
		else
			n += write(1, &str[i], 1);
		i++;
	}
	va_end(args);
	free(flags_info);
	return (n);
}

int	ft_print_call(va_list *args, int *flags_info)
{
	int	n;

	n = 0;
	if (flags_info[0] == 'c')
		n = ft_print_char_flag(args, flags_info);
	if (flags_info[0] == 's')
		n = ft_print_str_flag(args, flags_info);
	if (flags_info[0] == 'p')
		n = ft_print_ptr_flag(args, flags_info);
	if (flags_info[0] == 'd' || flags_info[0] == 'i')
		n = ft_print_int_flag(args, flags_info);
	if (flags_info[0] == 'u')
		n = ft_print_uint_flag(args, flags_info);
	if (flags_info[0] == 'x' || flags_info[0] == 'X')
		n = ft_print_hex_flag(args, flags_info);
	if (flags_info[0] == '%')
		n = write(1, "%", 1);
	return (n);
}
