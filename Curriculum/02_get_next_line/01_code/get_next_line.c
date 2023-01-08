/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akekesi <akekesi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 16:32:34 by akekesi           #+#    #+#             */
/*   Updated: 2023/01/08 21:14:34 by akekesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	ssize_t		n;
	char		*str_tmp;
	char		*str_buff;
	static char	*str_line;

	if (ft_str_char(str_line, '\n'))
	{
		free(str_line);
		str_line = NULL;
	}
	str_buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (fd == -1 || !str_buff)
		return (NULL);
	n = read(fd, str_buff, BUFFER_SIZE);
	if (n < 1)
	/*
		n = -1 --> error
		n = 0  --> nothing was read
	*/
	{
		free (str_buff);
		return (str_line);
	}
	else
	{
		str_buff[n] = '\0';
		str_tmp = str_line;
		ft_str_cut(str_buff, '\n');
		str_line = ft_str_cat(str_tmp, str_buff);
		free (str_buff);
		free (str_tmp);
	}
	return (str_line);
}
