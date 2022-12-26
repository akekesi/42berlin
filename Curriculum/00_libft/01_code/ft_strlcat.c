/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akekesi <akekesi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 11:54:12 by akekesi           #+#    #+#             */
/*   Updated: 2022/12/26 17:31:29 by akekesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t n)
{
	size_t	i_dest;
	size_t	i_src;
	size_t	len_src;

	i_dest = 0;
	len_src = ft_strlen(src);
	while (i_dest < n && dest[i_dest])
		i_dest++;
	i_src = 0;
	while (src[i_src] && (i_dest + i_src + 1) < n)
	{
		dest[i_dest + i_src] = src[i_src];
		i_src++;
	}
	if (i_dest < n)
		dest[i_dest + i_src] = '\0';
	return (i_dest + len_src);
}
