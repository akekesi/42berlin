/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akekesi <akekesi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 17:51:11 by akekesi           #+#    #+#             */
/*   Updated: 2023/01/17 21:26:12 by akekesi          ###   ########.fr       */
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
	if (str[i])
		i++;
	str_dup = (char *)malloc(sizeof(char) * (i + 1));
	if (!str_dup)
		return (NULL);
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
	if (str[i])
		i++;
	len = ft_str_len(str);
	str_dup = (char *)malloc(sizeof(char) * (len - i + 1));
	if (!str_dup)
		return (NULL);
	str_dup[len - i] = '\0';
	while (len - i)
	{
		len--;
		str_dup[len - i] = str[len];
	}
	if (str_dup[0] == '\0')
		ft_str_free(&str_dup);
	return (str_dup);
}

void	ft_str_free(char **str)
{
	if (*str)
	{
		free (*str);
		*str = NULL;
	}
}
