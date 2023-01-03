/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_pad_00.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akekesi <akekesi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 18:30:53 by akekesi           #+#    #+#             */
/*   Updated: 2023/01/04 00:11:03 by akekesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_pad_pos(char *arg, int *flag_info)
{
	int	n;
	int	c;
	int	pad_dot;
	int	arg_len;

	n = 0;
	c = ' ';
	if (flag_info[6] && flag_info[0] != 's')
		c = '0';
	pad_dot = flag_info[7];
	arg_len = ft_str_len(arg);
	pad_dot -= arg_len;
	if (flag_info[0] == 'i' || flag_info[0] == 'd')
	{
		if (flag_info[6] && arg_len < flag_info[7] && arg[0] == '-')
		{
			n += write(1, "-", 1);
			arg += 1;
		}
		if (arg[0] != '-')
		{
			if (flag_info[5])
				n += write(1, "+", 1);
			else if (flag_info[4])
				n += write(1, " ", 1);
		}
	}
	if (flag_info[1])
	{
		n += ft_print_str(arg);
		n += ft_print_pad(c, pad_dot);
	}
	else
	{
		n += ft_print_pad(c, pad_dot);
		n += ft_print_str(arg);
	}
	return (n);
}

int	ft_print_pad(int c, int n)
{
	int	i;
	int	n_;

	i = 0;
	n_ = 0;
	while (i < n)
	{
		n_ += write(1, &c, 1);
		i++;
	}
	return (n_);
}
