/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_get_00.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akekesi <akekesi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 04:02:39 by akekesi           #+#    #+#             */
/*   Updated: 2023/01/01 04:03:08 by akekesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_get_null(int c)
{
	if (c == 's')
		return ("(null)");
	if (c == 'p')
		return ("(nil)");
	return (NULL);
}

char	*ft_get_flags(void)
{
	return ("-0123456789.# +");
}

char	*ft_get_types(void)
{
	return ("cspdiuxX%");
}
