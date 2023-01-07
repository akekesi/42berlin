/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_flag_01.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akekesi <akekesi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 22:00:12 by akekesi           #+#    #+#             */
/*   Updated: 2023/01/07 21:39:29 by akekesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_hex_flag(va_list *args, t_flag_info *flag_info)
{
	int		n;
	int		pad_a;
	int		pad_b;
	char	*arg;
	char	*prefix;

	arg = ft_hex_to_str(va_arg(*args, unsigned int));
	if (flag_info->type == 'X')
		ft_str_to_upper(arg);
	if (flag_info->dot && flag_info->int_a < ft_str_len(arg))
		if (!ft_str_cmp(arg, "0"))
			arg[0] = '\0';
	prefix = ft_get_prefix_main(
			arg[0] - '0', flag_info->hashtag, flag_info->type, 0);
	pad_a = ft_neg_to_zero(flag_info->int_a - ft_str_len(arg));
	pad_b = flag_info->int_b - pad_a - ft_str_len(arg) - ft_str_len(prefix);
	if (flag_info->minus)
		n = ft_print_flag_sub3(arg, prefix, pad_a, pad_b);
	else if (flag_info->zero && !flag_info->dot)
		n = ft_print_flag_sub4(arg, prefix, pad_a, pad_b);
	else
		n = ft_print_flag_sub5(arg, prefix, pad_a, pad_b);
	free(arg);
	return (n);
}

int	ft_print_ptr_flag(va_list *args, t_flag_info *flag_info)
{
	int		n;
	int		pad_a;
	int		pad_b;
	char	*arg;
	char	*prefix;

	arg = ft_ptr_to_str(va_arg(*args, unsigned long long));
	prefix = ft_get_prefix_ptr(arg, flag_info);
	pad_a = ft_neg_to_zero(flag_info->int_a - ft_str_len(arg));
	pad_b = flag_info->int_b - pad_a - ft_str_len(arg) - ft_str_len(prefix);
	if (!ft_str_cmp(arg, ft_get_null('p')))
	{
		if (flag_info->minus)
			n = ft_print_flag_sub1(arg, prefix, pad_a, pad_b);
		else
			n = ft_print_flag_sub2(arg, prefix, pad_a, pad_b);
	}	
	else if (flag_info->minus)
		n = ft_print_flag_sub3(arg, prefix, pad_a, pad_b);
	else if (flag_info->zero && !flag_info->dot)
		n = ft_print_flag_sub4(arg, prefix, pad_a, pad_b);
	else
		n = ft_print_flag_sub5(arg, prefix, pad_a, pad_b);
	free(arg);
	return (n);
}
