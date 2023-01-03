/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_in_00.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akekesi <akekesi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 16:09:56 by akekesi           #+#    #+#             */
/*   Updated: 2023/01/03 22:14:08 by akekesi          ###   ########.fr       */
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
			return (1);
		i++;
	}
	return (0);
}

int	*ft_flags_in_str(const char *str, int size, int *flags)
{
	int	i;

	i = 0;
	flags[0] = str[size];
	while (i < size)
	{
		if (str[i] == '-')
			flags[1] = 1;
		if (str[i] == '.')
			flags[2] = 1;
		if (str[i] == '#')
			flags[3] = 1;
		if (str[i] == ' ')
			flags[4] = 1;
		if (str[i] == '+')
			flags[5] = 1;
		i++;
	}
	flags[6] = ft_is_first_int_zero(str, size);
	flags[7] = ft_int_in_str_dot_before(str, size);
	flags[8] = ft_int_in_str_dot_after(str, size);
	return (flags);
}

int	ft_int_in_str_dot_before(const char *str, int size)
{
	int	i;
	int	n;

	i = 0;
	while (str[i] && !ft_is_digit(str[i]) && i < size)
	{
		if (str[i] == '.')
			return (0);
		i++;
	}
	n = 0;
	while (str[i] && ft_is_digit(str[i]) && i < size)
	{
		n = n * 10 + str[i] - '0';
		i++;
	}
	return (n);
}

int	ft_int_in_str_dot_after(const char *str, int size)
{
	int	i;
	int	n;

	i = 0;
	while (str[i] && str[i] != '.' && i < size)
		i++;
	i++;
	n = 0;
	while (str[i] && ft_is_digit(str[i]) && i < size)
	{
		n = n * 10 + str[i] - '0';
		i++;
	}
	return (n);
}
