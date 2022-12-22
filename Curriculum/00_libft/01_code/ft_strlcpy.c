/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akekesi <akekesi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 11:54:12 by akekesi           #+#    #+#             */
/*   Updated: 2022/12/22 18:10:43 by akekesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t n)
{
	int	i;
	int	len_src;

	len_src = ft_strlen((char *)src);
	i = 0;
	if (len_src + 1 < n)
		ft_memcpy(dest, src, len_src + 1);
	else if (n)
	{
		ft_memcpy(dest, src, n - 1);
		dest[n - 1] = '\0';
	}
	return (len_src);
}
