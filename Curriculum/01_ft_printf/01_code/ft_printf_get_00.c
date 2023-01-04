/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_get_00.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akekesi <akekesi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 15:41:49 by akekesi           #+#    #+#             */
/*   Updated: 2023/01/03 22:13:59 by akekesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_get_types(void)
{
	return ("cspdiuxX%");
}

char	*ft_get_flags(void)
{
	return ("-0123456789.# +");
}

char	*ft_get_null(char type)
{
	if (type == 's')
		return ("(null)");
	if (type == 'p')
		return ("(nil)");
	return (NULL);
}
