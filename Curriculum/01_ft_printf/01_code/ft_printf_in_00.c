/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_in_00.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akekesi <akekesi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 16:09:56 by akekesi           #+#    #+#             */
/*   Updated: 2023/01/04 02:25:08 by akekesi          ###   ########.fr       */
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

int	*ft_flags_in_str(const char *str, int size, int *flag_info)
{
	int	i;

	i = 0;
	flag_info[0] = str[size];
	while (i < size)
	{
		if (str[i] == '-')
			flag_info[1] = 1;
		if (str[i] == '.')
			flag_info[2] = 1;
		if (str[i] == '#')
			flag_info[3] = 1;
		if (str[i] == ' ')
			flag_info[4] = 1;
		if (str[i] == '+')
			flag_info[5] = 1;
		i++;
	}
	flag_info[6] = ft_is_first_int_zero(str, size);
	flag_info[7] = ft_int_in_str_dot_before(str, size);
	flag_info[8] = ft_int_in_str_dot_after(str, size);
	return (flag_info);
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
