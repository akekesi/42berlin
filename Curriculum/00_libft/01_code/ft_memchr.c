/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akekesi <akekesi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 13:06:53 by akekesi           #+#    #+#             */
/*   Updated: 2022/12/22 15:34:38 by akekesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	unsigned char	c_;
	unsigned char	*str_;

	c_ = (unsigned char)c;
	str_ = (unsigned char *)str;
	while (n)
	{
		if (*str_ == c_)
			return (str_);
		str_++;
		n--;
	}
	return (NULL);
}
