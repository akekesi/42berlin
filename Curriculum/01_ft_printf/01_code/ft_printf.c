/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akekesi <akekesi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 18:31:07 by akekesi           #+#    #+#             */
/*   Updated: 2022/12/28 20:35:19 by akekesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include "test.h"

int		ft_printf(const char *str, ...);
char	*ft_types(void);
int		ft_char_in_str(int c, char *str);
int		ft_print_arg(int c, va_list *args);
int		ft_print_char(int c);
int		ft_print_str(char *str);
int		ft_print_ptr(unsigned long long ptr);
int		ft_print_int(int n, int i);
int		ft_print_uint(unsigned int n, int i);
int		ft_print_hex(unsigned int n, char c);

int	ft_printf(const char *str, ...)
{
	int		i;
	int		n;
	char	c;
	va_list	args;

	va_start(args, str);
	i = 0;
	n = 0;
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

char	*ft_types(void)
{
	return ("cspdiuxX%");
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
	// just for test in windows (not increment) ???
	int	n;

	n = 0;
	if (c == 'c' || c == '%')
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
		n = ft_print_hex(va_arg(*args, unsigned int), c);
	return (n);
}

int	ft_print_char(int c) 
{
	write(1, &c, 1);
	return (1);
}

int	ft_print_str(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		ft_print_char(str[i]);
		i++;
	}
	return (i);
}

int	ft_print_ptr(unsigned long long ptr)
{
	return (0);
}

int	ft_print_int(int n, int i)
{
	if (n == -2147483648)
		i += ft_print_str("-2147483648");
	else
	{
		if (n < 0)
		{
			i += ft_print_char('-');
			n *= -1;
		}
		if (9 < n)
		{
			i += ft_print_int(n / 10, i);
		}
		i += ft_print_char((n % 10) + '0');
	}
	return (i);
}

int	ft_print_uint(unsigned int n, int i)
{
	if (9 < n)
		i += ft_print_int(n / 10, i);
	i += ft_print_char((n % 10) + '0');
	return (i);}

int	ft_print_hex(unsigned int n, char c)
{
	return (0);
}
