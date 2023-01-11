/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akekesi <akekesi@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 15:17:59 by akekesi           #+#    #+#             */
/*   Updated: 2023/01/08 22:28:05 by akekesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "test.h"

int	main(void)
{
	printf("|-- TEST -->\n");
	printf("|-- get_next_line -->\n");
	int		i;
	int		i_max;
	int		fd;
	char	*str;
	char	*path;

	// path = "99_text/fd_negative";
	path = "99_text/test_gnl_00.txt";
	// path = "99_text/test_gnl_01.txt";
	// path = "99_text/nl";
	// path = "99_text/empty";
	// path = "99_text/empty.txt";
	// path = "99_text/read_error.txt";
	fd = open(path, O_RDONLY);
	if (fd == -1)
		printf("fd = -1\n");
	i = 0;
	i_max = 7;
	while (i < i_max)
	{
		str = get_next_line(fd);
		printf("%d. -->%s<--\n", i, str);
		free(str);
		i++;
	}
	printf("<-- get_next_line --|\n");
	printf("<-- TEST --|\n");
	return (1);
}
