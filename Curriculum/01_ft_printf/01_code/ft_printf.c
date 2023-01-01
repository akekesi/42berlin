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

int	ft_printf(const char *str, ...)
{
	int		i;
	int		n;
	int		t;
	va_list	args;

	if (!str)
		return (0);
	va_start(args, str);
	i = 0;
	n = 0;
	while (str[i])
	{
		t = ft_check_print(&str[i]);
		if (t)
		{
			n += ft_print_call(&args, &(str[i + 1]), t - 1);
			i += t;
		}
		else
			n += write(1, &str[i], 1);
		i++;
	}
	va_end(args);
	return (n);
}

int	ft_print_call(va_list *args, const char *str, int t)
{
	int	n;

	n = 0;
	if (*(str + t) == 'c')
		n = ft_print_char_flag(args, str, t);
	if (*(str + t) == 's')
		n = ft_print_str_flag(args, str, t);
	if (*(str + t) == 'p')
		n = ft_print_ptr_flag(args, str, t);
	if (*(str + t) == 'd' || *(str + t) == 'i')
		n = ft_print_int_flag(args, str, t);
	if (*(str + t) == 'u')
		n = ft_print_uint_flag(args, str, t);
	if (*(str + t) == 'x' || *(str + t) == 'X')
		n = ft_print_hex_flag(args, str, t);
	if (*(str + t) == '%')
		n = write(1, "%", 1);
	return (n);
}
