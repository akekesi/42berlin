/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akekesi <akekesi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 21:04:21 by akekesi           #+#    #+#             */
/*   Updated: 2022/12/13 22:39:32 by akekesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strrchr(const char *str, int c)
{
	char	*str_;

	str_ = (char *)str;
	while (*str_)
		str_++;
	while (*str_ != c)
	{
		if (*str_ == str[0])
			return (NULL);
		str_--;
	}
	return (str_);
}
