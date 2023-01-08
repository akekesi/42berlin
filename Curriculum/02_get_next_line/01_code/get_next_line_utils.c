/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akekesi <akekesi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 17:51:11 by akekesi           #+#    #+#             */
/*   Updated: 2023/01/08 21:14:28 by akekesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_str_cat(char *str_line, char *str_buff)
{
	int		i;
	int		len_line;
	int		len_buff;
	char	*str_cat;

	len_line = ft_str_len(str_line);
	len_buff = ft_str_len(str_buff);
	str_cat = (char *)malloc(sizeof(char) * (len_line + len_buff + 1));
	if (!str_cat)
		return (NULL);
	if (str_line)
	{
		i = 0;
		while (str_line[i])
		{
			str_cat[i] = str_line[i];
			i++;
		}
	}
	i = 0;
	while (str_buff[i])
	{
		str_cat[len_line + i] = str_buff[i];
		i++;
	}
	str_cat[len_line + len_buff] = '\0';
	return (str_cat);
}

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

void	ft_str_cut(char *str, int c)
{
	int	i;

	if (!str)
		return ;
	i = 0;
	while (str[i])
	{
		if (str[i] == c)
		{
			str[i + 1] = '\0';
			return ;
		}
		i++;
	}
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
