/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_check_00.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akekesi <akekesi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 15:56:22 by akekesi           #+#    #+#             */
/*   Updated: 2023/01/03 22:13:38 by akekesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_check_print(const char *str)
{
	int		i;
	char	*types;
	char	*flags;

	i = 0;
	types = ft_get_types();
	flags = ft_get_flags();
	if (str[i] == '%')
	{
		i++;
		while (str[i] && ft_char_in_str(str[i], flags))
			i++;
		if (ft_char_in_str(str[i], types))
			return (i);
	}
	return (0);
}
