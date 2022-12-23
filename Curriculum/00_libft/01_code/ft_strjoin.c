/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akekesi <akekesi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 16:20:26 by akekesi           #+#    #+#             */
/*   Updated: 2022/12/23 17:17:13 by akekesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *str1, char const *str2)
{
	size_t	len_str1;
	size_t	len_str2;
	char	*str_join;

	if (!str1 || !str2)
		return (NULL);
	len_str1 = ft_strlen(str1);
	len_str2 = ft_strlen(str2);
	str_join = (char *)malloc(sizeof(char) * (len_str1 + len_str2 + 1));
	if (str_join)
	{
		str_join = (char *)ft_memcpy(str_join, str1, len_str1);
		str_join = (char *)ft_memcpy(str_join + len_str1, str2, len_str2 + 1);
		str_join = str_join - len_str1;
	}
	return (str_join);
}
