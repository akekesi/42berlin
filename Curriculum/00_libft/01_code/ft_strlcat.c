/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akekesi <akekesi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 11:54:12 by akekesi           #+#    #+#             */
/*   Updated: 2022/12/18 20:42:25 by akekesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dest, const char *src, size_t n);
static int	hf_strlen(char *str);

size_t	ft_strlcat(char *dest, const char *src, size_t n)
{
	int	i;
	int	len_dest;
	int	len_src;

	len_dest = hf_strlen(dest);
	len_src = hf_strlen((char *)src);
	if (n <= len_dest)
		return (len_src + n);
	i = 0;
	while ((i < ((int)n - 1)) && src[i])
	{
		dest[len_dest + i] = src[i];
		i++;
	}
	dest[len_dest + i] = '\0';
	return (len_dest + i);
}

static int	hf_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
