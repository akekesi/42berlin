/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_to_02.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akekesi <akekesi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 04:41:09 by akekesi           #+#    #+#             */
/*   Updated: 2023/01/04 04:41:09 by akekesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_hex_to_str(unsigned int n, int *flags_info)
{
	int		len;
	char	*arg;

	len = ft_hex_len(n);
	if (flags_info[3] && n)
		len += 2;
	arg = (char *)malloc(sizeof(char) * (len + 1));
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
	arg = ft_hex_to_str_sub(n, arg, flags_info, len);
	return (arg);
}

char	*ft_hex_to_str_sub(unsigned int n, char *arg, int *flags_info, int len)
{
	int		rest;

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
	char	*arg;

	if (n == 0)
	{
		len = ft_str_len(ft_get_null('p'));
		arg = (char *)malloc(sizeof(char) * (len + 1));
		arg = ft_str_cpy(arg, ft_get_null('p'));
		return (arg);
	}
	arg = ft_ptr_to_str_sub(n);
	return (arg);
}

char	*ft_ptr_to_str_sub(unsigned long long n)
{
	int		len;
	int		rest;
	char	*arg;

	len = ft_hexll_len(n) + 2;
	arg = (char *)malloc(sizeof(char) * (len + 1));
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
