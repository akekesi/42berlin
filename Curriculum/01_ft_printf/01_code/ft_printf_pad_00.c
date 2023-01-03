/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_pad_00.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akekesi <akekesi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 18:30:53 by akekesi           #+#    #+#             */
/*   Updated: 2023/01/01 18:30:53 by akekesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_pad_pos(char *arg, int *flags_info)
{
	int	n;
	int	c;
	int	pad_len;
	int	arg_len;

	n = 0;
	c = ' ';
	if (flags_info[6])
		c = '0';
	pad_len = flags_info[7];
	arg_len = ft_str_len(arg);
	pad_len -= arg_len ;
	if (flags_info[1])
	{
		n += ft_print_str(arg);
		n += ft_print_pad(c, pad_len);
	}
	else
	{
		n += ft_print_pad(c, pad_len);
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
