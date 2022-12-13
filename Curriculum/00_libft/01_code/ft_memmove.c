/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akekesi <akekesi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 11:32:39 by akekesi           #+#    #+#             */
/*   Updated: 2022/12/13 19:49:23 by akekesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*src_;
	char	*dest_;
	char	*tmp;

	src_ = (char *)src;
	dest_ = (char *)dest;
	tmp = (char *)malloc(n);
	i = 0;
	while (i < n)
	{
		tmp[i] = src_[i];
		i++;
	}
	i = 0;
	while (i < n)
	{
		dest_[i] = tmp[i];
		i++;
	}
	return (dest);
}
