/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akekesi <akekesi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 16:32:34 by akekesi           #+#    #+#             */
/*   Updated: 2023/01/08 22:27:35 by akekesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "test.h"

/*
read(\n) = 0 ???
*/

char	*get_next_line(int fd)
{
	ssize_t		n;
	char		*str_rtrn;
	char		*str_buff;
	char		*str_temp;
	static char	*str_line;

	int			debug;
	debug = 0;

	if (fd == -1 || BUFFER_SIZE < 1)
		return (NULL);
	str_buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!str_buff)
		return (NULL);
	n = read(fd, str_buff, BUFFER_SIZE);
	str_buff[n] = '\0';
	if (debug)
		printf("(%d-%s): ", (int)n, str_buff);
	if (n == -1)
	{	// n = -1 --> error
		if (debug)
			printf("n = -1*");
		free (str_buff);
		return (NULL);
	}
	else if (n == 0)
	{	// n = 0  --> nothing was read
		if (debug)
			printf("n = 0 and ");
		free (str_buff);
		if (ft_str_len(str_line))
		{	// str_line not empty
			if (ft_str_char(str_line, '\n'))
			{	// \n in str_line
				/*
				-copy text until \n or \0 from str_line in str_rtrn and return(str_rtrn)
				-save rest in str_line
				-use str_temp to free old str_line
				*/
				if (debug)
					printf("with \\n*");
				str_temp = str_line;
				str_rtrn = ft_str_dup_b(str_temp, '\n');
				str_line = ft_str_dup_a(str_temp, '\n');
				free (str_temp);
				return (str_rtrn);
			}
			else
			{	// \n not in str_line
				/*
				-copy text until \0 from str_line in str_rtrn and return(str_rtrn)
				-free str_line and null
				*/
				if (debug)
					printf("without \\n*");
				str_rtrn = ft_str_dup_b(str_line, '\0');
				free (str_line);
				str_line = NULL;
				return (str_rtrn);
			}
		}
		else
		{	// str_line empty
			if (debug)
				printf("empty*");
			free (str_line);
			str_line = NULL;
			return (str_line);
		}
	}
	else
	{	// n > 0  --> something was read
		/*
		-not end of the text
		-concatenate str_line and str_buff
		-free str_buff
		-use str_temp to free old str_line
		*/
		if (debug)
			printf("n > 0 and ");
		str_temp = str_line;
		str_line = ft_str_cat(str_temp, str_buff);
		free(str_temp);
		free(str_buff);
		if (ft_str_char(str_line, '\n'))
		{	// \n in str_line
			/*
			-copy text until \n or \0 from str_line in str_rtrn and return(str_rtrn)
			-save rest in str_line
			-use str_temp to free old str_line
			*/
			if (debug)
				printf("with \\n*");
			str_temp = str_line;
			str_rtrn = ft_str_dup_b(str_temp, '\n');
			str_line = ft_str_dup_a(str_temp, '\n');
			free (str_temp);
			return (str_rtrn);
		}
		else
		{	// \n not in str_line
			/*
			-call get_next_line() again (recursive)
			*/
			if (debug)
				printf("without \\n*");
			return (get_next_line(fd));
		}
	}
}
