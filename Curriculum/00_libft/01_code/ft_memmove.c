/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akekesi <akekesi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 11:32:39 by akekesi           #+#    #+#             */
/*   Updated: 2022/12/17 19:59:09 by akekesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*src_;
	char	*dest_;

	src_ = (char *)src;
	dest_ = (char *)dest;
	if (src_ < dest_)
	{
		while (n)
		{
			n--;
			dest_[n] = src_[n];
		}
	}
	if (src_ > dest_)
	{
		i = 0;
		while (i < n)
		{
			dest_[i] = src_[i];
			i++;
		}
	}
	return (dest_);
}
