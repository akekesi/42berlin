/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_len_00.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akekesi <akekesi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 13:18:35 by akekesi           #+#    #+#             */
/*   Updated: 2023/01/02 13:18:35 by akekesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_str_len(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_int_len(int n)
{
	int	i;

	i = 0;
	if (!n)
		return (1);
	if (n == -2147483648)
		return (11);
	if (n < 0)
	{
		i++;
		n *= -1;
	}
	while(n)
	{
		i++;
		n /= 10;
	}
	return (i);
}

int	ft_uint_len(unsigned int n)
{
	int	i;

	i = 0;
	if (!n)
		return (1);
	while(n)
	{
		i++;
		n /= 10;
	}
	return (i);
}

int	ft_ull_len(unsigned long long n)
{
	int	i;

	i = 0;
	if (!n)
		return (1);
	while(n)
	{
		i++;
		n /= 10;
	}
	return (i);
}

int	ft_hex_len(unsigned int n)
{
	int	i;

	i = 0;
	if (!n)
		return (1);
	while(n)
	{
		i++;
		n /= 16;
	}
	return (i);
}
