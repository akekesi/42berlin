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
#include "test.h"

int			ft_strncmp(const char *str1, const char *str2, size_t n);
static int	hf_ft_chrcmp(int c1, int c2);

int	ft_strncmp(const char *str1, const char *str2, size_t n)
{
	char	*str1_;
	char	*str2_;
	int		result;

	if (!n)
		return (0);
	str1_ = (char *)str1;
	str2_ = (char *)str2;
	while (*str1_ && *str2_ && n != 1)
	{
		result = hf_ft_chrcmp(*str1_, *str2_);
		if (result)
			return (result);
		str1_++;
		str2_++;
		n--;
	}
	return (hf_ft_chrcmp(*str1_, *str2_));
}

static int	hf_ft_chrcmp(int c1, int c2)
{
	if (c1 > c2)
		return (1);
	if (c1 < c2)
		return (-1);
	return (0);
}
