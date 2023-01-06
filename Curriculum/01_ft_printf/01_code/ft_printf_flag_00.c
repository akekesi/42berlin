/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_flag_00.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akekesi <akekesi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 20:59:03 by akekesi           #+#    #+#             */
/*   Updated: 2023/01/03 22:13:52 by akekesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_char_flag(va_list *args, int *flag_info)
{
	int	n;
	int	c;
	int	arg;
	int	pad_len;

	n = 0;
	arg = va_arg(*args, int);
	pad_len = flag_info[7];
	c = ' ';
	if (flag_info[6] && !flag_info[1])
		c = '0';
	if (flag_info[1])
	{
		n += write(1, &arg, 1);
		n += ft_print_char_n(c, pad_len - 1);
	}
	else
	{
		n += ft_print_char_n(c, pad_len - 1);
		n += write(1, &arg, 1);
	}
	return (n);
}

int	ft_print_str_flag(va_list *args, int *flag_info)
{
	int		n;
	int		c;
	int		pad;
	char	*arg;

	n = 0;
	arg = ft_str_to_str(va_arg(*args, char *));
	if (flag_info[2] && flag_info[8] < ft_str_len(arg))
		arg[flag_info[8]] = '\0';
	pad = flag_info[7] - ft_str_len(arg);
	c = ' ';
	if (flag_info[6] && !flag_info[1])
		c = '0';
	if (flag_info[1])
	{
		n += ft_print_str(arg);
		n += ft_print_char_n(c, pad);
	}
	else
	{
		n += ft_print_char_n(c, pad);
		n += ft_print_str(arg);
	}
	free(arg);
	return (n);
}
