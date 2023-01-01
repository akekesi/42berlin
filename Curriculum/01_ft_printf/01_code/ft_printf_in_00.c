/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_in_00.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akekesi <akekesi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 03:58:52 by akekesi           #+#    #+#             */
/*   Updated: 2023/01/01 03:58:56 by akekesi          ###   ########.fr       */
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

int	ft_int_in_str(const char *str, int n)
{
	int	i;
	int	n_;

	i = 0;
	while (str[i] && !ft_is_digit(str[i]) && i < n)
		i++;
	n_ = 0;
	while (str[i] && ft_is_digit(str[i]) && i < n)
	{
		n_ = n_ * 10 + str[i] - '0';
		i++;
	}
	return (n_);
}

int	ft_first_int_in_str_zero(const char *str, int n)
{
	int	i;

	i = 0;
	while (str[i] && !ft_is_digit(str[i]) && i < n)
		i++;
	if (ft_is_digit(str[i]) && str[i] == '0')
		return (1);
	return (0);
}
