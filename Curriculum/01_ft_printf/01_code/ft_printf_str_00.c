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

int	ft_str_cmp(const char *str1, const char *str2)
{
	int	i;

	i = 0;
	while (str1[i] || str2[i])
	{
		if (str1[i] != str2[i])
			return (((unsigned char *)str1)[i] - ((unsigned char *)str2)[i]);
		i++;
	}
	return (0);
}
