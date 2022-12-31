/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_01.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akekesi <akekesi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 17:01:40 by akekesi           #+#    #+#             */
/*   Updated: 2022/12/31 02:28:26 by akekesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_char(int c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_print_str(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
		return (write(1, "(null)", 6));
	while (str[i])
	{
		ft_print_char(str[i]);
		i++;
	}
	return (i);
}

int	ft_print_str_flag(char *arg, const char *str, int f)
{
	int	n;
	int	pad;

	n = 0;
	if (arg != NULL)
	{
		pad = ft_int_in_str(str, f);
		pad -= ft_str_len(arg);
		while (0 < pad)
		{
			n += ft_print_char(' ');
			pad--;
		}
	}
	n += ft_print_str(arg);
	return (n);
}

int	ft_str_len(const char *str)
{
	int	n;

	n = 0;
	while (str[n])
		n++;
	return (n);
}
