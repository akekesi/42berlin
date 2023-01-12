/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akekesi <akekesi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 17:51:11 by akekesi           #+#    #+#             */
/*   Updated: 2023/01/12 18:02:25 by akekesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_str_len(char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_str_char(char *str, int c)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_str_dup_b(char *str, int c)
{
	int		i;
	char	*str_dup;

	if (!str)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != c)
		i++;
	i++;
	str_dup = (char *)malloc(sizeof(char) * (i + 1));
	str_dup[i] = '\0';
	while (i)
	{
		i--;
		str_dup[i] = str[i];
	}
	return (str_dup);
}

char	*ft_str_dup_a(char *str, int c)
{
	int		i;
	int		len;
	char	*str_dup;

	if (!str)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != c)
		i++;
	i++;
	len = ft_str_len(str);
	str_dup = (char *)malloc(sizeof(char) * (len - i + 1));
	str_dup[len - i] = '\0';
	while (len - i)
	{
		len--;
		str_dup[len - i] = str[len];
	}
	return (str_dup);
}

char	*ft_str_cat(char *str1, char *str2)
{
	int		i;
	int		len_str1;
	int		len_str2;
	char	*str_cat;

	len_str1 = ft_str_len(str1);
	len_str2 = ft_str_len(str2);
	str_cat = (char *)malloc(sizeof(char) * (len_str1 + len_str2 + 1));
	if (!str_cat)
		return (NULL);
	if (str1)
	{
		i = 0;
		while (str1[i])
		{
			str_cat[i] = str1[i];
			i++;
		}
	}
	if (str2)
	{
		i = 0;
		while (str2[i])
		{
			str_cat[len_str1 + i] = str2[i];
			i++;
		}
	}
	str_cat[len_str1 + len_str2] = '\0';
	return (str_cat);
}
