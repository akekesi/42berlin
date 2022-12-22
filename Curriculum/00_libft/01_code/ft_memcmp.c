/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akekesi <akekesi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 13:26:15 by akekesi           #+#    #+#             */
/*   Updated: 2022/12/22 21:01:57 by akekesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *str1, const void *str2, size_t n)
{
	size_t			i;
	unsigned char	*str1_;
	unsigned char	*str2_;

	str1_ = (unsigned char *)str1;
	str2_ = (unsigned char *)str2;
	i = 0;
	while (i < n)
	{
		if (str1_[i] != str2_[i])
			return (str1_[i] - str2_[i]);
		i++;
	}
	return (0);
}
