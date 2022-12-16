/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akekesi <akekesi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 15:16:34 by akekesi           #+#    #+#             */
/*   Updated: 2022/12/16 15:16:34 by akekesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_strncmp(const char *str1, const char *str2, size_t n);
static int	hf_ft_chrcmp(int c1, int c2);

int	ft_strncmp(const char *str1, const char *str2, size_t n)
{
	size_t	i;

	i = 0;
	while ((str1[i] || str2[i]) && i < n)
	{
		if (str1[i] != str2[i])
			return (hf_ft_chrcmp(((unsigned char *)str1)[i], ((unsigned char *)str2)[i]));
			// return (((unsigned char *)str1)[i] - ((unsigned char *)str2)[i]);
		i++;
	}
	return (0);
}

static int	hf_ft_chrcmp(int c1, int c2)
{
	if (c1 > c2)
		return (1);
	if (c1 < c2)
		return (-1);
	return (0);
}
