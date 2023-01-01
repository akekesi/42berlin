/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_len_00.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akekesi <akekesi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 03:56:00 by akekesi           #+#    #+#             */
/*   Updated: 2023/01/01 03:56:33 by akekesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_str_len(const char *str)
{
	int	n;

	n = 0;
	while (str[n])
		n++;
	return (n);
}

int	ft_int_len(int n)
{
	int	i;

	i = 0;
	if (n == -2147483648)
		return (11);
	if (!n)
		return (1);
	if (n < 0)
	{
		i++;
		n *= -1;
	}
	while (n)
	{
		n /= 10;
		i++;
	}
	return (i);
}

int	ft_uint_len(unsigned int n)
{
	int	i;

	i = 0;
	if (!n)
		return (1);
	while (n)
	{
		n /= 10;
		i++;
	}
	return (i);
}

int	ft_hex_len(unsigned int n)
{
	int	i;

	i = 0;
	if (!n)
		return (1);
	while (n)
	{
		n /= 16;
		i++;
	}
	return (i);
}

int	ft_ull_len(unsigned long long n)
{
	int	i;

	i = 0;
	if (!n)
		return (1);
	while (n)
	{
		n /= 16;
		i++;
	}
	return (i);
}
