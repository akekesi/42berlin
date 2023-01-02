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
