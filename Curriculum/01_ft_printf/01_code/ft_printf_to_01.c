/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_to_01.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akekesi <akekesi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 22:04:42 by akekesi           #+#    #+#             */
/*   Updated: 2023/01/03 23:21:25 by akekesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
		return (ft_str_cpy(arg, "-2147483648"));
	if (n < 0)
	{
		n *= -1;
		arg[0] = '-';
	}
	while (n)
	{
		len--;
		arg[len] = (n % 10) + '0';
		n /= 10;
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
		len--;
		arg[len] = (n % 10) + '0';
		n /= 10;
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
		len--;
		arg[len] = (n % 10) + '0';
		n /= 10;
	}
	return (arg);
}

char	*ft_hex_to_str(unsigned int n, int *flags_info)
{
	int		len;
	int		rest;
	char	*arg;

	len = ft_hex_len(n);
	if (flags_info[3] && n)
	{
		len += 2;
	}
	arg = (char *)malloc(sizeof(char) * (len + 1));
	if (!arg)
		return (NULL);
	if (flags_info[3] && n)
	{
		arg[0] = '0';
		arg[1] = flags_info[0] + '\0';
	}
	arg[len] = '\0';
	if (n == 0)
	{
		arg[0] = '0';
		return (arg);
	}
	while (n)
	{
		len--;
		rest = n % 16;
		if (rest < 10)
			arg[len] = rest + '0';
		if (9 < rest)
			arg[len] = rest - 10 + 'a' - 'x' + flags_info[0];
		n /= 16;
	}
	return (arg);
}

char	*ft_ptr_to_str(unsigned long long n)
{
	int		len;
	int		rest;
	char	*arg;

	if (n == 0)
	{
		len = ft_str_len(ft_get_null('p'));
		arg = (char *)malloc(sizeof(char) * (len + 1));
		arg = ft_str_cpy(arg, ft_get_null('p'));
		return (arg);
	}
	len = ft_hexll_len(n) + 2;
	arg = (char *)malloc(sizeof(char) * (len + 1));
	if (!arg)
		return (NULL);
	arg[0] = '0';
	arg[1] = 'x';
	arg[len] = '\0';
	while (n)
	{
		len--;
		rest = n % 16;
		if (rest < 10)
			arg[len] = rest + '0';
		if (9 < rest)
			arg[len] = rest - 10 + 'a';
		n /= 16;
	}
	return (arg);
}
