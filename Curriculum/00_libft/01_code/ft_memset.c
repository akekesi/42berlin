/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akekesi <akekesi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 22:11:04 by akekesi           #+#    #+#             */
/*   Updated: 2022/12/11 22:11:04 by akekesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int c, size_t n)
{
	size_t			i;
	unsigned char	*str_;

	i = 0;
	str_ = (unsigned char *)str;
	while (i < n)
	{
		str_[i] = (unsigned char)c;
		i++;
	}
	return (str);
}
