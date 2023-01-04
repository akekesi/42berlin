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
