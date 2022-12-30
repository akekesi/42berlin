/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akekesi <akekesi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 18:31:07 by akekesi           #+#    #+#             */
/*   Updated: 2022/12/30 20:48:09 by akekesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	ft_printf(const char *str, ...)
{
	int		i;
	int		f;
	int		n;
	char	c;
	va_list	args;

	va_start(args, str);
	i = 0;
	f = 0;
	n = 0;
	if (!str)
		return (-1);
	while (str[i])
	{
		f = ft_is_flag(&str[i + 1]);
		c = ft_char_in_str(str[i + f + 1], "cspdiuxX%");
		if (str[i] == '%' && (c || f))
		{
			n += ft_print_arg(c, &str[i + 1], f, &args);
			i += 1 + f;
		}	
		else
			n += ft_print_char(str[i]);
		i++;
	}
	va_end(args);
	return (n);
}

int	ft_char_in_str(int c, char *str)
{
	while (*str)
	{
		if (*str == c)
			return (c);
		str++;
	}
	return (0);
}

int	ft_char_in_str_n(int c, const char *str, int n)
{
	int	i;

	i = 0;
	while (str[i] && i < n)
	{
		if (str[i] == c)
			return (c);
		i++;
	}
	return (0);
}

int	ft_is_flag(const char *str)
{
	int	i;

	i = 0;
	while (ft_char_in_str(str[i], "-0123456789.# +"))
	{
		i++;
		if (ft_char_in_str(str[i], "cspdiuxX%"))
			return (i);
	}
	return (0);
}

int	ft_print_arg(int c, const char *str, int f, va_list *args)
{
	int	n;

	n = 0;
	if (c == 'c')
		n = ft_print_char(va_arg(*args, int));
	if (c == 's')
		n = ft_print_str(va_arg(*args, char *));
	if (c == 'p')
		n = ft_print_ptr(va_arg(*args, unsigned long long));
	if (c == 'd' || c == 'i')
		n = ft_print_int(va_arg(*args, int), 0);
	if (c == 'u')
		n = ft_print_uint(va_arg(*args, unsigned int), 0);
	if (c == 'x' || c == 'X')
		n = ft_print_hex_flag(va_arg(*args, unsigned int), c, str, f);
	if (c == '%')
		n = ft_print_char('%');
	return (n);
}
