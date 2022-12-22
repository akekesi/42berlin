/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akekesi <akekesi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 21:04:21 by akekesi           #+#    #+#             */
/*   Updated: 2022/12/22 22:17:28 by akekesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	size_t	i;
	char	c_;
	char	*str_;

	c_ = (char)c;
	str_ = (char *)str;
	i = ft_strlen(str) + 1;
	while (i--)
	{
		if (str_[i] == c_)
			return (&str_[i]);
	}
	return (NULL);
}
