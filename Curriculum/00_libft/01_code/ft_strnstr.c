/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akekesi <akekesi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 14:56:52 by akekesi           #+#    #+#             */
/*   Updated: 2022/12/22 23:20:41 by akekesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "test.h"

char		*ft_strnstr(const char *str1, const char *str2, size_t n);
static int	hf_check_ft_strnstr(char *str1, char *str2, size_t n);

char	*ft_strnstr(const char *str1, const char *str2, size_t n)
{
	char	*str1_;
	char	*str2_;

	str1_ = (char *)str1;
	str2_ = (char *)str2;
	if (*str2_ == '\0' || str2_ == NULL)
		return (str1_);
	while (*str1_ && n)
	{
		if (hf_check_ft_strnstr(str1_, str2_, n))
			return (str1_);
		str1_++;
		n--;
	}
	return (NULL);
}

static int	hf_check_ft_strnstr(char *str1, char *str2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && str1[i] && str2[i])
	{
		if (str1[i] != str2[i])
			return (0);
		i++;
	}
	if (str2[i])
		return (0);
	return (1);
}
