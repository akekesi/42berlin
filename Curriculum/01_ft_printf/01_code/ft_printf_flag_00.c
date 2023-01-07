/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_flag_00.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akekesi <akekesi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 20:59:03 by akekesi           #+#    #+#             */
/*   Updated: 2023/01/07 21:39:56 by akekesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_char_flag(va_list *args, t_flag_info *flag_info)
{
	int	n;
	int	arg;
	int	pad_len;

	arg = va_arg(*args, int);
	pad_len = flag_info->int_b;
	if (flag_info->minus)
	{
		n = write(1, &arg, 1);
		n += ft_print_char_n(' ', pad_len - 1);
	}
	else
	{
		n = ft_print_char_n(' ', pad_len - 1);
		n += write(1, &arg, 1);
	}
	return (n);
}

int	ft_print_str_flag(va_list *args, t_flag_info *flag_info)
{
	int		n;
	int		pad;
	char	*arg;

	arg = ft_str_to_str(va_arg(*args, char *));
	if (flag_info->dot && flag_info->int_a < ft_str_len(arg))
	{
		if (ft_str_cmp(arg, ft_get_null('s')))
			arg[flag_info->int_a] = '\0';
		else
			arg[0] = '\0';
	}
	pad = flag_info->int_b - ft_str_len(arg);
	if (flag_info->minus)
		n = ft_print_flag_sub1(arg, "\0", pad, 0);
	else
		n = ft_print_flag_sub2(arg, "\0", pad, 0);
	free(arg);
	return (n);
}
