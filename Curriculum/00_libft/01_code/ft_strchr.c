/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akekesi <akekesi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 21:04:21 by akekesi           #+#    #+#             */
/*   Updated: 2022/12/22 22:31:59 by akekesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	size_t	i;
	size_t	i_max;
	char	c_;
	char	*str_;

	c_ = (char)c;
	str_ = (char *)str;
	i = 0;
	i_max = ft_strlen(str) + 1;
	while (i < i_max)
	{
		if (str_[i] == c_)
			return (&str_[i]);
		i++;
	}
	return (NULL);
}
