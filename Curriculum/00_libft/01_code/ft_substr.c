/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akekesi <akekesi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 09:20:37 by akekesi           #+#    #+#             */
/*   Updated: 2022/12/26 17:32:58 by akekesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_substr(char const *str, unsigned int start, size_t len);
static size_t	hf_calc_len(char const *str, unsigned int start, size_t len);

char	*ft_substr(char const *str, unsigned int start, size_t len)
{
	size_t	i;
	char	*str_sub;

	if (!str)
		return (NULL);
	len = hf_calc_len(str, start, len);
	str_sub = (char *)malloc(sizeof(char) * (len + 1));
	if (str_sub)
	{
		i = 0;
		while (i < len)
		{
			str_sub[i] = str[start + i];
			i++;
		}
		str_sub[i] = '\0';
	}
	return (str_sub);
}

static size_t	hf_calc_len(char const *str, unsigned int start, size_t len)
{
	size_t	len_str;

	len_str = ft_strlen(str);
	if (len_str < start)
		return (0);
	if (len_str < start + len)
		return (len_str - start);
	return (len);
}
