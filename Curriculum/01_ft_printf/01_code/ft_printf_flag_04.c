/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_flag_04.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akekesi <akekesi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 22:00:12 by akekesi           #+#    #+#             */
/*   Updated: 2023/01/06 18:25:49 by akekesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_flag_sub6(char *arg, int pad, int c)
{
	int	n;

	n = 0;
	n += ft_print_str(arg);
	n += ft_print_char_n(c, pad);
	return (n);
}

int	ft_print_flag_sub7(char *arg, int pad, int c)
{
	int	n;

	n = 0;
	n += ft_print_char_n(c, pad);
	n += ft_print_str(arg);
	return (n);
}
