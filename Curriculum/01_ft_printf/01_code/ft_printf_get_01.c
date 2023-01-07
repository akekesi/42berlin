/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_get_01.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akekesi <akekesi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 15:41:49 by akekesi           #+#    #+#             */
/*   Updated: 2023/01/07 15:40:31 by akekesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_get_prefix_main(int n, int prefix, int type, int pprefix)
{
	if (prefix && n)
	{
		if (type == 'x')
			return ("0x");
		if (type == 'X')
			return ("0X");
		if (type == 'p' && pprefix == '+')
			return ("+0x");
		if (type == 'p' && pprefix == ' ')
			return (" 0x");
		if (type == 'p' && pprefix == 0)
			return ("0x");
	}
	return ("\0");
}

char	*ft_get_prefix_ptr(char *arg, int *flag_info)
{
	if (!ft_str_cmp(arg, ft_get_null('p')))
		return ("\0");
	else if (flag_info[5])
		return (ft_get_prefix_main(arg[0] - '0', 1, 'p', '+'));
	else if (flag_info[4])
		return (ft_get_prefix_main(arg[0] - '0', 1, 'p', ' '));
	else
		return (ft_get_prefix_main(arg[0] - '0', 1, 'p', 0));
}

char	*ft_get_prefix_int(char *arg, int *flag_info)
{
	if (arg[0] != '-')
	{
		if (flag_info[5])
			return ("+");
		else if (flag_info[4])
			return (" ");
		else
			return ("\0");
	}
	else
		return ("-");
}
