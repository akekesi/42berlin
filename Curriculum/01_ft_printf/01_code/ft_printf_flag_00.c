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
	int	arg;
	int	pad_len;

	n = 0;
	arg = va_arg(*args, int);
	pad_len = flag_info[7];
	if (flag_info[1])
	{
		n += write(1, &arg, 1);
		n += ft_print_char_n(' ', pad_len - 1);
	}
	else
	{
		n += ft_print_char_n(' ', pad_len - 1);
		n += write(1, &arg, 1);
	}
	return (n);
}

int	ft_print_str_flag(va_list *args, int *flag_info)
{
	int		n;
	int		arg_len;
	char	c;
	char	*arg;

	n = 0;
	arg = ft_str_to_str(va_arg(*args, char *));
	arg_len = ft_str_len(arg);
	if (flag_info[2] && flag_info[8] < arg_len)
		arg[flag_info[8]] = '\0';
	c = ' ';
	if (flag_info[6] && flag_info[0] != 's')
		c = '0';
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
	free(arg);
	return (n);
}
