/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_flag_03.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akekesi <akekesi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 22:00:12 by akekesi           #+#    #+#             */
/*   Updated: 2023/01/07 15:48:14 by akekesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_flag_sub1(char *arg, char *prefix, int pad_a, int pad_b)
{
	int	n;

	n = 0;
	n += ft_print_str(prefix);
	n += ft_print_str(arg);
	n += ft_print_char_n(' ', pad_a);
	n += ft_print_char_n(' ', pad_b);
	return (n);
}

int	ft_print_flag_sub2(char *arg, char *prefix, int pad_a, int pad_b)
{
	int	n;

	n = 0;
	n += ft_print_char_n(' ', pad_a);
	n += ft_print_char_n(' ', pad_b);
	n += ft_print_str(prefix);
	n += ft_print_str(arg);
	return (n);
}

int	ft_print_flag_sub3(char *arg, char *prefix, int pad_a, int pad_b)
{
	int	n;

	n = 0;
	n += ft_print_str(prefix);
	n += ft_print_char_n('0', pad_a);
	n += ft_print_str(arg);
	n += ft_print_char_n(' ', pad_b);
	return (n);
}

int	ft_print_flag_sub4(char *arg, char *prefix, int pad_a, int pad_b)
{
	int	n;

	n = 0;
	n += ft_print_str(prefix);
	n += ft_print_char_n('0', pad_b);
	n += ft_print_char_n('0', pad_a);
	n += ft_print_str(arg);
	return (n);
}

int	ft_print_flag_sub5(char *arg, char *prefix, int pad_a, int pad_b)
{
	int	n;

	n = 0;
	n += ft_print_char_n(' ', pad_b);
	n += ft_print_str(prefix);
	n += ft_print_char_n('0', pad_a);
	n += ft_print_str(arg);
	return (n);
}
