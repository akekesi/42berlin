/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_is_00.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akekesi <akekesi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 19:12:55 by akekesi           #+#    #+#             */
/*   Updated: 2023/01/01 19:12:55 by akekesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_is_digit(int c)
{
	if ('0' <= c && c <= '9')
		return (1);
	return (0);
}

int	ft_is_first_int_zero(const char *str, int t)
{
	int	i;

	i = 0;
	while (str[i] && !ft_is_digit(str[i]) && i < t) // csak a . elottig kell figyelnni ???
		i++;
	if (ft_is_digit(str[i]) && str[i] == '0')
		return (1);
	return (0);
}
