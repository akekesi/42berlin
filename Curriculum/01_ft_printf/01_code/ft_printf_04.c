/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_04.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akekesi <akekesi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 16:31:34 by akekesi           #+#    #+#             */
/*   Updated: 2022/12/31 17:11:48 by akekesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_pad(const char *str, int f, int len_arg)
{
	int	n;
	int	pad;

	n = 0;
	pad = ft_int_in_str(str, f);
	pad -= len_arg;
	while (0 < pad)
	{
		n += ft_print_char(' ');
		pad--;
	}
	return (n);
}
