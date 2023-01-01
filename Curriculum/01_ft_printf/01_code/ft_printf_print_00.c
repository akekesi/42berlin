/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_print_00.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akekesi <akekesi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 17:01:40 by akekesi           #+#    #+#             */
/*   Updated: 2023/01/01 04:04:18 by akekesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_char(int c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_print_str(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
		return (write(1, ft_get_null('s'), 6));
	while (str[i])
	{
		ft_print_char(str[i]);
		i++;
	}
	return (i);
}

int	ft_print_str_n(char *str, int n)
{
	int	i;

	i = 0;
	if (str == NULL)
	{
		if (5 < n)
			return (write(1, ft_get_null('s'), 6));
		return (write(1, ft_get_null('s'), 0));
	}
	while (str[i] && i < n)
	{
		ft_print_char(str[i]);
		i++;
	}
	return (i);
}
