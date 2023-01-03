/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_get_00.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akekesi <akekesi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 15:41:49 by akekesi           #+#    #+#             */
/*   Updated: 2023/01/01 15:41:49 by akekesi          ###   ########.fr       */
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

int	*ft_flags_in_str(const char *str, int t, int *flags)
{
	int	i;

	i = 0;
	flags[0] = str[t];
	while (i < t)
	{
		if (str[i] == '-')
			flags[1] = 1;
		if (str[i] == '.')
			flags[2] = 1;
		if (str[i] == '#')
			flags[3] = 1;
		if (str[i] == ' ')
			flags[4] = 1;
		if (str[i] == '+')
			flags[5] = 1;
		i++;
	}
	flags[6] = ft_is_first_int_zero(str, t);
	flags[7] = ft_int_in_str_dot_before(str, t);
	flags[8] = ft_int_in_str_dot_after(str, t);
	return (flags);
}

void	ft_set_zero(int *list, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		list[i] = 0;
		i++;
	}
}
