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

int	ft_print_char_flag(va_list *args, int *flags_info)
{
	int	n;
	int	arg;
	int	pad_len;

	n = 0;
	arg = va_arg(*args, int);
	pad_len = flags_info[7];
	if (flags_info[1])
	{
		n += write(1, &arg, 1);
		n += ft_print_pad(' ', pad_len - 1);
	}
	else
	{
		n += ft_print_pad(' ', pad_len - 1);
		n += write(1, &arg, 1);
	}
	return (n);
}

int	ft_print_str_flag(va_list *args, int *flags_info)
{
	int		n;
	int		dot_int;
	char	*arg;

	n = 0;
	arg = ft_str_to_str(va_arg(*args, char *));
	if (flags_info[2])
	{
		dot_int = flags_info[8];
		if (dot_int < ft_str_len(arg))
			arg[dot_int] = '\0';
	}
	n = ft_print_pad_pos(arg, flags_info);
	free(arg);
	return (n);
}
