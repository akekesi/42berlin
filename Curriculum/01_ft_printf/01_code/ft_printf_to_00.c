/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_to_00.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akekesi <akekesi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 20:51:37 by akekesi           #+#    #+#             */
/*   Updated: 2023/01/01 20:51:37 by akekesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
// !!! return (strcpy(str_, str)); // sajat fuggvenyt irni erre az str-ben!!!
// !!! return (strcpy(str_, str)); // sajat fuggvenyt irni erre az int-ben!!!

char	*ft_char_to_str(int c)
{
	char	*arg;

	arg = (char *)malloc(sizeof(char) * 2);
	if (!arg)
		return (NULL);
	arg[0] = c;
	arg[1] = '\0';
	return (arg);
}

char	*ft_str_to_str(char *str)
{
	char	*arg;

	if (str == NULL)
		str = ft_get_null('s');
	arg = (char *)malloc(sizeof(char) * (ft_str_len(str) + 1));
	if (!arg)
		return (NULL);

	return (strcpy(arg, str)); // sajat fuggvenyt irni !!!
}

char	*ft_int_to_str(int n)
{
	int		len;
	char	*arg;

	len = ft_int_len(n);
	arg = (char *)malloc(sizeof(char) * (len + 1));
	if (!arg)
		return (NULL);
	arg[len] = '\0';
	if (n == 0)
	{
		arg[0] = '0';
		return (arg);
	}
	if (n == -2147483648)
		return (strcpy(arg, "-2147483648")); // ??? mukodik + sajat fuggvenyt
	if (n < 0)
	{
		n *= -1;
		arg[0] = '-';
	}
	while (n)
	{
		arg[len] = (n % 10) + '0';
		n /= 10;
		len--;
	}
	return (arg);
}

char	*ft_uint_to_str(unsigned int n)
{
	int		len;
	char	*arg;

	len = ft_uint_len(n);
	arg = (char *)malloc(sizeof(char) * (len + 1));
	if (!arg)
		return (NULL);
	arg[len] = '\0';
	if (n == 0)
	{
		arg[0] = '0';
		return (arg);
	}
	while (n)
	{
		arg[len] = (n % 10) + '0';
		n /= 10;
		len--;
	}
	return (arg);
}

char	*ft_ull_to_str(unsigned long long n)
{
	int		len;
	char	*arg;

	len = ft_ull_len(n);
	arg = (char *)malloc(sizeof(char) * (len + 1));
	if (!arg)
		return (NULL);
	arg[len] = '\0';
	if (n == 0)
	{
		arg[0] = '0';
		return (arg);
	}
	while (n)
	{
		arg[len] = (n % 10) + '0';
		n /= 10;
		len--;
	}
	return (arg);
}

char	*ft_hex_to_str(unsigned int n)
{
	int		len;
	int		rest;
	char	*arg;

	len = ft_hex_len(n);
	arg = (char *)malloc(sizeof(char) * (len + 1));
	if (!arg)
		return (NULL);
	arg[len] = '\0';
	if (n == 0)
	{
		arg[0] = '0';
		return (arg);
	}
	while (n)
	{
		rest = n % 16;
		if (rest < 10)
			arg[len] = rest + '0';
		if (9 < rest)
			arg[len] = rest - 10 + 'a';
		n /= 16;
		len--;
	}
	return (arg);
}
