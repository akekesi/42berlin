/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akekesi <akekesi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 18:31:07 by akekesi           #+#    #+#             */
/*   Updated: 2022/12/30 17:08:35 by akekesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	int		i;
	int		n;
	char	c;
	va_list	args;

	va_start(args, str);
	i = 0;
	n = 0;
	if (!str)
		return (-1);
	while (str[i])
	{
		c = ft_char_in_str(str[i + 1], "cspdiuxX%");
		if (str[i] == '%' && c)
		{
			n += ft_print_arg(c, &args);
			i++;
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

int	ft_print_arg(int c, va_list *args)
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
		n = ft_print_hex(va_arg(*args, unsigned int), c, 0);
	if (c == '%')
		n = ft_print_char('%');
	return (n);
}
