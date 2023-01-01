/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_to_00.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akekesi <akekesi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 20:51:37 by akekesi           #+#    #+#             */
/*   Updated: 2023/01/01 20:51:37 by akekesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_char_to_str(int c)
{
	char	*arg;

	arg = (char *)malloc(sizeof(char) * 2);
	if (!arg)
		return (NULL);
	arg[0] = c;
	arg[1] = '\0';
	return (arg);
}
