/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_str_00.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akekesi <akekesi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 16:58:05 by akekesi           #+#    #+#             */
/*   Updated: 2023/01/07 15:51:05 by akekesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_str_len(const char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_str_cpy(char *dest, const char *src)
{
	int		i;
	char	*src_;

	src_ = (char *)src;
	if (!dest || !src)
		return (NULL);
	i = 0;
	while (src[i])
	{
		dest[i] = src_[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

int	ft_str_cmp(const char *str1, const char *str2)
{
	int	i;

	if (!str1 && !str2)
		return (0);
	if (!str1 || !str2)
		return (1);
	i = 0;
	while (str1[i] || str2[i])
	{
		if (str1[i] != str2[i])
			return (((unsigned char *)str1)[i] - ((unsigned char *)str2)[i]);
		i++;
	}
	return (0);
}

void	ft_str_to_upper(char *str)
{
	int	i;

	if (!str)
		return ;
	i = 0;
	while (str[i])
	{
		if ('a' <= str[i] && str[i] <= 'z')
			str[i] = str[i] - 'a' + 'A';
		i++;
	}
}
