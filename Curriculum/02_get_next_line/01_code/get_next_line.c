/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akekesi <akekesi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 16:32:34 by akekesi           #+#    #+#             */
/*   Updated: 2023/01/13 00:31:45 by akekesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	ssize_t		n;
	char		*str_rtrn;
	char		*str_buff;
	char		*str_temp;
	static char	*str_line;

	if (fd < 0 || BUFFER_SIZE < 1)
	{
		if (str_line)
		{
			free (str_line);
			str_line = NULL;
		}
		return (NULL);
	}
	str_buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!str_buff)
		return (NULL);
	n = read(fd, str_buff, BUFFER_SIZE);
	if (n < 0)
	{
		free (str_buff);
		if (str_line)
		{
			free (str_line);
			str_line = NULL;
		}
		return (NULL);
	}
	str_buff[n] = '\0';
	if (n == -1)
	{
		free (str_buff);
		return (NULL);
	}
	else if (n == 0)
	{
		free (str_buff);
		if (ft_str_len(str_line))
		{
			if (ft_str_char(str_line, '\n'))
			{
				str_temp = str_line;
				str_rtrn = ft_str_dup_b(str_temp, '\n');
				str_line = ft_str_dup_a(str_temp, '\n');
				free (str_temp);
				return (str_rtrn);
			}
			else
			{
				str_rtrn = ft_str_dup_b(str_line, '\0');
				free (str_line);
				str_line = NULL;
				return (str_rtrn);
			}
		}
		else
		{
			free (str_line);
			str_line = NULL;
			return (str_line);
		}
	}
	else
	{
		str_temp = str_line;
		str_line = ft_str_cat(str_temp, str_buff);
		free(str_temp);
		free(str_buff);
		if (ft_str_char(str_line, '\n'))
		{
			str_temp = str_line;
			str_rtrn = ft_str_dup_b(str_temp, '\n');
			str_line = ft_str_dup_a(str_temp, '\n');
			free (str_temp);
			return (str_rtrn);
		}
		else
			return (get_next_line(fd));
	}
}
