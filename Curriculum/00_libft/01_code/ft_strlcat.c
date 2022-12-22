/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akekesi <akekesi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 11:54:12 by akekesi           #+#    #+#             */
/*   Updated: 2022/12/22 20:23:11 by akekesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t n)
{
	size_t	i_destn;
	size_t	i_src;
	size_t	len_src;

	i_destn = 0;
	len_src = ft_strlen(src);
	while (i_destn < n && dest[i_destn])
		i_destn++;
	i_src = 0;
	while (src[i_src] && (i_destn + i_src + 1) < n)
	{
		dest[i_destn + i_src] = src[i_src];
		i_src++;
	}
	if (i_destn < n)
		dest[i_destn + i_src] = '\0';
	return (i_destn + len_src);
}
