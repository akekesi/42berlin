/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_set_00.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akekesi <akekesi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 17:21:33 by akekesi           #+#    #+#             */
/*   Updated: 2023/01/07 21:27:11 by akekesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_set_flag_info_zero(t_flag_info *flag_info)
{
	flag_info->type = 0;
	flag_info->minus = 0;
	flag_info->dot = 0;
	flag_info->hashtag = 0;
	flag_info->space = 0;
	flag_info->plus = 0;
	flag_info->zero = 0;
	flag_info->int_b = 0;
	flag_info->int_a = 0;
}
