/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akekesi <akekesi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 16:32:34 by akekesi           #+#    #+#             */
/*   Updated: 2023/01/19 15:07:54 by akekesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	ssize_t		n;
	char		*str_buff;
	static char	*str_line;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (ft_str_free(&str_line));
	str_buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!str_buff)
		return (ft_str_free(&str_line));
	n = read(fd, str_buff, BUFFER_SIZE);
	if (n < 0)
	{
		free (str_buff);
		return (ft_str_free(&str_line));
	}
	str_buff[n] = '\0';
	if (n == 0)
		return (ft_get_next_line_sub1(&str_buff, &str_line));
	return (ft_get_next_line_sub2(&str_buff, &str_line, fd));
}

char	*ft_get_next_line_sub1(char **str_buff, char **str_line)
{
	char		*str_rtrn;
	char		*str_temp;

	free (*str_buff);
	if (ft_str_len(*str_line))
	{
		if (ft_str_char(*str_line, '\n'))
		{
			str_temp = *str_line;
			str_rtrn = ft_str_dup_b(str_temp, '\n');
			*str_line = ft_str_dup_a(str_temp, '\n');
			free (str_temp);
			return (str_rtrn);
		}
		str_rtrn = ft_str_dup_b(*str_line, '\0');
		free (*str_line);
		*str_line = NULL;
		return (str_rtrn);
	}
	free (*str_line);
	*str_line = NULL;
	return (*str_line);
}

char	*ft_get_next_line_sub2(char **str_buff, char **str_line, int fd)
{
	char		*str_rtrn;
	char		*str_temp;

	str_temp = *str_line;
	*str_line = ft_str_cat(str_temp, *str_buff);
	free(str_temp);
	free(*str_buff);
	if (ft_str_char(*str_line, '\n'))
	{
		str_temp = *str_line;
		str_rtrn = ft_str_dup_b(str_temp, '\n');
		*str_line = ft_str_dup_a(str_temp, '\n');
		free (str_temp);
		return (str_rtrn);
	}
	return (get_next_line(fd));
}

char	*ft_str_cat(char *str1, char *str2)
{
	int		len_str1;
	int		len_str2;
	char	*str_cat;

	len_str1 = ft_str_len(str1);
	len_str2 = ft_str_len(str2);
	str_cat = (char *)malloc(sizeof(char) * (len_str1 + len_str2 + 1));
	if (!str_cat)
		return (NULL);
	if (str1)
		ft_str_cat_sub(str_cat, str1, 0);
	if (str2)
		ft_str_cat_sub(str_cat, str2, len_str1);
	str_cat[len_str1 + len_str2] = '\0';
	return (str_cat);
}

void	ft_str_cat_sub(char *dest, char *src, int start)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dest[start + i] = src[i];
		i++;
	}
}
