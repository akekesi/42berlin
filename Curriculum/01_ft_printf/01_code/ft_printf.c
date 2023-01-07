/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akekesi <akekesi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 15:12:53 by akekesi           #+#    #+#             */
/*   Updated: 2023/01/07 22:01:17 by akekesi          ###   ########.fr       */
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
	int			i;
	int			n;
	int			size_ft;
	t_flag_info	*flag_info;

	flag_info = (t_flag_info *)malloc(sizeof(t_flag_info) * 1);
	i = 0;
	n = 0;
	while (str[i])
	{
		size_ft = ft_check_print(&str[i]);
		if (size_ft)
		{
			ft_set_flag_info_zero(flag_info);
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

int	ft_print_call(va_list *args, t_flag_info *flag_info)
{
	int	n;

	n = 0;
	if (flag_info->type == 'c')
		n = ft_print_char_flag(args, flag_info);
	if (flag_info->type == 's')
		n = ft_print_str_flag(args, flag_info);
	if (flag_info->type == 'p')
		n = ft_print_ptr_flag(args, flag_info);
	if (flag_info->type == 'd' || flag_info->type == 'i')
		n = ft_print_int_flag(args, flag_info);
	if (flag_info->type == 'u')
		n = ft_print_uint_flag(args, flag_info);
	if (flag_info->type == 'x' || flag_info->type == 'X')
		n = ft_print_hex_flag(args, flag_info);
	if (flag_info->type == '%')
		n = write(1, "%", 1);
	return (n);
}
