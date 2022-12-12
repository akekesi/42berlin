/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akekesi <akekesi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 11:32:39 by akekesi           #+#    #+#             */
/*   Updated: 2022/12/12 11:32:39 by akekesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*src_;
	char	*dest_;

	i = 0;
	src_ = (char *)src;
	dest_ = (char *)dest;
	while (i < n)
	{
		dest_[i] = src_[i];
		i++;
	}
	return (dest);
}
