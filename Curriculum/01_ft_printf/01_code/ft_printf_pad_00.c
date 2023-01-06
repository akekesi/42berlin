/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_pad_00.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akekesi <akekesi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 18:30:53 by akekesi           #+#    #+#             */
/*   Updated: 2023/01/04 02:25:01 by akekesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_pad_pos(char *arg, int *flag_info)
{
	int	n;
	int	c;
	int	arg_len;

	n = 0;
	c = ' ';
	if (flag_info[6])
		c = '0';
	arg_len = ft_str_len(arg);
	if (flag_info[6] && arg_len < flag_info[7] && arg[0] == '-')
	{
		n += write(1, "-", 1);
		arg++;
	}
	if (arg[0] != '-')
	{
		if (flag_info[5])
			n += write(1, "+", 1);
		else if (flag_info[4])
			n += write(1, " ", 1);
	}
	if (flag_info[2])
	{
		if (arg[0] == '-')
		{
			n += write(1, "-", 1);
			arg++;
			arg_len--;
		}
		n += ft_print_char_n('0', flag_info[8] - arg_len);
	}	
	if (flag_info[1])
	{
		n += ft_print_str(arg);
		n += ft_print_char_n(c, flag_info[7] - arg_len);
	}
	else
	{
		n += ft_print_char_n(c, flag_info[7] - arg_len);
		n += ft_print_str(arg);
	}
	return (n);
}
