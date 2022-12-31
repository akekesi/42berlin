/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akekesi <akekesi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 18:31:07 by akekesi           #+#    #+#             */
/*   Updated: 2022/12/31 17:16:09 by akekesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	int		n;
	va_list	args;

	va_start(args, str);
	if (!str)
		return (-1);
	n = ft_printf_sub(str, &args);
	va_end(args);
	return (n);
}

int	ft_printf_sub(const char *str, va_list *args)
{
	int		i;
	int		f;
	int		n;
	char	c;

	i = 0;
	n = 0;
	while (str[i])
	{
		f = ft_is_flag(&str[i + 1]);
		c = ft_char_in_str(str[i + f + 1], ft_get_types());
		if (str[i] == '%' && (c || f))
		{
			n += ft_print_arg(c, &str[i + 1], f, args);
			i += 1 + f;
		}	
		else
			n += ft_print_char(str[i]);
		i++;
	}
	return (n);
}

int	ft_print_arg(int c, const char *str, int f, va_list *args)
{
	int	n;

	n = 0;
	if (c == 'c')
		n = ft_print_char(va_arg(*args, int));
	if (c == 's')
		n = ft_print_str_flag(va_arg(*args, char *), str, f);
	if (c == 'p')
		n = ft_print_ptr(va_arg(*args, unsigned long long));
	if (c == 'd' || c == 'i')
		n = ft_print_int_flag(va_arg(*args, int), str, f);
	if (c == 'u')
		n = ft_print_uint(va_arg(*args, unsigned int), 0);
	if (c == 'x' || c == 'X')
		n = ft_print_hex_flag(va_arg(*args, unsigned int), c, str, f);
	if (c == '%')
		n = ft_print_char('%');
	return (n);
}
