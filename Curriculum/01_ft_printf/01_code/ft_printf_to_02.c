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

char	*ft_hex_to_str(unsigned int n)
{
	int		len;
	char	*arg;

	len = ft_hex_len(n);
	arg = (char *)malloc(sizeof(char) * (len + 1));
	arg[len] = '\0';
	if (!n)
	{
		arg[0] = '0';
		return (arg);
	}
	arg = ft_hex_to_str_sub(n, arg, len);
	return (arg);
}

char	*ft_hex_to_str_sub(unsigned int n, char *arg, int size)
{
	int	rest;

	while (n)
	{
		size--;
		rest = n % 16;
		if (rest < 10)
			arg[size] = rest + '0';
		if (9 < rest)
			arg[size] = rest - 10 + 'a';
		n /= 16;
	}
	return (arg);
}

void	ft_str_to_upper(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if ('a' <= str[i] && str[i] <= 'z')
			str[i] = str[i] - 'a' + 'A';
		i++;
	}
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
