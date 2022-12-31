/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_00.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akekesi <akekesi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 16:13:18 by akekesi           #+#    #+#             */
/*   Updated: 2022/12/31 17:13:04 by akekesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
	while (ft_char_in_str(str[i], ft_get_flags()))
	{
		i++;
		if (ft_char_in_str(str[i], ft_get_types()))
			return (i);
	}
	return (0);
}

int	ft_int_in_str(const char *str, int n)
{
	int	i;
	int	nbr;

	i = 0;
	while (str[i] && !ft_isdigit(str[i]) && i < n)
		i++;
	nbr = 0;
	while (str[i] && ft_isdigit(str[i]) && i < n)
	{
		nbr = nbr * 10 + str[i] - '0';
		i++;
	}
	return (nbr);
}

int	ft_isdigit(int c)
{
	if ('0' <= c && c <= '9')
		return (1);
	return (0);
}

int	ft_str_len(const char *str)
{
	int	n;

	n = 0;
	while (str[n])
		n++;
	return (n);
}
