/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akekesi <akekesi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 15:12:53 by akekesi           #+#    #+#             */
/*   Updated: 2023/01/07 15:45:39 by akekesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	int		n;
	va_list	args;

	if (!str)
		return (0);
	va_start(args, str);
	n = ft_printf_sub(str, &args);
	va_end(args);
	return (n);
}

int	ft_printf_sub(const char *str, va_list *args)
{
	int	i;
	int	n;
	int	size_ft;
	int	*flag_info;

	flag_info = (int *)malloc(sizeof(int) * 9);
	i = 0;
	n = 0;
	while (str[i])
	{
		size_ft = ft_check_print(&str[i]);
		if (size_ft)
		{
			ft_set_int_zero(flag_info, 9);
			flag_info = ft_flags_in_str(&str[i], size_ft, flag_info);
			n += ft_print_call(args, flag_info);
			i += size_ft;
		}
		else
			n += write(1, &str[i], 1);
		i++;
	}
	free(flag_info);
	return (n);
}

int	ft_print_call(va_list *args, int *flag_info)
{
	int	n;

	n = 0;
	if (flag_info[0] == 'c')
		n = ft_print_char_flag(args, flag_info);
	if (flag_info[0] == 's')
		n = ft_print_str_flag(args, flag_info);
	if (flag_info[0] == 'p')
		n = ft_print_ptr_flag(args, flag_info);
	if (flag_info[0] == 'd' || flag_info[0] == 'i')
		n = ft_print_int_flag(args, flag_info);
	if (flag_info[0] == 'u')
		n = ft_print_uint_flag(args, flag_info);
	if (flag_info[0] == 'x' || flag_info[0] == 'X')
		n = ft_print_hex_flag(args, flag_info);
	if (flag_info[0] == '%')
		n = write(1, "%", 1);
	return (n);
}
