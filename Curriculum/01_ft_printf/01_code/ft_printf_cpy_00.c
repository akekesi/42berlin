/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_cpy_00.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akekesi <akekesi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 16:58:05 by akekesi           #+#    #+#             */
/*   Updated: 2023/01/03 22:13:44 by akekesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_str_cpy(char *dest, const char *src)
{
	int		i;
	char	*src_;

	i = 0;
	src_ = (char *)src;
	while (src[i])
	{
		dest[i] = src_[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
