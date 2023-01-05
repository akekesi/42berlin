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

int	ft_print_ptr_flag(va_list *args, int *flag_info)
{
	int		n;
	int		pad_a;
	int		pad_b;
	char	*arg;
	char	*prefix;

	arg = ft_ptr_to_str(va_arg(*args, unsigned long long));
	if (!ft_str_cmp(arg, ft_get_null('p')))
		prefix = "\0";
	else if (flag_info[5])
		prefix = ft_get_prefix(arg[0] - '0', 1, 'p', '+');
	else if (flag_info[4])
		prefix = ft_get_prefix(arg[0] - '0', 1, 'p', ' ');
	else
		prefix = ft_get_prefix(arg[0] - '0', 1, 'p', 0);
	pad_a = ft_neg_to_zero(flag_info[8] - ft_str_len(arg));
	pad_b = flag_info[7] - pad_a - ft_str_len(arg) - ft_str_len(prefix);
	if (flag_info[1])
		n = ft_print_ptr_flag_sub1(arg, prefix, pad_a, pad_b);
	else if (flag_info[6] && !flag_info[2])
		n = ft_print_ptr_flag_sub2(arg, prefix, pad_a, pad_b);
	else
		n = ft_print_ptr_flag_sub3(arg, prefix, pad_a, pad_b);
	free(arg);
	return (n);
}

int	ft_print_ptr_flag_sub1(char *arg, char *prefix, int pad_a, int pad_b)
{
	int	n;

	n = 0;
	n += ft_print_str(prefix);
	n += ft_print_char_n('0', pad_a);
	n += ft_print_str(arg);
	n += ft_print_char_n(' ', pad_b);
	return (n);
}

int	ft_print_ptr_flag_sub2(char *arg, char *prefix, int pad_a, int pad_b)
{
	int	n;

	n = 0;
	n += ft_print_str(prefix);
	n += ft_print_char_n('0', pad_b);
	n += ft_print_char_n('0', pad_a);
	n += ft_print_str(arg);
	return (n);
}

int	ft_print_ptr_flag_sub3(char *arg, char *prefix, int pad_a, int pad_b)
{
	int	n;

	n = 0;
	n += ft_print_char_n(' ', pad_b);
	n += ft_print_str(prefix);
	n += ft_print_char_n('0', pad_a);
	n += ft_print_str(arg);
	return (n);
}
