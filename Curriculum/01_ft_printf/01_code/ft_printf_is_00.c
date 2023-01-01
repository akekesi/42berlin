/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_is_00.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akekesi <akekesi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 04:00:51 by akekesi           #+#    #+#             */
/*   Updated: 2023/01/01 04:00:53 by akekesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_is_flag(const char *str)
{
	int	i;

	i = 0;
	while (ft_char_in_str(str[i], ft_get_flags()))
	{
		i++;
		if (ft_char_in_str(str[i], ft_get_types()))
			return (i);
	}
	return (0);
}

int	ft_is_digit(int c)
{
	if ('0' <= c && c <= '9')
		return (1);
	return (0);
}
