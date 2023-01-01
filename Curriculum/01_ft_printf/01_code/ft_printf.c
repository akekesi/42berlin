/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akekesi <akekesi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 15:12:53 by akekesi           #+#    #+#             */
/*   Updated: 2023/01/01 15:12:53 by akekesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "test.h"

int	ft_printf(const char *str, ...)
{
	int		i;
	int		n;
	va_list	args;

	if (!str)
		return (0);
	va_start(args, str);
	i = 0;
	n = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	printf(" -->%d<--", va_arg(args, int));
	printf(" -->%d<--", va_arg(args, int));
	va_end(args);
	return (n);
}
