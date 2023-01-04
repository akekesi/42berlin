/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_flag_01.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akekesi <akekesi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 22:00:12 by akekesi           #+#    #+#             */
/*   Updated: 2023/01/04 02:36:59 by akekesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_int_flag(va_list *args, int *flags_info)
{
	int		n;
	char	*arg;

	n = 0;
	arg = ft_int_to_str(va_arg(*args, int));
	n = ft_print_pad_pos(arg, flags_info);
	free(arg);
	return (n);
}

int	ft_print_uint_flag(va_list *args, int *flags_info)
{
	int		n;
	char	*arg;

	n = 0;
	arg = ft_uint_to_str(va_arg(*args, unsigned int));
	n = ft_print_pad_pos(arg, flags_info);
	free(arg);
	return (n);
}

int	ft_print_hex_flag(va_list *args, int *flags_info)
{
	int		n;
	char	*arg;

	n = 0;
	arg = ft_hex_to_str(va_arg(*args, unsigned int), flags_info);
	n = ft_print_pad_pos(arg, flags_info);
	free(arg);
	return (n);
}

int	ft_print_ptr_flag(va_list *args, int *flags_info)
{
	int		n;
	int		dot_int;
	char	*arg;

	n = 0;
	arg = ft_ptr_to_str(va_arg(*args, unsigned long long));
	if (flags_info[2])
	{
		dot_int = flags_info[8];
		if (dot_int < ft_str_len(arg))
			arg[dot_int] = '\0';
	}
	n += ft_print_pad_pos(arg, flags_info);
	free(arg);
	return (n);
}
