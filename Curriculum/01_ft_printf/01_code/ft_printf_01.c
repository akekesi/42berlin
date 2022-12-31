/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_01.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akekesi <akekesi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 17:01:40 by akekesi           #+#    #+#             */
/*   Updated: 2022/12/31 17:11:20 by akekesi          ###   ########.fr       */
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
