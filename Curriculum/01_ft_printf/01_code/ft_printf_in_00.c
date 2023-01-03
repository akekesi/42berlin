/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_in_00.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akekesi <akekesi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 16:09:56 by akekesi           #+#    #+#             */
/*   Updated: 2023/01/01 16:09:56 by akekesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_char_in_str(int c, const char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int	ft_char_in_str_n(int c, const char *str, int n)
{
	int	i;

	i = 0;
	while (str[i] && i < n)
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int	ft_int_in_str(const char *str, int n)
{
	int	i;
	int	n_;

	i = 0;
	n_ = 0;
	while (str[i] && !ft_is_digit(str[i]) && i < n)
		i++;
	while (str[i] && ft_is_digit(str[i]) && i < n)
	{
		n_ = n_ * 10 + str[i] - '0';
		i++;
	}
	return (n_);
}

int	ft_int_in_str_dot_before(const char *str, int t)
{
	int	i;
	int	n;

	i = 0;
	while (str[i] && !ft_is_digit(str[i]) && i < t)
	{
		if (str[i] == '.')
			return (0);
		i++;
	}
	n = 0;
	while (str[i] && ft_is_digit(str[i]) && i < t)
	{
		n = n * 10 + str[i] - '0';
		i++;
	}
	return (n);
}

int	ft_int_in_str_dot_after(const char *str, int t)
{
	int	i;
	int	n;

	i = 0;
	while (str[i] && str[i] != '.' && i < t)
		i++;
	i++;
	n = 0;
	while (str[i] && ft_is_digit(str[i]) && i < t)
	{
		n = n * 10 + str[i] - '0';
		i++;
	}
	return (n);
}
