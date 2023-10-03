/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akekesi <akekesi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 16:20:26 by akekesi           #+#    #+#             */
/*   Updated: 2023/10/03 23:23:47 by akekesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_strjoin(char *str1, char *str2)
{
	int		i;
	int		len_str1;
	int		len_str2;
	char	*str_join;

	len_str1 = ft_strlen(str1);
	len_str2 = ft_strlen(str2);
	str_join = (char *)malloc(sizeof(char) * (len_str1 + len_str2 + 1));
	if (str_join)
	{
		i = 0;
		while (i < len_str1)
		{
			str_join[i] = str1[i];
			i++;
		}
		while (i < len_str1 + len_str2)
		{
			str_join[i] = str2[i - len_str1];
			i++;
		}
		str_join[i] = '\0';
	}
	return (str_join);
}
